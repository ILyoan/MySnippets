// Codeforces 675/E Trains and Statistics
// [segment tree], [rmq], [update and query]

#include <cstdio>
typedef long long i64;

struct Node {
    int i;
    int ai;
    Node() : i(0), ai(0) {}
    Node(int i, int ai) : i(i), ai(ai) {}
};

int N;
int A[100001];
i64 S[100001];
Node T[500001];
Node None = Node(-1, -1);

int max(int a, int b) {
    return a > b ? a : b;
}

Node update(int i, int x, int idx, int l, int r) {
    if (l > i) return None;
    if (r <= i) return None;
    int len = r - l;
    if (len <= 0) return None;
    if (len == 1) return T[idx] = Node(i, x);
    Node res1 = update(i, x, idx * 2 + 0, l, l + len / 2);
    Node res2 = update(i, x, idx * 2 + 1, l + len / 2, r);
    if (T[idx].ai < res1.ai) T[idx] = res1;
    if (T[idx].ai < res2.ai) T[idx] = res2;
    return T[idx];
}

void update(int i, int x) {
    update(i, x, 1, 1, N + 1);
}

Node query(int ql, int qr, int idx, int l, int r) {
    if (l >= qr) return None;
    if (r <= ql) return None;
    int len = r - l;
    if (len <= 0) return None;
    if (ql <= l && qr >= r) return T[idx];
    Node res1 = query(ql, qr, idx * 2 + 0, l, l + len / 2);
    Node res2 = query(ql, qr, idx * 2 + 1, l + len / 2, r);
    return res1.ai > res2.ai ? res1 : res2;
}

Node query(int ql, int qr) {
    return query(ql, qr, 1, 1, N + 1);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    i64 ans = 0;
    update(N, N);
    for (int i = N - 1; i >= 1; --i) {
        int k = query(i, A[i] + 1).i;
        S[i] = S[k] - (A[i] - k) + (N - i);
        ans += S[i];
        update(i, A[i] + 1);
    }
    printf("%lld\n", ans);

    return 0;
}
