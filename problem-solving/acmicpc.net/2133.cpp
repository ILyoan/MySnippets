// baekjoon online judge 2133 (www.acmicpc.net/problem/2133)

// Category: DP
// Difficulty: Easy

#include <stdio.h>

const int MAX_N = 30;

int N;
int mem[MAX_N + 1];

int main() {
    scanf("%d", &N);
    mem[0] = 1;
    mem[1] = 0;
    for (int i = 2; i <= N; ++i) {
        mem[i] = 3 * mem[i - 2];
        for (int j = i - 4; j >= 0; j -= 2) {
            mem[i] += 2 * mem[j];
        }
    }
    printf("%d\n", mem[N]);
    return 0;
}
