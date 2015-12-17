// baekjoon online judge 2445 (www.acmicpc.net/problem/2445)

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("*");
        }
        for (int j = 0; j < 2 * n - (2 * i + 2); ++j) {
            printf(" ");
        }
        for (int j = 0; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            printf("*");
        }
        for (int j = 0; j < 2 * n - (2 * i + 2); ++j) {
            printf(" ");
        }
        for (int j = 0; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
