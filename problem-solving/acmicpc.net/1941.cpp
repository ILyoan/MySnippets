// baekjoon online judge 1941 (www.acmicpc.net/problem/1941)

// category: brute force, backtrack
// difficulty: easy

#include <cstdio>

const int N = 5;

char B[N + 1][N + 1];
bool V[N + 1][N + 1];
int answer = 0;

void dfs(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N) return;
    if (V[y][x] == false) return;
    V[y][x] = false;
    dfs(y  - 1, x);
    dfs(y  + 1, x);
    dfs(y, x - 1);
    dfs(y, x + 1);
}

bool verify(int bit) {
    int s = 0;
    for (int i = 0; i < N * N; ++i) {
        int y = i / N;
        int x = i % N;
        V[y][x] = bit & (1 << i);
        s += V[y][x] && B[y][x] == 'S';
    }
    if (s < 4) return false;
    int group = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (V[y][x]) {
                group++;
                dfs(y, x);
            }
        }
    }
    return group == 1;
}

void solve(int idx, int k, int bit) {
    if (k == 7) {
        if (verify(bit)) {
            answer += 1;
        }
    } else if (idx < N * N) {
        solve(idx + 1, k, bit);
        solve(idx + 1, k + 1, bit | (1 << idx));
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        scanf("%s", B[i]);
    }
    solve(0, 0, 0);
    printf("%d\n", answer);
    return 0;
}
