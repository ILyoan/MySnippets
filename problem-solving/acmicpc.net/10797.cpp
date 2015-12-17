// baekjoon online judge 10797 (www.acmicpc.net/problem/10797)

#include <cstdio>

int main() {
    int x;
    scanf("%d", &x);

    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        int y;
        scanf("%d", &y);
        if (x == y) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
