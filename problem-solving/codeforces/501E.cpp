// codeforces round #284 (Div. 2) E. Misha and Palindrome Degree (501/E)
// [palindrome], [sliding window]

#include <cstdio>

typedef long long i64;

const int MAX_N = 100000;

int N;
int A[MAX_N + 1];
int C[MAX_N + 1];


int min(int a, int b) { return a < b ? a : b; }

bool isPalindrome() {
  int i = 0;
  int j = N - 1;

  while (i <= j && A[i] == A[j]) {
    ++i;
    --j;
  }

  return i > j;
}


struct Result {
  Result() : ok(false) {}
  Result(int left, int right) : ok(true), left(left), right(right) {}
  bool ok;
  int left;
  int right;
};

Result solve() {
  int i = 0;
  int j = N - 1;

  for (int i = 1; i <= N; ++i) {
    C[i] = 0;
  }

  while (i <= j && A[i] == A[j]) {
    ++i;
    --j;
  }

  int left = i;
  int right = j;
  int miss_matches = 0;

  while (i <= j) {
    while (i <= j && C[A[j]] == 0) {
      C[A[i]] += 1;
      miss_matches += 1;
      ++i;
    }

    right = i - 1;

    if (i > j) {
      break;
    }

    while (i <= j && C[A[j]] > 0) {
      C[A[j]] -= 1;
      miss_matches -= 1;
      --j;
    }

    if (miss_matches == 0) {
      while (i <= j && A[i] == A[j]) {
        ++i;
        --j;
      }
    }
  }

  int odds = 0;
  for (int i = 1; i <= N; ++i) {
    if (C[i] & 1) {
      odds += 1;
    }
  }

  if (odds > ((N & 1) ? 1 : 0)) {
    return Result();
  } else {
    return Result(left + 1, N - right);
  }
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }

  if (isPalindrome()) {
    printf("%lld\n", (i64)N * (N + 1) / 2);
  } else {
    Result res1 = solve();

    for (int i = 0, j = N - 1; i < j; ++i, --j) {
      int t = A[i];
      A[i] = A[j];
      A[j] = t;
    }

    Result res2 = solve();

    i64 ans = 0;
    if (res1.ok) {
      ans += (i64)res1.left * res1.right;
    }
    if (res2.ok) {
      ans += (i64)res2.left * res2.right;
    }
    if (res1.ok && res2.ok) {
      ans -= (i64)res1.left * res2.left;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
