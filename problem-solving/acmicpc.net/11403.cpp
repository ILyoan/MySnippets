// baekjoon online judge 11403 (www.acmicpc.net/problem/11403)

// Category: floyd
// Difficulty: pupil

#include <cstdio>

const int MAX_N = 100;

int N;
int G[MAX_N + 1][MAX_N + 1];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &G[i][j]);
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] && G[k][j]) {
                    G[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}
