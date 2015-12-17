// baekjoon online judge 10816 (www.acmicpc.net/problem/10816)

#include <cstdio>

const int OFFSET = 10000001;
const int RANGE = 2 * OFFSET + 1;

int card_count[RANGE];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        card_count[x + OFFSET] += 1;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        printf("%d ", card_count[x + OFFSET]);
    }

    printf("\n");

    return 0;
}
