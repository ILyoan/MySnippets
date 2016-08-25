// acmicpc.net/problem/3683
// category : bipartite graph, vertex cover

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class BipartiteGraph {
  public:
    BipartiteGraph(int left_size, int right_size) 
      : _l_size(left_size), _r_size(right_size), _graph(left_size) {
    }

    void add_edge(int li, int ri) {
        _graph[li].push_back(ri);
    }

    int maximum_matching() {
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
        for (int ri : _graph[li]) {
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
    vector<vector<int>> _graph;
    vector<int> _l_match;
    vector<int> _r_match;
    vector<bool> _visited;
};

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int catc, dogc, watchc;
        scanf("%d%d%d", &catc, &dogc, &watchc);

        vector<pair<int, int>> cats;
        vector<pair<int, int>> dogs;
        for (int i = 0; i < watchc; ++i) {
            char a[10];
            char b[10];
            scanf("%s%s", a, b);
            if (a[0] == 'C') {
                cats.push_back(make_pair(atoi(&a[1]), atoi(&b[1]))); 
            } else {
                dogs.push_back(make_pair(atoi(&a[1]), atoi(&b[1])));
            }
        }
        BipartiteGraph graph(cats.size(), dogs.size());
        for (int ci = 0; ci < cats.size(); ++ci) {
            for (int di = 0; di < dogs.size(); ++di) {
                if (cats[ci].first == dogs[di].second || dogs[di].first == cats[ci].second) {
                    graph.add_edge(ci, di);
                }
            }
        }
        printf("%d\n", watchc - graph.maximum_matching());
    }
    return 0;
}
