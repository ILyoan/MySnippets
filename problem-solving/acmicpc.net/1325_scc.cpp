// baekjoon online judge 1325 (www.acmicnum_primes.net/problem/1325)

// Category: dfs, scc, tarjan
// Level: medium

#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_V = 10000;
const int MAX_E = 100000;

typedef vector<vector<int>> Graph;

// Strongly Connected Component Solver by Tarjan's algorithm.
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


int V, E;

int SCC_size[MAX_V + 1];
bool SCC_visited[MAX_V + 1];
Graph SCCG;
int scc_dfs(int sccu) {
	if (SCC_visited[sccu]) return 0;
	SCC_visited[sccu] = true;

	int reachable = SCC_size[sccu];
	for (int sccv : SCCG[sccu]) {
		reachable += scc_dfs(sccv);
	}
	return reachable;
}

int main() {
	scanf("%d%d", &V, &E);
	Graph G1(V);
	for (int i = 0; i < E; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G1[v - 1].push_back(u - 1);
	}

	// Solve SCC
	SCC scc;
	vector<int> to_scc = scc.Solve(G1);

	// Construct SCC graph
	SCCG = Graph(scc.size());
	vector<int> scc_indegrees(SCCG.size());
	vector<set<int>> scc_adj_set(SCCG.size());
	for (int u = 0; u < V; ++u) {
		int sccu = to_scc[u];
		SCC_size[sccu]++;
		for (int v : G1[u]) {
			int sccv = to_scc[v];
			if (sccu != sccv) {
				scc_adj_set[sccu].insert(sccv);
			}
		}
	}
	for (int sccu = 0; sccu < SCCG.size(); ++sccu) {
		for (int sccv : scc_adj_set[sccu]) {
			SCCG[sccu].push_back(sccv);
			scc_indegrees[sccv]++;
		}
	}

	// Solve from each start vertex
	int max_cnt = 0;
	vector<int> count(SCCG.size());
	for (int sccu = 0; sccu < SCCG.size(); ++sccu) {
		if (scc_indegrees[sccu] == 0) {
			for (int i = 0; i < SCCG.size(); ++i) {
				SCC_visited[i] = false;
			}
			count[sccu] = scc_dfs(sccu);
			if (max_cnt < count[sccu]) {
				max_cnt = count[sccu];
			}
		}
	}

	// Print answer
	for (int u = 0; u < G1.size(); ++u) {
		int sccu = to_scc[u];
		if (count[sccu] == max_cnt) {
			printf("%d ", u + 1);
		}
	}
	printf("\n");

	return 0;
}
