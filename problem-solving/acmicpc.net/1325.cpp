// baekjoon online judge 1325 (www.acmicnum_primes.net/problem/1325)

// Category: dfs
// Level: easy

#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Graph;

const int MAX_V = 10000;
const int MAX_E = 100000;

int V, E;
Graph G;
bool visited[MAX_V + 1];
int answer[MAX_V + 1];

int dfs(int u) {
	if (visited[u]) return 0;
	visited[u] = true;
	
	int res = 1;
	for (int v : G[u]) {
		res += dfs(v);
	}
	return res;
}

int main() {
	scanf("%d%d", &V, &E);
	G = Graph(V);
	for (int i = 0; i < E; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[v - 1].push_back(u - 1);
	}

	int max_answer = 0;
	for (int u = 0; u < V; ++u) {
		for (int i = 0; i < V; ++i) visited[i] = false;
		answer[u] = dfs(u);
		if (max_answer < answer[u]) {
			max_answer = answer[u];
		}
	}

	for (int u = 0; u < V; ++u) {
		if (answer[u] == max_answer) {
			printf("%d ", u + 1);
		}
	}
	printf("\n");

	return 0;
}
