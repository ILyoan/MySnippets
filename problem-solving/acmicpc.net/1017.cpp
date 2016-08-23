// acmicpc.net 1017
// category: bipartite matching.

#include <cstdio>
#include <vector>
#include <algorithm>
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

int A[1001];
bool is_not_prime[2001];

int main() {
    is_not_prime[0] = true;
    is_not_prime[1] = true;
    for (int i = 2; i * i <= 2000; ++i) {
        if (!is_not_prime[i]) {
            for (int j = i * i; j <= 2000; j += i) {
                is_not_prime[j] = true;
            }
        }
    }
    
    int n;
    scanf("%d", &n);

    vector<int> ls;
    vector<int> rs;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        if (A[i] % 2 == A[0] % 2) {
            ls.push_back(A[i]);
        } else {
            rs.push_back(A[i]);
        } 
    }

    vector<int> res;
    if (ls.size() == rs.size()) {
        for (int k = 0; k < rs.size(); ++k) {
            if (!is_not_prime[ls[0] + rs[k]]) {
                BipartiteGraph graph(ls.size(), rs.size());

                for (int li = 1; li < ls.size(); ++li) {
                    for (int ri = 0; ri < rs.size(); ++ri) {
                        if (ri != k && !is_not_prime[ls[li] + rs[ri]]) {
                            graph.add_edge(li, ri);
                        }
                    }
                }

                if (graph.maximum_matching() == ls.size() - 1) {
                    res.push_back(rs[k]);
                }
            } 
        }
    }

    if (res.size() > 0) {
        sort(res.begin(), res.end());
        for (int ans : res) {
            printf("%d ", ans);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }

    return 0;
}
