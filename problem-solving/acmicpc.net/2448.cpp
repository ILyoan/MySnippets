// baekjoon online judge 2448 (www.acmicnum_primes.net/problem/2448)

#include <cstdio>

const int MAX_N = 3 * 1024;

const char TEMPLATE[3][6] = {
    "  *  ",
    " * * ",
    "*****",
};

char B[MAX_N + 1][2 * MAX_N + 1];



void fillStar(int n, int y, int x) {
    if (n == 3) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                B[i + y][j + x] = TEMPLATE[i][j];
            }
        }
        return ;
    }
    int m = n / 2;
    fillStar(m, y, x + m);
    fillStar(m, y + m, x);
    fillStar(m, y + m, x + m + m);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n; ++j) {
            B[i][j] = ' ';
        }
    }

    fillStar(n, 0, 0);

    for (int i = 0; i < n; ++i) {
        printf("%s\n", B[i]);
    }
}
