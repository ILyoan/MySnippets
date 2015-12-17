// baekjoon online judge 1929 (www.acmicpc.net/problem/1929)

#include <cstdio>

bool is_not_prime[1000001];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    is_not_prime[0] = true;
    is_not_prime[1] = true;

    for (int i = 2; i * i <= n; ++i) {
        if (!is_not_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_not_prime[j] = true;
            }
        }
    }

    int count = 0;
    for (int i = m; i <= n; ++i) {
        if (!is_not_prime[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
