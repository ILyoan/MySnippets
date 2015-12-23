// baekjoon online judge 1956 (www.acmicnum_primes.net/problem/1956)

// Category: graph, floyd, cycle.
// Level: Pupil.

#include <cstdio>

const int MAX_N = 400;
const int INF = 1000000000;

int N, M;
int G[MAX_N + 1][MAX_N + 1];

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            G[i][j] = INF;
        }
    }

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (G[u][v] > w) {
            G[u][v] = w;
        }
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (G[i][j] > G[i][k] + G[k][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }

    int min_cycle = INF;
    for (int i = 1; i <= N; ++i) {
        if (min_cycle > G[i][i]) {
            min_cycle = G[i][i];
        }
    }

    if (min_cycle == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", min_cycle);
    }

    return 0;
}
