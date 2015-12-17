// baekjoon online judge 11653 (www.acmicpc.net/problem/11653)

#include <cstdio>

// prime_factor[i] is a smallest prime number that divides i.
int prime_factor[10000001];

int main() {
    int n;
    scanf("%d", &n);

    prime_factor[0] = 0;
    prime_factor[1] = 0;

    for (int i = 2; i <= n; ++i) {
        prime_factor[i] = i;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (prime_factor[i] == i) {
            prime_factor[i] = i;
            for (int j = i * i; j <= n; j += i) {
                if (prime_factor[j] == j) {
                    prime_factor[j] = i;
                }
            }
        }
    }

    while (n > 1) {
        printf("%d\n", prime_factor[n]);
        n = n / prime_factor[n];
    }

    return 0;
}
