// baekjoon online judge 9613 (www.acmicpc.net/problem/9613)

#include <cstdio>

int A[101];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                sum += gcd(A[i], A[j]);
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
