// baekjoon online judge 11404 (www.acmicnum_primes.net/problem/11404)

// Category: graph, floyd, shortest path.
// Level: Pupil.

#include <cstdio>

const int MAX_N = 100;
const int INF = 1000000000;

int N, M;
int D[MAX_N + 1][MAX_N + 1];

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            D[i][j] = INF;
        }
        D[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (D[u][v] > w) {
            D[u][v] = w;
        }
    }

    // floyd algorithm.
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
