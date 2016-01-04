// baekjoon online judge 2526 (www.acmicnum_primes.net/problem/2526)

// Level: Pupil.

#include <cstdio>

const int MAX_N = 1000;

int mem[MAX_N + 1];

int getNext(int x, int n, int p) {
    return (x * n) % p;
}

int main() {
    int N, P;
    scanf("%d%d", &N, &P);

    int x = N;
    int count = 1;
    while (mem[x] == 0) {
        mem[x] = count;
        x = getNext(x, N, P);
        count += 1;
    }

    printf("%d\n", count - mem[x]);

    return 0;
}
