// acmicpc.net/problem/3640
// category : mcmf, maxflow, minunum cost maximum flow, spfa, dijkstra
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define INF INT_MAX

struct Edge {
    int u;
    int v;
    int cap;
    int cost;
    int flow;
    int cost_org;
    Edge* dual;
    
    Edge(int u, int v, int cap, int cost) 
      : u(u), v(v), cap(cap), cost(cost), flow(0), cost_org(cost), dual(NULL) {
    }

    int residual() { return cap - flow; }
    
    void augment(int amount) {
        flow += amount;
        dual->flow -= amount;
    }

    static pair<Edge*, Edge*> createEdgeAndDual(int u, int v, int cap, int cost) {
        Edge* uv = new Edge(u, v, cap, cost);
        Edge* vu = new Edge(v, u, 0, -cost);
        
        uv->dual = vu;
        vu->dual = uv;

        return make_pair(uv, vu);
    }
};

typedef vector<vector<Edge*>> Graph;

class MCMF {
  public:
    MCMF(int size, int source, int sink) 
      : _size(size), _source(source), _sink(sink), _g(size), _flow(0) {
    }

    ~MCMF() {
        for (auto edges : _g) {
            for (auto edge : edges) {
                delete edge;
            }
        }
    }

    Graph graph() { return _g; }

    int flow() { return _flow; }

    int cost() {
        int cost = 0;
        for (auto edges : _g) {
            for (auto e : edges) {
                if (e->cap > 0) {
                    cost += e->cost_org * e->flow;
                }
            }
        }
        return cost;
    }

    void addEdge(int u, int v, int cap, int cost) {
        auto edges = Edge::createEdgeAndDual(u, v, cap, cost);
        auto uv = edges.first;
        auto vu = edges.second;
        _g[uv->u].push_back(uv);
        _g[uv->v].push_back(vu);
    }

    pair<int, int> solve() {
        initializeCosts();
        
        while (tryAugment() > 0);
        
        return make_pair(flow(), cost());
    }

    int tryAugment() {
        auto path = findAugmentPath();
        auto volume = pathVolume(path);
        for (auto e: path) {
            e->augment(volume);
        }
        _flow += volume;
        return volume; 
    }

    void reduceCosts(const vector<int>& dist) {
        for (int u = 0; u < _size; ++u) {
            if (dist[u] < INF) {
                for (auto e : _g[u]) {
                    if (e->cap > 0) {
                        e->cost += dist[u] - dist[e->v];
                    } else {
                        e->cost = 0;
                    }
                }
            }
        }
    }


    void initializeCosts() {
        reduceCosts(SPFA());
    }
    
    vector<int> SPFA() {
        vector<int> dist(_size, INF);
        vector<bool> in_queue(_size);
        queue<int> q;
        q.push(_source);
        in_queue[_source] = true;
        dist[_source] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for (auto e : _g[u]) {
                if (e->residual() > 0 && dist[e->v] > dist[u] + e->cost) {
                    dist[e->v] = dist[u] + e->cost;
                    if (!in_queue[e->v]) {
                        q.push(e->v);
                        in_queue[e->v] = true;
                    }
                }
            }
        }
        return dist;
    }

    vector<Edge*> findAugmentPath() {
        vector<Edge*> from(_size);
        vector<bool> visit(_size, false);
        vector<int> dist(_size, INF);
       
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, _source));
        dist[_source] = 0; 

        while (!pq.empty()) {
            int d = -pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (visit[u]) continue;
            visit[u] = true;
            
            for (auto e : _g[u]) {
                if (!visit[e->v] && e->residual() > 0) {
                    if (from[e->v] == NULL || dist[e->v] > d + e->cost) {
                        from[e->v] = e;
                        dist[e->v] = d + e->cost;
                        pq.push(make_pair(-dist[e->v], e->v));
                    }
                }
            }
        }

        vector<Edge*> path;
        if (from[_sink] != NULL) {
            buildPath(path, from, _source, _sink);
            reduceCosts(dist);
        }
        
        return path;
    }

    void buildPath(vector<Edge*>& path, const vector<Edge*>& from, int s, int v) {
        if (v != s) {
            buildPath(path, from, s, from[v]->u);
            path.push_back(from[v]);
        }
    }

    int pathVolume(const vector<Edge*>& path) {
        if (path.size() == 0) return 0;
        int volume = INF;
        for (auto e : path) {
            volume = min(volume, e->residual());
        }
        return volume;
    }

  private:
    int _size;
    int _source;
    int _sink;
    int _flow;
    Graph _g;
};

int main() {
    int V, E;
    while (scanf("%d%d", &V, &E) > 0) {
        int source = V + 1;
        int sink = V;
        MCMF mcmf(2 * V + 2, source, sink);
        for (int u = 1; u <= V; ++u) {
            mcmf.addEdge(u, V + u, 1, 0);
        }
        for (int ei = 0; ei < E; ++ei) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            mcmf.addEdge(V + u, v, 1, w);
        }

        mcmf.initializeCosts();
        mcmf.tryAugment();
        mcmf.tryAugment();
        printf("%d\n", mcmf.cost());
    }
    return 0;
}
