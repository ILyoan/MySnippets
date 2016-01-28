// baekjoon online judge 3085 (www.acmicpc.net/problem/3085)

// Category: brute force
// Difficulty: easy

#include <cstdio>

const int MAX_N = 50;

int N;
char B[MAX_N + 1][MAX_N + 1];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int max(int a, int b) { return a > b ? a : b; }

void swap(int y1, int x1, int y2, int x2) {
    char t = B[y1][x1];
    B[y1][x1] = B[y2][x2];
    B[y2][x2] = t;
}

int count() {
    int res = 1;
    for (int y = 0; y < N; ++y) {
        int cnt = 1;
        for (int x = 1; x < N; ++x) {
            if (B[y][x] == B[y][x - 1]) {
                cnt++;
                res = max(res, cnt);
            } else {
                cnt = 1;
            }
        }
    }
    for (int x = 0; x < N; ++x) {
        int cnt = 1;
        for (int y = 1; y < N; ++y) {
            if (B[y][x] == B[y - 1][x]) {
                cnt++;
                res = max(res, cnt);
            } else {
                cnt = 1;
            }
        }
    }
    return res;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", B[i]);
    }
    int answer = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            for (int k = 0; k < 4; ++k) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (B[y][x] == B[ny][nx]) continue;
                swap(y, x, ny, nx);
                answer = max(answer, count());
                swap(y, x, ny, nx);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
