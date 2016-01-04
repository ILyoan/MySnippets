// baekjoon online judge 2577 (www.acmicnum_primes.net/problem/2577)

// Level: Pupil.

#include <cstdio>

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);

    int n = A * B * C;
    int count[10] = {0};
    while (n > 0) {
        count[n % 10] += 1;
        n /= 10;
    }

    for (int i = 0; i <= 9; ++i) {
        printf("%d\n", count[i]);
    }

    return 0;
}
