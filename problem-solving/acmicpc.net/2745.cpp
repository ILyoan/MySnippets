// baekjoon online judge 2745 (www.acmicpc.net/problem/2745)

#include <cstdio>

int toDecDigit(char hex) {
  if (hex >= '0' && hex <='9') {
    return hex - '0';
  } else {
    return hex - 'A' + 10;
  }
}

int main() {
  char n[40];
  int b;
  scanf("%s%d", n, &b);

  int num = 0;

  for (int i = 0; n[i]; ++i) {
    num = num * b + toDecDigit(n[i]);
  }

  printf("%d\n", num);

  return 0;
}

