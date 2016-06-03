// Codeforces 507/E
// [shortest path], [dijkstra]

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

#ifdef MYDEBUG
#define DPRINT(f, ...) printf(f, ##__VA_ARGS__);printf("\n");
#else
#define DPRINT(f, ...)
#endif

typedef long long i64;

vector<int> dijkstra(vector<vector<int> >& adj, vector<pair<i64, pair<int, int> > > edge, int start)
{
    int n = int(adj.size());
    vector<bool> visit(n, false);
	vector<int> prev(n, -1);
    vector<i64> res(n, numeric_limits<i64>::max());
    priority_queue<pair<i64, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        i64 weight = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (visit[u]) continue;
        visit[u] = true;
        for (int e = 0; e < adj[u].size(); ++e) {
			int eidx = adj[u][e];
			int v1 = edge[eidx].second.first;
			int v2 = edge[eidx].second.second;
            i64 w = edge[eidx].first;
			int v = v1;
			if (u == v) v = v2;
            if (weight + w < res[v]) {
                res[v] = weight + w;
                pq.push(make_pair(-res[v], v));
				prev[v] = eidx;
            }
        }
    }
    return prev;
}


int main() {
	int nv, ne;
	scanf("%d%d", &nv, &ne);
	vector<vector<int> > adj(nv);
	vector<pair<i64, pair<int, int> > > edge(ne);
	for (int i = 0; i < ne; ++i) {
		int u, v, z;
		scanf("%d%d%d", &u, &v, &z);
		--u;--v;z=1-z;
		edge[i] = make_pair(1000000+z, make_pair(u, v));
		adj[u].push_back(i);
		adj[v].push_back(i);
	}
	vector<int> prev = dijkstra(adj, edge, 0);
	vector<bool> used(ne, false);
	int v = nv-1;
	do {
		int eidx = prev[v];
		int u1 = edge[eidx].second.first;
		int u2 = edge[eidx].second.second;
		int u = u1;
		if (u == v) u = u2;
		used[eidx] = true;
		v = u;
	} while (v);
	int res = 0;
	vector<bool> aff(ne, false);
	for (int i = 0; i < ne; ++i) {
		if (used[i]) {
			aff[i] = edge[i].first & 1;
		} else {
			aff[i] = !(edge[i].first & 1);
		}
		res += aff[i];
	}
	printf("%d\n", res);
	for (int i = 0; i < ne; ++i) {
		if (aff[i]) {
			int u = edge[i].second.first + 1;
			int v = edge[i].second.second + 1;
			int z = edge[i].first & 1;
			printf("%d %d %d\n", u, v, z);
		}
	}
	return 0;
}
