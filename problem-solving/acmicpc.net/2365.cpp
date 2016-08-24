// acmicpc.net/problem/2365
// category: max flow, binary search

#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

class MaxFlowEdge {
  public:
    static pair<MaxFlowEdge*, MaxFlowEdge*> create_edge_and_dual(int u, int v, int capacity) {
        MaxFlowEdge* uv = new MaxFlowEdge;
        MaxFlowEdge* vu = new MaxFlowEdge;
        
        uv->_u = u;
        uv->_v = v;
        uv->_capacity = capacity;
        uv->_flow = 0;
        uv->_dual = vu;

        vu->_u = v;
        vu->_v = u;
        vu->_capacity = 0;
        vu->_flow = 0;
        vu->_dual = uv;

        return make_pair(uv, vu);
    }

    int u() { return _u; }
    int v() { return _v; }
    int capacity() { return _capacity; }
    int flow() { return _flow; }
    int residual() { return _capacity - _flow; }
    MaxFlowEdge* dual() { return _dual; }

    void augment(int amount) {
        _flow += amount;
        _dual->_flow -= amount;
    }

  private:
    int _u;
    int _v;
    int _capacity;
    int _flow;
    MaxFlowEdge* _dual;
};

class MaxFlowNetwork {
  public:
    MaxFlowNetwork(int n) : _g(n) {}
    
    ~MaxFlowNetwork() {
        for (auto edge_list : _g) {
            for (auto edge : edge_list) {
                delete edge;
            }
        }
    }

    vector<vector<MaxFlowEdge*>> graph() { return _g; }

    void add_edge(int u, int v, int capacity) {
        auto edges = MaxFlowEdge::create_edge_and_dual(u, v, capacity);
        auto uv = edges.first;
        auto vu = edges.second;
        _g[uv->u()].push_back(uv);
        _g[vu->u()].push_back(vu);
    }

    int maximum_flow(int s, int t) {
        int res = 0;
        int augment_volume = 0;
        while ((augment_volume = try_augment(s, t)) > 0) {
            res += augment_volume;
        }
        return res;
    }

  private:
    vector<MaxFlowEdge*> find_augment_path(int s, int t) {
        vector<MaxFlowEdge*> path;
        vector<MaxFlowEdge*> from(_g.size());
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto e : _g[u]) {
                if (e->residual() > 0 && from[e->v()] == NULL) {
                    q.push(e->v());
                    from[e->v()] = e;
                }
            }
        }
        build_augment_path(path, from, s, t);
        return path;
    }

    int try_augment(int s, int t) {
        auto path = find_augment_path(s, t);
        auto volume = path_volume(path);
        for (auto e : path) e->augment(volume);
        return volume;
    }

    int path_volume(vector<MaxFlowEdge*>& path) {
        if (path.size() == 0) return 0;
        int volume = INT_MAX;
        for (auto e : path) volume = min(volume, e->residual());
        return volume;
    }
    
    void build_augment_path(vector<MaxFlowEdge*>& path, vector<MaxFlowEdge*>& from, int s, int v) {
        if (v != s && from[v] != NULL) {
            build_augment_path(path, from, s, from[v]->u());
            path.push_back(from[v]);
        }
    }

  private:
    vector<vector<MaxFlowEdge*>> _g;
};

int N;
int RowSum[51];
int ColSum[51];
int A[51][51];

bool solve(int weight) {
    MaxFlowNetwork network(2 * N + 2);
    int start = 2 * N;
    int sink = 2 * N + 1;

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += RowSum[i];
        network.add_edge(start, i, RowSum[i]);
        network.add_edge(N + i, sink, ColSum[i]);
        for (int j = 0; j < N; ++j) {
            network.add_edge(i, N + j, weight);
        }
    }
    if (network.maximum_flow(start, sink) == sum) {
        auto graph = network.graph();
        for (int i = 0; i < N; ++i) {
            for (auto edge : graph[i]) {
                A[i][edge->v() - N] = edge->flow();
            }
        }
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &RowSum[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &ColSum[i]);

    int low_bound = 0;
    int upper_bound = 10000;
    int answer = 10000;
    while (low_bound <= upper_bound) {
        int mid = (low_bound + upper_bound) / 2;
        if (solve(mid)) {
            answer = mid;
            upper_bound = mid - 1;
        } else {
            low_bound = mid + 1;
        }
    }
    printf("%d\n", answer);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
