// acmicpc.net 2570
// category: bipartite matching

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

int N, M;
bool B[101][101];
int A1[101][101];
int A2[101][101];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int y, x;
        scanf("%d%d", &y, &x);
        B[y - 1][x - 1] = true;
    }
    int a1 = 0;
    int a2 = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (!B[y][x]) {
                if (A1[y][x] == 0) {
                    ++a1;
                    int ny = y;
                    int nx = x;
                    while (ny < N && nx < N && !B[ny][nx]) {
                        A1[ny++][nx++] = a1;
                    }
                }
                if (A2[y][x] == 0) {
                    ++a2;
                    int ny = y;
                    int nx = x;
                    while (ny < N && nx >= 0 && !B[ny][nx]) {
                        A2[ny++][nx--] = a2;
                    }
                }
            }
        }
    }
    BipartiteGraph graph(a1 + 1, a2 + 1);

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (!B[y][x]) {
                graph.add_edge(A1[y][x], A2[y][x]);
            }
        }
    }

    printf("%d\n", graph.maximum_matching());

    return 0;
}
