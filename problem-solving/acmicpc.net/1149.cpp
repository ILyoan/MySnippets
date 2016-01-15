// baekjoon online judge 1149 (www.acmicpc.net/problem/1149)

// Category: DP
// Difficulty: Easy

#include <stdio.h>

const int MAX_N = 1000;

int N;
int cost[MAX_N + 1][3];
int mem[MAX_N + 1][3];

int min(int a, int b) { return a < b ? a : b; }

int solve(int i, int j) {
    if (i == 0) {
        return 0;
    }
    int& res = mem[i][j];
    if (res != -1) {
        return res;
    }
    res = cost[i][j];
    if (j == 0) res += min(solve(i - 1, 1), solve(i - 1, 2));
    if (j == 1) res += min(solve(i - 1, 0), solve(i - 1, 2));
    if (j == 2) res += min(solve(i - 1, 0), solve(i - 1, 1));
    return res;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    for (int i = 1; i <= N; ++i) {
        mem[i][0] = mem[i][1] = mem[i][2] = -1;
    }
    printf("%d\n", min(solve(N, 0), min(solve(N, 1), solve(N, 2))));
    return 0;
}
