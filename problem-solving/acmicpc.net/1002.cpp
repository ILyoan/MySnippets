// baekjoon online judge 1002 (www.acmicpc.net/problem/1002)

#include <cstdio>

typedef long long i64;

int main() {
  // 테스트 케이스 수.
  int TC;
  scanf("%d", &TC);

  for (int tc = 1; tc <= TC; ++tc) {

    i64 x1, y1, r1; // 조규현의 위치와 조규현이 탐지한 류재명과의 거리.
    i64 x2, y2, r2; // 백승환의 위치와 백승환이 탐지한 류재명과의 거리.

    scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &r1, &x2, &y2, &r2);

    // 실수를 이용하여 계산하면 계산 오차가 발생할 수 있으므로 정수를 이용한다.
    // 계산 결과가 32비트 정수 범위를 벗어나므로 64비트 정수형을 사용한다.

    // 조규현과 백승환 사이의 거리(d)의 제곱.
    i64 d_square = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    // (조규현과 류재명의 사이의 거리 + 백승환과 류재명 사이의 거리) 의 제곱
    // (r1 + r2) * (r1 + r2) = r1 * r1 + r2 * r2 + 2 * r1 * r2
    i64 r1_plus_r2_square = (r1 * r1 + r2 * r2 + 2 * r1 * r2);

    // (조규현과 류재명의 사이의 거리 - 백승환과 류재명 사이의 거리) 의 제곱
    i64 r1_minus_r2_square = (r1 * r1 + r2 * r2 - 2 * r1 * r2);

    // 조규현과 류재명이 같은 점에 있는 경우,
    if (x1 == x2 && y1 == y2) {
      // 거리를 똑같이 탐지한 경우 무한대.
      if (r1 == r2) {
        printf("-1\n");
      }
      // 그렇지 않으면 불가능.
      else {
        printf("0\n");
      }
    }
    // 조규현과 류재명이 다른 점에 있는 경우,
    else {
      // r1 + r2 = d 이거나, r1 - r2 = d이면, 한 점.
      if (r1_plus_r2_square == d_square || r1_minus_r2_square == d_square) {
        printf("1\n");
      }
      // 한 점에서 만나지 않고, r1 - r2 > d 이거나, r1 + r2 < d 이면, 불가능.
      else if (r1_minus_r2_square > d_square || r1_plus_r2_square < d_square) {
        printf("0\n");
      }
      // 나머지 경우, 두 개의 교점이 있음.
      else {
        printf("2\n");
      }
    }

  }

  return 0;
}

