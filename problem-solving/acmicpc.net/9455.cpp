// baekjoon online judge 9455 (www.acmicnum_primes.net/problem/9455)

// Category: greedy
// Level: pupil

#include <cstdio>

const int MAX_N = 100;

int Box[MAX_N + 1][MAX_N + 1];

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &Box[i][j]);
            }
        }

        int sum = 0;
        for (int j = 0; j < m; ++j) {
            int spaces = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (Box[i][j] == 0) {
                    spaces += 1;
                } else {
                    sum += spaces;
                }
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
