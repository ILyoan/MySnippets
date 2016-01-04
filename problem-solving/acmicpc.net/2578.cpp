// baekjoon online judge 2578 (www.acmicnum_primes.net/problem/2578)

// Category: implementation
// Level: pupil

#include <cstdio>

int A[5][5];

void eraseNumber(int n) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (A[i][j] == n) {
                A[i][j] = 0;
            }
        }
    }
}

int getLines() {
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        bool ok = true;
        for (int j = 0; j < 5; ++j) {
            if (A[i][j] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans += 1;
        }
    }
    for (int i = 0; i < 5; ++i) {
        bool ok = true;
        for (int j = 0; j < 5; ++j) {
            if (A[j][i] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans += 1;
        }
    }
    bool ok1 = true;
    bool ok2 = true;
    for (int i = 0; i < 5; ++i) {
        if (A[i][i] != 0) {
            ok1 = false;
        }
        if (A[i][4-i] != 0) {
            ok2 = false;
        }
    }
    if (ok1) {
        ans += 1;
    }
    if (ok2) {
        ans += 1;
    }
    return ans;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    int ans = -1;
    for (int i = 1; i <= 25; ++i) {
        int n;
        scanf("%d", &n);
        eraseNumber(n);
        if (ans == -1 && getLines() >= 3) {
            ans = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}
