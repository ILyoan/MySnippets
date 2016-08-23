// acmicpc.net 11014
// category: bipartite matching, independent set.

#include <cstdio>
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

    int maximum_independent_set() {
        int independent_size = _l_size;

        maximum_matching();

        _l_independent = vector<bool>(_l_size, true);
        _r_independent = vector<bool>(_r_size, false);
        for (int ri = 0; ri < _r_size; ++ri) {
            if (_r_match[ri] == -1) {
                _r_independent[ri] = true;
                ++independent_size;
            }
        }

        while (true) {
            bool updated = false;
            for (int li = 0; li < _l_size; ++li) {
                for (int ri : _graph[li]) {
                    if (_l_independent[li] && _r_independent[ri]) {
                        _l_independent[li] = false;
                        _r_independent[_l_match[li]] = true;
                        updated = true;
                    }
                }
            }
            if (!updated) {
                break;
            }
        }

        return independent_size;
    }

    vector<int> match_left() { return _l_match; }
    vector<int> match_right() { return _r_match; }
    vector<bool> independent_left() { return _l_independent; }
    vector<bool> independent_right() { return _r_independent; }

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
    vector<bool> _l_independent;
    vector<bool> _r_independent;
    vector<bool> _visited;
};

int B[81][81];
int dy[] = { -1, -1, 0, 0, 1, 1};
int dx[] = { -1, 1, -1, 1, -1, 1};

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ls = 0;
        int rs = 0;
        for (int y = 0; y < n; ++y) {
            char line[81];
            scanf("%s", line);
            for (int x = 0; x < m; ++x) {
                if (line[x] == '.') {
                    if ((x % 2) == 0) {
                        B[y][x] = ls++; 
                    } else {
                        B[y][x] = rs++;
                    }
                } else {
                    B[y][x] = -1;
                }
            }
        }

        BipartiteGraph graph(ls, rs);
        
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; x += 2) {
                if (B[y][x] != -1) {
                    for (int k = 0; k < 6; ++k) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m || B[ny][nx] == -1) {
                            continue;
                        }
                        graph.add_edge(B[y][x], B[ny][nx]);
                    }
                }
            }
        }

        printf("%d\n", graph.maximum_independent_set());
    }
    return 0;
}
