// baekjoon online judge 11728 (www.acmicpc.net/problem/11728)

#include <cstdio>

int A[1000001];
int B[1000001];
int C[2000001];

void merge(int A[], int B[], int C[], int alen, int blen) {
    int ai = 0;
    int bi = 0;
    int ci = 0;

    while (ai < alen && bi < blen) {
        if (A[ai] < B[bi]) {
            C[ci++] = A[ai++];
        } else {
            C[ci++] = B[bi++];
        }
    }
    while (ai < alen) {
        C[ci++] = A[ai++];
    }
    while (bi < blen) {
        C[ci++] = B[bi++];
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &B[i]);
    }

    merge(A, B, C, n, m);

    for (int i = 0; i < n + m; ++i) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}