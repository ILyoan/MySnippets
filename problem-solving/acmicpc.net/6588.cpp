// baekjoon online judge 6588 (www.acmicpc.net/problem/6588)

#include <cstdio>

const int MAX_N = 1000000;

bool not_prime[MAX_N + 1];

int main() {
    not_prime[0] = true;
    not_prime[1] = true;
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (!not_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                not_prime[j] = true;
            }
        }
    }

    int n;
    while (scanf("%d", &n) > 0) {
        if (n == 0) break;
        for (int i = 3; i <= n; i += 2) {
            if (!not_prime[i] && !not_prime[n - i]) {
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }
    }

    return 0;
}