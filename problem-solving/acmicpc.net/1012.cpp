// baekjoon online judge 1012 (www.acmicpc.net/problem/1012)

// Category: dfs
// Difficulty: pupil

#include <cstdio>

const int MAX_N = 50;
const int MAX_K = 2500;

int Y, X, K;
bool Map[MAX_N + 1][MAX_N + 1];

void dfs(int y, int x) {
  if (y < 0 || y >= Y || x < 0 || x >= X) return;
  if (!Map[y][x]) return;
  Map[y][x] = false;
  dfs(y + 1, x);
  dfs(y - 1, x);
  dfs(y, x + 1);
  dfs(y, x - 1);
}

int main() {
  int TC;
  scanf("%d", &TC);

  for (int tc = 1; tc <= TC; ++tc) {
    scanf("%d%d%d", &Y, &X, &K);
    for (int y = 0; y < Y; ++y) {
      for (int x = 0; x < X; ++x) {
        Map[y][x] = false;
      }
    }
    for (int i = 0; i < K; ++i) {
      int y, x;
      scanf("%d%d", &y, &x);
      Map[y][x] = true;
    }
    int answer = 0;
    for (int y = 0; y < Y; ++y) {
      for (int x = 0; x < X; ++x) {
        if (Map[y][x]) {
          dfs(y, x);
          answer++;
        }
      }
    }
    printf("%d\n", answer);
  }

  return 0;
}
