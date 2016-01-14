// baekjoon online judge 2096 (www.acmicpc.net/problem/2096)

// Category: DP
// Difficulty: Easy

#include <stdio.h>

const int MAX_N = 100000;

int N;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    scanf("%d", &N);

    int maxs[3] = { 0 };
    int mins[3] = { 0 };

    for (int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        int a1 = max(maxs[0], maxs[1]) + a;
        int b1 = max(maxs[0], max(maxs[1], maxs[2])) + b;
        int c1 = max(maxs[1], maxs[2]) + c;

        maxs[0] = a1;
        maxs[1] = b1;
        maxs[2] = c1;

        int a2 = min(mins[0], mins[1]) + a;
        int b2 = min(mins[0], min(mins[1], mins[2])) + b;
        int c2 = min(mins[1], mins[2]) + c;

        mins[0] = a2;
        mins[1] = b2;
        mins[2] = c2;
    }

    printf("%d %d\n", max(maxs[0], max(maxs[1], maxs[2])), min(mins[0], min(mins[1], mins[2])));

    return 0;
}
