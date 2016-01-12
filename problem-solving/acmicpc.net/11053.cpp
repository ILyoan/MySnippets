// baekjoon online judge 11053 (www.acmicpc.net/problem/11053)

#include <cstdio>

const int MAX_N = 1000;

int N;
int A[MAX_N + 1];
int D[MAX_N + 1];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; ++i) {
        D[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && D[i] < D[j] + 1) {
                D[i] = D[j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (ans < D[i]) {
            ans = D[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
