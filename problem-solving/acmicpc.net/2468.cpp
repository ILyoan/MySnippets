// baekjoon online judge 2468 (www.acmicnum_primes.net/problem/2468)

// Category: DFS, bruth force
// Level: Pupil.

#include <cstdio>

const int MAX_N = 100;
const int MAX_HEIGHT = 100;

int N;
int B[MAX_N + 1][MAX_N + 1];
int C[MAX_N + 1][MAX_N + 1];

void colorArea(int y, int x, int rain, int color) {
    if (y < 0 || y >= N || x < 0 || x >= N) {
        return;
    }
    if (C[y][x] != 0 || B[y][x] <= rain) {
        return;
    }
    C[y][x] = color;

    colorArea(y - 1, x, rain, color);
    colorArea(y + 1, x, rain, color);
    colorArea(y, x - 1, rain, color);
    colorArea(y, x + 1, rain, color);
}

int getNumSafeArea(int rain) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
        }
    }

    int color = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (C[i][j] == 0 && B[i][j] > rain) {
                color += 1;
                colorArea(i, j, rain, color);
            }
        }
    }

    return color;
}

int main() {
    scanf("%d", &N);

    int max_height = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &B[i][j]);
            if (max_height < B[i][j]) {
                max_height = B[i][j];
            }
        }
    }

    int ans = 1;
    for (int rain = 1; rain <= max_height; ++rain) {
        int num_safe_area = getNumSafeArea(rain);

        if (ans < num_safe_area) {
            ans = num_safe_area;
        }
    }

    printf("%d\n", ans);

    return 0;
}
