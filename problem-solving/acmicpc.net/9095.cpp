// baekjoon online judge 9095 (www.acmicnum_primes.net/problem/9095)

// Category: DFS, brute force.
// Level: Pupil.

#include <cstdio>

int go(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    return go(n - 1) + go(n - 2) + go(n - 3);
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        int n;
        scanf("%d", &n);

        printf("%d\n", go(n));
    }

    return 0;
}
