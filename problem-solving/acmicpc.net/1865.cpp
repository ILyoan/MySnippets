// baekjoon online judge 1865 (www.acmicnum_primes.net/problem/1865)

// Category: Graph, shortest path, bellman ford
// Level: east

#include <stdio.h>

const int MAX_V = 500;
const int MAX_E = 6000;
const int INF = 1000000000;

struct Edge {
    Edge() : u(-1), v(-1) {}
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    bool operator<(const Edge& e) { return w < e.w; }
    int u, v, w;
};

Edge edges[MAX_E];
int dists[MAX_V];

bool findNagative(int V, int E) {
    for (int u = 1; u <= V; ++u) {
        dists[u] = INF;
    }

    dists[1] = 0;
    for (int iter = 0; iter < V - 1; ++iter) {
        for (int ei = 0; ei < E; ++ei) {
            Edge e = edges[ei];
            if (dists[e.v] > dists[e.u] + e.w) {
                dists[e.v] = dists[e.u] + e.w;
            }
        }
    }

    for (int ei = 0; ei < E; ++ei) {
        Edge e = edges[ei];
        if (dists[e.v] > dists[e.u] + e.w) {
            return true;
        }
    }
    return false;
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        int V, E1, E2, E = 0;
        scanf("%d%d%d", &V, &E1, &E2);

        for (int i = 0; i < E1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edges[E++] = Edge(u, v, w);
            edges[E++] = Edge(v, u, w);
        }
        for (int i = 0; i < E2; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edges[E++] = Edge(u, v, -w);
        }

        printf("%s\n", findNagative(V, E) ? "YES" : "NO");
    }

    return 0;
}
