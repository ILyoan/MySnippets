// baekjoon online judge 1644 (www.acmicnum_primes.net/problem/1644)

#include <cstdio>

const int MAX_N = 4000000;

bool is_not_prime[MAX_N + 1];
int prime_numbers[MAX_N + 1];

int main() {
  int n;
  scanf("%d", &n);

  int num_primes = 0;
  is_not_prime[0] = is_not_prime[1] = true;
  for (int i = 2; i * i <= n; ++i) {
    if (!is_not_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_not_prime[j] = true;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (!is_not_prime[i]) {
      prime_numbers[num_primes++] = i;
    }
  }

  int l = 0;
  int r = 0;
  int sum = 0;
  int cnt = 0;
  while (r <= num_primes) {
    if (sum < n) {
      sum += prime_numbers[r++];
    } else {
      cnt += sum == n;
      sum -= prime_numbers[l++];
    }
  }

  printf("%d\n", cnt);
  return 0;
}