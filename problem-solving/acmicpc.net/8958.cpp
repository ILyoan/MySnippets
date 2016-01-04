// baekjoon online judge 8958 (www.acmicnum_primes.net/problem/8958)

// Category: implementation
// Level: pupil

#include <cstdio>

const int MAX_LENGTH = 80;

char S[MAX_LENGTH + 1];

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%s", S);
        int succ = 0;
        int sum = 0;
        for (int i = 0; S[i]; ++i) {
            if (S[i] == 'O') {
                succ += 1;
                sum += succ;
            } else {
                succ = 0;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
