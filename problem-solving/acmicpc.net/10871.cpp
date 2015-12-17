// baekjoon online judge 10871 (www.acmicpc.net/problem/10871)

#include <cstdio>

int main() {
    int n, x;
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (a < x) {
            printf("%d ", a);
        }
    }
    printf("\n");

    return 0;
}
