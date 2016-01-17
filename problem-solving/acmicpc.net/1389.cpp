// baekjoon online judge 1389 (www.acmicpc.net/problem/1389)

#include <cstdio>

const int MAX_N = 100;
const int INF = 1000000000;

int V, E;
int D[MAX_N + 1][MAX_N + 1];

int main() {
    scanf("%d%d", &V, &E);
    for (int u = 1; u <= V; ++u) {
        for (int v = 1; v <= V; ++v) {
            D[u][v] = INF;
        }
    }
    for (int i = 0; i < E; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        D[u][v] = D[v][u] = 1;
    }

    for (int k = 1; k <= V; ++k) {
        for (int u = 1; u <= V; ++u) {
            for (int v = 1; v <= V; ++v) {
                if (D[u][v] > D[u][k] + D[k][v]) {
                    D[u][v] = D[u][k] + D[k][v];
                }
            }
        }
    }

    int answer = 0;
    int min = INF;
    for (int u = 1; u <= V; ++u) {
        int sum = 0;
        for (int v = 1; v <= V; ++v) {
            if (u == v) continue;
            sum += D[u][v];
        }
        if (min > sum) {
            min = sum;
            answer = u;
        }
    }

    printf("%d\n", answer);

    return 0;
}
