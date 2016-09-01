// acmicpc.net/problem/3666
// category : maximum flow, maxflow, dinic, binary search

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

int N;
int F[101];
char G[101][101];
int AC;
int AI[101];
int IA[101];
int AF[101];
int AL[101][101];
int ALC[101];
int BC;
bool B[101];


bool solve(int limit) {
    int source = 2 * AC;
    int sink = 2 * AC + 1;
    MaxFlowDinic mf(2 * AC + 2, source, sink);

    for (int ai = 0; ai < AC; ++ai) {
        if (B[ai]) {
            mf.addEdge(source, ai, AF[ai]);
            mf.addEdge(ai, sink, limit);
        } else {
            mf.addEdge(source, ai, AF[ai] - 1);
        }
        mf.addEdge(ai, AC + ai, AF[ai]);
        for (int ali = 0; ali < ALC[ai]; ++ali) {
            int aj = AL[ai][ali];
            mf.addEdge(AC + ai, aj, AF[ai]);
        }
    }
    
    return BC * limit <= mf.maximumFlow(); 
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        AC = 0;
        BC = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &F[i]);
            if (F[i] > 0) {
                IA[i] = AC;
                AI[AC] = i;
                ALC[AC] = 0;
                AF[AC] = F[i];
                B[AC] = false;
                ++AC;
            }
        }
        for (int i = 0; i < N; ++i) {
            scanf("%s", G[i]);
        }
        for (int ai = 0; ai < AC; ++ai) {
            int i = AI[ai];
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (F[j] > 0) {
                    if (G[i][j] == 'Y') {
                        AL[ai][ALC[ai]++] = IA[j];
                    }
                } else {
                    B[ai] = B[ai] || (G[i][j] == 'Y');
                }
            }
            BC += B[ai];
        }

        int low = 0;
        int high = 10000;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (solve(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
