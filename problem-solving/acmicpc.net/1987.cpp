// baekjoon online judge 1987 (www.acmicnum_primes.net/problem/1987)

// Category: DFS
// Level: Pupil

#include <cstdio>

const int MAX_R = 20;
const int MAX_C = 20;

int R, C;

char A[MAX_R + 1][MAX_C + 1];
bool used[26];

int ans;

void go(int y, int x, int depth) {
    if (y < 0 || y >= R || x < 0 | x >= C) {
        return;
    }

    if (used[A[y][x] - 'A']) {
        return;
    }

    used[A[y][x] - 'A'] = true;

    if (ans < depth) {
        ans = depth;
    }

    go(y, x + 1, depth + 1);
    go(y, x - 1, depth + 1);
    go(y + 1, x, depth + 1);
    go(y - 1, x, depth + 1);

    used[A[y][x] - 'A'] = false;
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", A[i]);
    }

    go(0, 0, 1);

    printf("%d\n", ans);

    return 0;
}
