// baekjoon online judge 2573 (www.acmicpc.net/problem/2573)

#include <cstdio>

const int MAX_N = 300;

int N, M;
int map[MAX_N + 1][MAX_N + 1];
int map2[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M) return;
    if (map[y][x] <= 0) return;
    if (visited[y][x]) return;
    visited[y][x] = true;
    dfs(y + 1, x);
    dfs(y - 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            scanf("%d", &map[y][x]);
        }
    }

    int answer = 0;
    int year = 0;
    while (true) {
        bool allwater = true;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                visited[y][x] = false;
                if (map[y][x] > 0) {
                    allwater = false;
                }
            }
        }
        if (allwater) break;

        int count = 0;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (map[y][x] > 0 && !visited[y][x]) {
                    dfs(y, x);
                    count++;
                }
            }
        }
        if (count >= 2) {
            answer = year;
            break;
        }
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                int waters = 0;
                for (int d = 0; d < 4; ++d) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    waters += map[ny][nx] == 0;
                }
                map2[y][x] = map[y][x] - waters;
                if (map2[y][x] < 0) {
                    map2[y][x] = 0;
                }
            }
        }
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                map[y][x] = map2[y][x];
            }
        }
        year++;
    }

    printf("%d\n", answer);

    return 0;
}