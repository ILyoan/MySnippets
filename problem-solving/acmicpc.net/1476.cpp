// baekjoon online judge 1476 (www.acmicnum_primes.net/problem/1476)

// Category: brute force
// Level: Pupil.

#include <cstdio>

int main() {
    int E, S, M;
    scanf("%d%d%d", &E, &S, &M);

    int year = 1;
    int e = 1;
    int s = 1;
    int m = 1;
    while (e != E || s != S || m != M) {
        e += 1;
        if (e > 15) {
            e = 1;
        }
        s += 1;
        if (s > 28) {
            s = 1;
        }
        m += 1;
        if (m > 19) {
            m = 1;
        }
        year += 1;
    }
    printf("%d\n", year);

    return 0;
}
