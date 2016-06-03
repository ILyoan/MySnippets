// Educational Codeforces Round 5 E.Sum of Remainders (616/E)
// [math], [pow]

#include <cstdio>

typedef long long i64;

const i64 MOD = 1000000007;

i64 pow(i64 a, i64 b) {
  if (b == 0) return 1;
  i64 p = pow(a, b / 2);
  i64 res = (p * p) % MOD;
  if (b & 1) {
    res = (res * a) % MOD;
  }
  return res;
}

i64 solve_direct(i64 n, i64 m) {
  i64 res = 0;
  for (int i = 1; i <= m; ++i) {
    res = (res + n % i) % MOD;
  }
  return res;
}

i64 solve(i64 n, i64 m) {
  if (n < m) {
    return solve(n, n) + (((m - n) % MOD) * (n % MOD)) % MOD;
  }
  i64 inv2 = pow(2, MOD - 2);
  i64 p = n / m;
  i64 q = n % m;
  i64 x = (m - q - 1) / (p + 1) + 1;
  i64 res = 0;
  while (m > 1000000 && x > 1) {
    i64 xm = x % MOD;
    i64 pm = p % MOD;
    i64 qm = q % MOD;
    i64 s = (qm * xm) % MOD + ((((pm * xm) % MOD * ((xm - 1 + MOD) % MOD)) % MOD) * inv2) % MOD;
    res = (res + s) % MOD;
    m = m - x;
    p = p + 1;
    q = n % m;
    x = (m - q - 1) / (p + 1) + 1;
  }
  return (res + solve_direct(n, m)) % MOD;
}

int main() {
  i64 n, m;
  scanf("%lld%lld", &n, &m);
  printf("%lld\n", solve(n, m));
  return 0;
}
