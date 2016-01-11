// baekjoon online judge 1992 (www.acmicnum_primes.net/problem/1992)

// Category: divide and conquer
// Level: pupil

#include <stdio.h>

const int MAX_N = 64;

int N;
char B[MAX_N + 1][MAX_N + 1];

void solve(int n, int y, int x) {
    bool same = true;
    for (int i = y; i < y + n; ++i) {
        for (int j = x; j < x + n; ++j) {
            if (B[i][j] != B[y][x]) {
                same = false;
                break;
            }
        }
    }
    if (same) {
        printf("%c", B[y][x]);
    } else {
        printf("(");
        solve(n / 2, y, x);
        solve(n / 2, y, x + n / 2);
        solve(n / 2, y + n / 2, x);
        solve(n / 2, y + n / 2, x + n / 2);
        printf(")");
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", B[i]);
    }

    solve(N, 0, 0);

    return 0;
}
