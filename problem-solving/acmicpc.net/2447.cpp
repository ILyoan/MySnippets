// baekjoon online judge 2447 (www.acmicnum_primes.net/problem/2447)

#include <cstdio>

const int MAX_N = 3 * 3 * 3 * 3 * 3 * 3 * 3;

char B[MAX_N + 1][MAX_N + 1];

void fillStar(int n, int y, int x) {
    if (n == 1) {
        B[y][x] = '*';
        return;
    }

    int m = n / 3;

    fillStar(m, y, x);
    fillStar(m, y, x + m);
    fillStar(m, y, x + m + m);

    fillStar(m, y + m, x);
    fillStar(m, y + m, x + m + m);

    fillStar(m, y + m + m, x);
    fillStar(m, y + m + m, x + m);
    fillStar(m, y + m + m, x + m + m);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B[i][j] = ' ';
        }
    }

    fillStar(n, 0, 0);

    for (int i = 0; i < n; ++i) {
        printf("%s\n", B[i]);
    }

    return 0;
}
