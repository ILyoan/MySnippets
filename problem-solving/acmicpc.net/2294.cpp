// baekjoon online judge 2294 (www.acmicpc.net/problem/2294)

// Category: DP
// Difficulty: Easy

#include <stdio.h>

const int MAX_N = 100;
const int MAX_K = 10000;

int N, K;
int coin[MAX_N + 1];
int mem[MAX_K + 1];

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i <= K; ++i) {
        mem[i] = -1;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &coin[i]);
    }
    mem[0] = 0;
    for (int to = 1; to <= K; ++to) {
        for (int i = 0; i < N; ++i) {
            int from = to - coin[i];
            if (from >= 0 && mem[from] != -1) {
                if (mem[to] == -1 || mem[to] > mem[from] + 1) {
                    mem[to] = mem[from] + 1;
                }
            }
        }
    }
    printf("%d\n", mem[K]);
    return 0;
}
