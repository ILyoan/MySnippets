// baekjoon online judge 2842 (www.acmicnum_primes.net/problem/2842)

// Category: dfs
// Level: medium

#include <cstdio>

const int MAX_N = 50;
const int MAX_V = 1000000;

int N;
char M1[MAX_N + 1][MAX_N + 1];
int M2[MAX_N + 1][MAX_N + 1];
bool V[MAX_V + 1];
int A[MAX_N * MAX_N + 1];

int found;
bool visited[MAX_N + 1][MAX_N + 1];

void dfs(int y, int x, int lb, int ub) {
    if (visited[y][x]) return;
    visited[y][x] = true;

    if (M1[y][x] == 'K') {
        found++;
    }
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            int ny = y + dy;
            int nx = x + dx;
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (M2[ny][nx] < lb || M2[ny][nx] > ub) continue;
            dfs(ny, nx, lb, ub);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", M1[i]);
    }
    int max_h = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &M2[i][j]);
            V[M2[i][j]] = true;
            if (max_h < M2[i][j]) {
                max_h = M2[i][j];
            }
        }
    }

    int as = 0;
    for (int i = 0; i <= MAX_V; ++i) {
        if (V[i]) {
            A[as++] = i;
        }
    }

    int px, py;
    int houses = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (M1[y][x] == 'P') {
                py = y;
                px = x;
            } else if (M1[y][x] == 'K') {
                houses++;
            }
        }
    }

    int ans = 1000000000;
    for (int ai = 0; ai < as; ++ai) {
        int lb = ai;
        int ub = as - 1;
        while (lb <= ub) {
            int mid = (lb + ub) / 2;

            found = 0;
            if (M2[py][px] >= A[ai] && M2[py][px] <= A[mid]) {
                for (int y = 0; y < N; ++y) {
                    for (int x = 0; x < N; ++x) {
                        visited[y][x] = false;
                    }
                }
                dfs(py, px, A[ai], A[mid]);
            }

            if (found == houses) {
                int difficulty = A[mid] - A[ai];
                if (ans > difficulty) {
                    ans = difficulty;
                }
                ub = mid - 1;
            }
            else {
                lb = mid + 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
