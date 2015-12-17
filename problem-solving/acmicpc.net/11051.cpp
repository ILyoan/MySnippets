// baekjoon online judge 11051 (www.acmicpc.net/problem/11051)

#include <cstdio>

const int MOD = 10007;

int combi[1001][1001];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    combi[0][0] = 1;
    for (int i = 1; i <=n; ++i) {
        combi[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % MOD;
        }
    }

    printf("%d\n", combi[n][k]);

    return 0;
}
