// baekjoon online judge 1969 (www.acmicnum_primes.net/problem/1969)

// Category: implementation, greedy
// Level: pupil

#include <cstdio>

const int MAX_N = 1000;
const int MAX_M = 50;

char DNA[MAX_N + 1][MAX_M + 1];
char ans[MAX_M + 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", DNA[i]);
    }

    int sum_dist = 0;
    for (int i = 0; i < m; ++i) {
        int count[26] = {0};
        for (int j = 0; j < n; ++j) {
            count[DNA[j][i] - 'A'] += 1;
        }
        int max_char = 0;
        for (int k = 0; k < 26; ++k) {
            if (count[k] > count[max_char]) {
                max_char = k;
            }
        }
        ans[i] = max_char + 'A';
        sum_dist += n - count[max_char];
    }
    printf("%s\n", ans);
    printf("%d\n", sum_dist);

    return 0;
}
