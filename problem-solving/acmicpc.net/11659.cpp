// baekjoon online judge 11659 (www.acmicpc.net/problem/11659)

#include <cstdio>

int A[100001];
int S[100001];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; ++i) {
        S[i + 1] = S[i] + A[i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", S[b] - S[a - 1]);
    }

    return 0;
}
