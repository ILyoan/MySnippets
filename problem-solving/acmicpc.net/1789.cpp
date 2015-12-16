// baekjoon online judge 1789 (www.acmicpc.net/problem/1789)

#include <cstdio>

typedef long long i64;

int main() {
  i64 s;
  scanf("%lld", &s);

  i64 sum = 0;
  i64 k = 0;
  while (sum <= s) {
    k++;
    sum += k;
  }

  printf("%lld\n", k - 1);

  return 0;
}

