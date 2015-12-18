// baekjoon online judge 11652 (www.acmicpc.net/problem/11652)

#include <cstdio>

typedef long long i64;

const int MAXN = 1000000;

i64 A[MAXN + 1];
i64 B[MAXN + 1];

void merge(int begin, int end) {
    int mid = (begin + end) / 2;

    int p = begin;
    int q = mid;
    int r = begin;

    while (p < mid && q < end) {
        if (A[p] < A[q]) {
            B[r++] = A[p++];
        } else {
            B[r++] = A[q++];
        }
    }
    while (p < mid) {
        B[r++] = A[p++];
    }
    while (q < end) {
        B[r++] = A[q++];
    }

    for (int i = begin; i < end; ++i) {
        A[i] = B[i];
    }
}

void mergeSort(int begin, int end) {
    if (begin >= end - 1) {
        return;
    }

    int mid = (begin + end) / 2;

    mergeSort(begin, mid);
    mergeSort(mid, end);
    merge(begin, end);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &A[i]);
    }

    mergeSort(0, n);

    i64 most_appear = A[0];
    i64 most_appear_count = 1;
    i64 current_count = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i] == A[i - 1]) {
            current_count += 1;
        } else {
            if (most_appear_count < current_count) {
                most_appear_count = current_count;
                most_appear = A[i - 1];
            }
            current_count = 1;
        }
    }

    if (most_appear_count < current_count) {
        most_appear = A[n - 1];
    }

    printf("%lld\n", most_appear);

    return 0;
}
