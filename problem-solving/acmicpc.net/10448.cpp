// baekjoon online judge 10448 (www.acmicnum_primes.net/problem/10448)

// Category: brute force
// Level: pupil

#include <cstdio>

const int MAX_K = 1000;

int TN[MAX_K]; // triangle numbers
int nTN; // number of triangle numbers

bool isEurekaNum(int n) {
   for (int i = 0; i < nTN; ++i) {
        for (int j = 0; j < nTN; ++j) {
            for (int k = 0; k < nTN; ++k) {
                if (TN[i] + TN[j] + TN[k] == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    // calculate triangle numbers
    for (int i = 1, sum = 1; sum <= MAX_K; ++i, sum += i) {
        TN[nTN++] = sum;
    }

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        int n;
        scanf("%d", &n);
        printf("%d\n", isEurekaNum(n));
    }
    return 0;
}
