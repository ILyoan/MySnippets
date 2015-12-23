// baekjoon online judge 2606 (www.acmicnum_primes.net/problem/2606)

// Category: graph, floyd, transitive.
// Level: Pupil.

#include <cstdio>

const int MAX_V = 100;

int N, M;
bool T[MAX_V + 1][MAX_V + 1];

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            T[i][j] = false;
        }
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        T[u][v] = true;
        T[v][u] = true;
    }

    // warshal algorithm
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (T[i][k] && T[k][j]) {
                    T[i][j] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= N; ++i) {
        if (T[1][i]) {
            ans += 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
