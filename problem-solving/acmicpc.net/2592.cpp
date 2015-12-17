// baekjoon online judge 2592 (www.acmicpc.net/problem/2592)

#include <cstdio>

int count[1001];

int main() {
    int sum = 0;
    int mode = 0;
    for (int i = 0; i < 10; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        count[x] += 1;
    }

    for (int i = 0; i <= 1000; i += 10) {
        if (count[mode] < count[i]) {
            mode = i;
        }
    }

    printf("%d\n", sum / 10);
    printf("%d\n", mode);

    return 0;
}
