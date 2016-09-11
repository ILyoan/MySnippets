// acmicpc.net/problem/1867
// category : bipartite matching, vertex cover
// Kőnig's theorem : In any bipartite graph, the number of edges in a maximum matching equals the number of vertices in a minimum vertex cover

#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
int L[501];
int R[501];
int Visited[501];
vector<vector<int>> G;

int dfs(int u) {
	if (Visited[u]) return 0;
	Visited[u] = 1;
	for (int v : G[u]) {
		if (R[v] == 0 || dfs(R[v])) {
			R[v] = u;
			L[u] = v;
			return 1;
		}
	}
	return 0;
}

int solve() {
	int ans = 0;
	for (int u = 1; u <= N; ++u) {
		memset(Visited, 0, sizeof(Visited));
		ans += dfs(u);
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	G = vector<vector<int>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	printf("%d\n", solve());
	return 0;
}
