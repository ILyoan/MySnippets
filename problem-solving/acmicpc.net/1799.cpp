// baekjoon online judge 1799 (www.acmicnum_primes.net/problem/1799)

#include <cstdio>

const int MAX_N = 10;

int N;
int B[MAX_N][MAX_N];

int dy[] = { 1, -1, -1, 1};
int dx[] = { 1, 1, -1, -1};

bool diag_used[MAX_N * 2];

int ans = 0;
void go(int diag, int bishops, int expected) {
    if (ans < bishops) {
        ans = bishops;
    }
    if (diag >= 2 * N - 1) {
        return;
    }
    if (expected <= ans) {
        return;
    }


    int ret = 0;

    int y = diag - N + 1;
    if (y < 0) {
        y = 0;
    }
    int x = diag - y;

    while (x >= 0 && y < N) {
        if (B[y][x] == 1 && diag_used[x - y + N] == false) {
            diag_used[x - y + N] = true;
            go(diag + 1, bishops + 1, expected);
            diag_used[x - y + N] = false;
        }
        y += 1;
        x -= 1;
    }

    go(diag + 1, bishops, expected - 1);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &B[i][j]);
        }
    }

    ans = 0;
    go(0, 0, 2 * N - 2);

    printf("%d\n", ans);


    return 0;
}
