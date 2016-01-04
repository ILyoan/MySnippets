// baekjoon online judge 2563 (www.acmicnum_primes.net/problem/2563)

// Category: implementation, brute force
// Level: pupil

#include <cstdio>

const int CANVAS_LENGTH = 100;
const int PAPER_LENGTH = 10;

bool Canvas[CANVAS_LENGTH + 1][CANVAS_LENGTH + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);

        for (int yy = y; yy < y + PAPER_LENGTH; ++yy) {
            for (int xx = x; xx < x + PAPER_LENGTH; ++xx) {
                Canvas[yy][xx] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < CANVAS_LENGTH; ++i) {
        for (int j = 0; j < CANVAS_LENGTH; ++j) {
            if (Canvas[i][j] == 1) {
                ans += 1;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
