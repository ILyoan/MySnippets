// baekjoon online judge 2309 (www.acmicnum_primes.net/problem/2309)

#include <cstdio>

const int N = 9;
const int TOTAL = 100;
const int TARGET = 7;

int dwarfs[N];
bool choose[N];

void go(int idx, int count, int remains) {
    if (count == TARGET && remains == 0) {
        for (int i = 0; i < N; ++i) {
            if (choose[i]) {
                printf("%d\n", dwarfs[i]);
            }
        }
        return;
    }

    if (idx >= N || remains < 0) {
        return;
    }

    choose[idx] = true;
    go(idx + 1, count + 1, remains - dwarfs[idx]);
    choose[idx] = false;
    go(idx + 1, count, remains);
}

int main() {
    for (int i = 0; i < N; ++i) {
        scanf("%d", &dwarfs[i]);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (dwarfs[i] > dwarfs[j]) {
                int t = dwarfs[i];
                dwarfs[i] = dwarfs[j];
                dwarfs[j] = t;
            }
        }
    }

    go(0, 0, TOTAL);

    return 0;
}
