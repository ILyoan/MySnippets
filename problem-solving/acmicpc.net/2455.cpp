// baekjoon online judge 2455 (www.acmicnum_primes.net/problem/2455)

// Category: Implementation
// Level: Pupil

#include <cstdio>


int main() {
    int ans = 0;
    int passanger = 0;
    for (int station = 1; station <= 4; ++station) {
        int off, on;
        scanf("%d%d", &off, &on);

        passanger -= off;
        passanger += on;

        if (ans < passanger) {
            ans = passanger;
        }
    }

    printf("%d\n", ans);

    return 0;
}
