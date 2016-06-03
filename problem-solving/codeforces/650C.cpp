// Codeforces 650/C
// [scc]

#include <cstdio>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;

typedef vector<vector<int>> Graph;
 
class SCC
{
public:
    vector<int> Solve(const Graph& g) {
        int n = g.size();
        _di = 0;
        _scc_count = 0;
        _scc_ids = vector<int>(n);
        _discovers = vector<int>(n, -1);
        _is_in_stack = vector<bool>(n);
        for (int u = 0; u < n; ++u) {
            if (_discovers[u] == -1) {
                Solve(g, u);
            }
        }
        return _scc_ids;
    }
    int size() { return _scc_count; }
private:
    int Solve(const Graph& g, int u) {
        int low = _discovers[u] = _di++;
        _stack.push(u);
        _is_in_stack[u] = true;
        for (int v : g[u]) {
            if (_discovers[v] == -1) {
                low = min(low, Solve(g, v));
            }
            else if (_is_in_stack[v]) {
                low = min(low, _discovers[v]);
            }
        }
        if (low == _discovers[u]) {
            while (true) {
                int v = _stack.top();
                _stack.pop();
                _scc_ids[v] = _scc_count;
                _is_in_stack[v] = false;
                if (u == v) {
                    break;
                }
            }
            ++_scc_count;
        }
        return low;
    }
    int _di;
    int _scc_count;
    vector<int> _scc_ids;
    vector<int> _discovers;
    vector<bool> _is_in_stack;
    stack<int> _stack;
};

int pointToIndex(int y, int x) { return y * M + x; }

int main() {
    scanf("%d%d", &N, &M);
    vector<vector<int>> A(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int a;
            scanf("%d", &a);
            A[i].push_back(a);
        }
    }

    // Create graph
    V = N * M;
    Graph g(V);
    for (int y = 0; y < N; ++y) {
        vector<pair<int, int>> vec;
        for (int x = 0; x < M; ++x) {
            vec.push_back(make_pair(A[y][x], x));
        }
        sort(vec.begin(), vec.end());
        for (int j = 1; j < M; ++j) {
            int idx_a = pointToIndex(y, vec[j - 1].second);
            int idx_b = pointToIndex(y, vec[j].second);
            g[idx_a].push_back(idx_b);
            if (vec[j].first == vec[j-1].first) {
                g[idx_b].push_back(idx_a);
            } 
        }
    }
    for (int x = 0; x < M; ++x) {
        vector<pair<int, int>> vec;
        for (int y = 0; y < N; ++y) {
            vec.push_back(make_pair(A[y][x], y));
        }
        sort(vec.begin(), vec.end());
        for (int j = 1; j < N; ++j) {
            int idx_a = pointToIndex(vec[j - 1].second, x);
            int idx_b = pointToIndex(vec[j].second, x);
            g[idx_a].push_back(idx_b);
            if (vec[j].first == vec[j-1].first) {
                g[idx_b].push_back(idx_a);
            }
        }
    }

    // Solve SCC
    SCC scc;
    vector<int> to_scc = scc.Solve(g);

    // Construct SCC graph
    Graph sccg(scc.size());
    vector<int> scc_size(sccg.size());
    vector<int> scc_indegrees(sccg.size());
    vector<set<int>> scc_adj_set(sccg.size());
    for (int u = 0; u < V; ++u) {
        int sccu = to_scc[u];
        scc_size[sccu]++;
        for (int v : g[u]) {
            int sccv = to_scc[v];
            if (sccu != sccv) {
                scc_adj_set[sccu].insert(sccv);
            }
        }
    }
    for (int sccu = 0; sccu < sccg.size(); ++sccu) {
        for (int sccv : scc_adj_set[sccu]) {
            sccg[sccu].push_back(sccv);
            scc_indegrees[sccv]++;
        }
    }

    // Topologycal sort
    queue<int> que;
    for (int sccu = 0; sccu < sccg.size(); ++sccu) {
        if (scc_indegrees[sccu] == 0) {
            que.push(sccu);
        }    
    }

    int depth = 0;
    vector<int> scc_order(sccg.size());
    while (!que.empty()) {
        depth++;
        int que_size = que.size();
        while (que_size--) {
            int sccu = que.front();
            que.pop();
            scc_order[sccu] = depth;
            for (int sccv : sccg[sccu]) {
                if (--scc_indegrees[sccv] == 0) {
                    que.push(sccv);
                }
            }
        }
    }

    // print answer
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            int index = pointToIndex(y, x);
            int sccu = to_scc[index];
            int order = scc_order[sccu];
            printf("%d ", order);
        }
        printf("\n");
    }

    return 0;
}
