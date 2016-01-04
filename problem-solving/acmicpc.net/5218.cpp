// baekjoon online judge 5218 (www.acmicnum_primes.net/problem/5218)

// Level: Pupil.

#include <cstdio>

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        char S1[21];
        char S2[21];
        scanf("%s%s", S1, S2);

        printf("Distances:");
        for (int i = 0; S1[i]; ++i) {
            if (S1[i] <= S2[i]) {
                printf(" %d", S2[i] - S1[i]);
            } else {
                printf(" %d", S2[i] - S1[i] + 26);
            }
        }
        printf("\n");
    }
    return 0;
}
