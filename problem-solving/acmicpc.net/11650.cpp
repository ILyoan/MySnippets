// baekjoon online judge 11650 (www.acmicpc.net/problem/11650)

#include <cstdio>

const int MAXN = 1000000;

struct Point {
    int x;
    int y;
};

Point A[MAXN + 1];
Point B[MAXN + 1];

void merge(int begin, int end) {
    int mid = (begin + end) / 2;

    int p = begin;
    int q = mid;
    int r = begin;

    while (p < mid && q < end) {
        if (A[p].x < A[q].x || A[p].x == A[q].x && A[p].y < A[q].y) {
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

void merge_sort(int begin, int end) {
    if (begin >= end - 1) {
        return;
    }

    int mid = (begin + end) / 2;

    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, end);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &A[i].x, &A[i].y);
    }

    merge_sort(0, n);

    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", A[i].x, A[i].y);
    }

    return 0;
}
