// baekjoon online judge 7568 (www.acmicpc.net/problem/7568)

#include <cstdio>

const int MAX_N =50;

int N;
int X[MAX_N + 1];
int Y[MAX_N + 1];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &X[i], &Y[i]);
    }

    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (X[i] < X[j] && Y[i] < Y[j]) {
                count += 1;
            }
        }
        printf("%d ", count + 1);
    }
    printf("\n");

    return 0;
}
