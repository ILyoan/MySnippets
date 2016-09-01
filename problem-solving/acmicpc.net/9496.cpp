// acmicpc.net/problem/9496
// category : bipartite matching, maximum independent set

#include <cstdio>
#include <vector>
using namespace std;
 
class BipartiteGraph {
  public:
    BipartiteGraph(int left_size, int right_size) 
      : _l_size(left_size), _r_size(right_size), _g(left_size) {
    }
 
    void addEdge(int li, int ri) {
        _g[li].push_back(ri);
    }
 
    int maximumMatching() {
        int matches = 0;
        _l_match = vector<int>(_l_size, -1);
        _r_match = vector<int>(_r_size, -1);
        for (int li = 0; li < _l_size; ++li) {
            _visited = vector<bool>(_l_size, false);
            if (augment(li)) {
                ++matches;
            }
        }
        return matches;
    }
 
  private:
    bool augment(int li) {
        if (_visited[li]) {
            return false;
        }
        _visited[li] = true;
        for (int ri : _g[li]) {
            if (_r_match[ri] == -1 || augment(_r_match[ri])) {
                _l_match[li] = ri;
                _r_match[ri] = li;
                return true;
            }
        }
        return false;
    }
 
  private:
    int _l_size;
    int _r_size;
    vector<vector<int>> _g;
    vector<int> _l_match;
    vector<int> _r_match;
    vector<bool> _visited;
};

int N;
char G[51];
char R[51][51];
int GC[4];
int GL[4][51];

int solve(int g1, int g2) {
    BipartiteGraph bg(GC[g1], GC[g2]);
    for (int i = 0; i < GC[g1]; ++i) {
        for (int j = 0; j < GC[g2]; ++j) {
            if (R[GL[g1][i]][GL[g2][j]] == 'Y') {
                bg.addEdge(i, j);
            }
        }
    }
    return N - bg.maximumMatching();
}

int main() {
    scanf("%d%s", &N, G);
    for (int i = 0; i < N; ++i) {
        scanf("%s", R[i]);
    }
    for (int i = 0; i < N; ++i) {
        int g = G[i] - '0';
        GL[g][GC[g]++] = i;
    }

    int ans12 = solve(1, 2);
    int ans13 = solve(1, 3);
    int ans23 = solve(2, 3);

    printf("%d\n", max(max(ans12, ans13), ans23));
    
    return 0;
}
