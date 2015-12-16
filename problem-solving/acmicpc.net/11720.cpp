// baekjoon online judge 11720 (www.acmicpc.net/problem/11720)

#include <cstdio>

int main() {
  int n;
  char nums[101];
  scanf("%d%s", &n, nums);

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i] - '0';
  }

  printf("%d\n", sum);

  return 0;
}
