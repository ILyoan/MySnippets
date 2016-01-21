// baekjoon online judge 1103 (www.acmicnum_primes.net/problem/1103)

// Category: dfs
// Level: easy

#include <cstdio>

const int MAX_N = 50;

int Y, X;
char B[MAX_N + 1][MAX_N + 1];
int V[MAX_N + 1][MAX_N + 1];

bool cycle = false;

int max(int a, int b) { return a > b ? a : b; }

int solve(int y, int x) {
    if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
    if (B[y][x] == 'H') return 0;

    if (V[y][x] == 0) {
        // discovered and not finished means cycle.
        cycle = true;
        return -1;
    }
    if (V[y][x] > 0) {
        return V[y][x];
    }
    // discovore this cell.
    V[y][x] = 0;

    // dfs
    int res = 0;
    int d = B[y][x] - '0';
    res = max(res, solve(y + d, x) + 1);
    res = max(res, solve(y - d, x) + 1);
    res = max(res, solve(y, x + d) + 1);
    res = max(res, solve(y, x - d) + 1);

    // finished.
    return V[y][x] = res;
}

int main() {
    scanf("%d%d", &Y, &X);
    for (int i = 0; i < Y; ++i) {
        scanf("%s", B[i]);
    }
    for (int i = 0; i < Y; ++i) {
        for (int j = 0; j < X; ++j) {
            V[i][j] = -1;
        }
    }
    int res = solve(0, 0);
    if (cycle) {
        res = -1;
    }
    printf("%d\n", res);

    return 0;
}

