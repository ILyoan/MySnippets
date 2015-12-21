// baekjoon online judge 1780 (www.acmicnum_primes.net/problem/1780)

#include <cstdio>

const int MAX_N = 3 * 3 * 3 * 3 * 3 * 3 * 3;

int A[MAX_N + 1][MAX_N + 1];

int zero;
int plus;
int minus;

void divide(int n, int y, int x) {
    bool same = true;
    for (int i = 0; i < n && same; ++i) {
        for (int j = 0; j < n && same; ++j) {
            if (A[i + y][j + x] != A[y][x]) {
                same = false;
            }
        }
    }
    if (same) {
        if (A[y][x] == -1) {
            minus += 1;
        } else if (A[y][x] == 0) {
            zero += 1;
        } else {
            plus += 1;
        }
        return;
    }

    int m = n / 3;
    divide(m, y, x);
    divide(m, y, x + m);
    divide(m, y, x + m + m);

    divide(m, y + m, x);
    divide(m, y + m, x + m);
    divide(m, y + m, x + m + m);

    divide(m, y + m + m, x);
    divide(m, y + m + m, x + m);
    divide(m, y + m + m, x + m + m);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    divide(n, 0, 0);

    printf("%d\n", minus);
    printf("%d\n", zero);
    printf("%d\n", plus);

    return 0;
}
