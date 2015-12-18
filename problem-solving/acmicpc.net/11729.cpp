// baekjoon online judge 11729 (www.acmicpc.net/problem/11729)

#include <cstdio>

void move(int n, int from, int to, int temp) {
    if (n == 0) {
        return;
    }

    move(n - 1, from, temp, to);
    printf("%d %d\n", from, to);
    move(n - 1, temp, to, from);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    move(n, 1, 3, 2);
    return 0;
}
