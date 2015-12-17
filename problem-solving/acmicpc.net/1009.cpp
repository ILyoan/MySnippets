// baekjoon online judge 1009 (www.acmicpc.net/problem/1009)

#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        int a, b;
        scanf("%d%d", &a, &b);

        int ans = 1;
        for (int i = 0; i < b; ++i) {
            ans = (ans * a) % 10;
        }

        if (ans == 0) {
            ans = 10;
        }

        printf("%d\n", ans);
    }

    return 0;
}
