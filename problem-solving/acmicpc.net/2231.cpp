// baekjoon online judge 2231 (www.acmicnum_primes.net/problem/2231)

// Category: brute force
// Level: Pupil.

#include <cstdio>

int sum(int n) {
    int ans = n;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);

    int num = 1;
    int ans = 0;
    while (num <= N) {
        if (sum(num) == N) {
            ans = num;
            break;
        }
        num += 1;
    }

    printf("%d\n", ans);

    return 0;
}
