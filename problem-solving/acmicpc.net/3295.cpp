// acmicpc.net/problem/3295
// category : bipartite matching

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

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int V, E;
        scanf("%d%d", &V, &E);
        BipartiteGraph bg(V, V);
        for (int ei = 0; ei < E; ++ei) {
            int u, v;
            scanf("%d%d", &u, &v);
            bg.addEdge(u, v);
        }
        printf("%d\n", bg.maximumMatching());
    }
    return 0;
}
