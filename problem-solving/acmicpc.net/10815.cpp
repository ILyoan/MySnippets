// baekjoon online judge 10815 (www.acmicpc.net/problem/10815)

#include <cstdio>

const int OFFSET = 10000001;
const int RANGE = 2 * OFFSET + 1;

bool is_exsist[RANGE];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        is_exsist[x + OFFSET] = true;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        printf("%d ", is_exsist[x + OFFSET] ? 1 : 0);
    }

    printf("\n");

    return 0;
}
