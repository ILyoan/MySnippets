// baekjoon online judge 2512 (www.acmicnum_primes.net/problem/2512)

#include <cstdio>

const int MAX_N = 10000;
const int MAX_V = 100000;

int budgets[MAX_N];

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &budgets[i]);
    }
    scanf("%d", &m);

    int low_bound = 0;
    int upper_bound = budgets[0];
    for (int i = 1; i < n; ++i) {
        if (upper_bound < budgets[i]) {
            upper_bound = budgets[i];
        }
    }
    int ans = 0;

    while (low_bound <= upper_bound) {
        int mid = (low_bound + upper_bound) / 2;

        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (budgets[i] < mid) {
                total += budgets[i];
            } else {
                total += mid;
            }
        }

        if (total <= m) {
            ans = mid;
            low_bound = mid + 1;
        } else {
            upper_bound = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
