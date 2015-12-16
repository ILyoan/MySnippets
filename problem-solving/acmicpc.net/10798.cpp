// baekjoon online judge 10798 (www.acmicpc.net/problem/10798)

#include <cstdio>

char lines[5][16];

int main() {
  // initialize array.
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 15; ++j) {
      lines[i][j] = 0;
    }
  }

  // take input.
  for (int i = 0; i < 5; ++i) {
    scanf("%s", lines[i]);
  }

  // print in vertical order.
  for (int col = 0; col < 15; ++col) {
    for (int row = 0; row < 5; ++row) {
      if (lines[row][col]) {
        printf("%c", lines[row][col]);
      }
    }
  }
  printf("\n");

  return 0;
}

