// baekjoon online judge 10989 (www.acmicpc.net/problem/10989)

#include <cstdio>

const int MAX_VALUE = 10000;

int count[MAX_VALUE + 1];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);

        count[x] += 1;
    }

    for (int i = 1; i <= MAX_VALUE; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            printf("%d\n", i);
        }
    }

    return 0;
}
