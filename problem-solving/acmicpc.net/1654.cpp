// baekjoon online judge 1654 (www.acmicnum_primes.net/problem/1654)

#include <cstdio>

int A[10001];

int main() {
    int k, n;
    scanf("%d%d", &k, &n);

    int lb = 1;
    int ub = 1;
    int ans = 1;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &A[i]);
        if (ub < A[i]) {
            ub = A[i];
        }
    }

    while (lb <= ub) {
        int len = (ub + lb) / 2;

        int pieces = 0;
        for (int i = 0; i < k; ++i) {
            pieces += A[i] / len;
        }

        if (pieces >= n) {
            ans = len;
            lb = len + 1;
        }
        else {
            ub = len - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}