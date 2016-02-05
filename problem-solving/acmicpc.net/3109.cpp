// baekjoon online judge 3109 (www.acmicpc.net/problem/3109)

// category: backtrack
// difficulty: easy

#include <cstdio>

const int MAX_R = 10000;
const int MAX_C = 500;

int R, C;
char B[MAX_R + 1][MAX_C + 1];

bool go(int r, int c) {
    if (c == C) return true;
    if (r < 0 || r >= R) return false;
    if (B[r][c] == 'x') return false;
    B[r][c] = 'x';
    return go(r - 1, c + 1) || go(r, c + 1) || go(r + 1, c + 1);
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", B[i]);
    }

    int answer = 0;
    for (int r = 0; r < R; ++r) {
        if (go(r, 0)) {
            answer += 1;
        }
    }
    printf("%d\n", answer);

    return 0;
}
