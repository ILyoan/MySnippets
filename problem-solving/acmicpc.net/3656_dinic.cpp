// acmicpc.net/problem/3656
// category : max flow, dinic

#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

#define INF INT_MAX

struct Edge {
    int u;
    int v;
    int cap;
    int flow;

    Edge(int u, int v, int cap) : u(u), v(v), cap(cap), flow(0) {}

    int residual() { return cap - flow; }
};

class MaxFlowDinic {
  public:
    MaxFlowDinic(int n, int source, int sink)
        : _n(n), _source(source), _sink(sink), _g(n), _dist(n), _push_tried(n) {
    }

    void addEdge(int u, int v, int cap1, int cap2 = 0) {
        _e.push_back(Edge(u, v, cap1));
        _g[u].push_back(_e.size() - 1);
        _e.push_back(Edge(v, u, cap2));
        _g[v].push_back(_e.size() - 1);
    }

    int maximumFlow() {
        int total_flow = 0;
        while (findAugmentPath()) {
            total_flow += pushFlow();
        }
        return total_flow;
    }

    bool findAugmentPath() {
        for (int u = 0; u < _n; ++u) {
            _dist[u] = -1;
        }
        queue<int> q;
        q.push(_source);
        _dist[_source] = 0;
        while (!q.empty() && _dist[_sink] == -1) {
            int u = q.front();
            q.pop();
            for (auto ei : _g[u]) {
                Edge& e = _e[ei];
                if (e.residual() > 0 && _dist[e.v] == -1) {
                    q.push(e.v);
                    _dist[e.v] = _dist[u] + 1;
                }
            }
        }
        return _dist[_sink] != -1;
    }

    int pushFlow() {
        int total_pushed = 0;
        int amount = 0;
        for (int u = 0; u < _n; ++u) {
            _push_tried[u] = 0;
        }
        while ((amount = pushFlow(_source, _sink, INF)) > 0) {
            total_pushed += amount;
        }
        return total_pushed;
    }

    int pushFlow(int u, int t, int amount) {
        if (amount == 0 || u == t) {
            return amount;
        }
        for (int& ei = _push_tried[u]; ei < _g[u].size(); ++ei) {
            Edge& e = _e[_g[u][ei]];
            Edge& e_dual = _e[_g[u][ei] ^ 1];
            if (e.residual() > 0 && _dist[u] + 1 == _dist[e.v]) {
                int flow = pushFlow(e.v, t, min(e.residual(), amount));
                if (flow > 0) {
                    e.flow += flow;
                    e_dual.flow -= flow;
                    return flow;
                }
            } 
        }
        return 0;
    }
  

  private:
    int _n;
    int _source;
    int _sink;
    vector<vector<int>> _g;
    vector<Edge> _e;
    vector<int> _dist;
    vector<int> _push_tried;
};


char M[51][51];

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int Y, X, D, F, B;
        scanf("%d%d%d%d%d", &X, &Y, &D, &F, &B);
        for (int i = 0; i < Y; ++i) {
            scanf("%s", M[i]);
        }
        int cost = 0;
        int source = Y * X;
        int sink = Y * X + 1;
        MaxFlowDinic maxFlow(Y * X + 2, source, sink);
        
        for (int y = 0; y < Y; ++y) {
            for (int x = 0; x < X; ++x) {
                if (y + 1 < Y) {
                    int ny = y + 1;
                    maxFlow.addEdge(y * X + x, ny * X + x, B, B);
                }
                if (x + 1 < X) {
                    int nx = x + 1;
                    maxFlow.addEdge(y * X + x, y * X + nx, B, B);
                }
                if (y == 0 || y == Y - 1 || x == 0 || x == X - 1) {
                    if (M[y][x] == '.') {
                        cost += F;
                    }
                    maxFlow.addEdge(source, y * X + x, INF);
                }
                else if (M[y][x] == '#') {
                    maxFlow.addEdge(source, y * X + x, D);
                } else {
                    maxFlow.addEdge(y * X + x, sink, F);
                }
            }
        }

        printf("%d\n", cost + maxFlow.maximumFlow());
    } 
    return 0;
}
