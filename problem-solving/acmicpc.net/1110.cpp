// baekjoon online judge 1110 (www.acmicpc.net/problem/1110)

#include <cstdio>

int next(int n) {
  return n % 10 * 10 + (n % 10 + n / 10) % 10;
}

int main() {
  int n;
  scanf("%d", &n);

  int k = n;
  int count = 1;
  while ((k = next(k)) != n) {
    count++;
  }

  printf("%d\n", count);

  return 0;
}
