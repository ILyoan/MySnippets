// acmicpc.net/problem/1031
// category : maxflow, maximum flow, ford fulkerson

#include <cstdio>
#include <memory.h>

int cap[105][105];
bool visit[105];

int A, B, N;
int Source, Sink;

bool augment(int x) {
    if (visit[x]) {
        return false;
    }
    visit[x] = true;

    if (x == Sink) {
        return true;
    }

    for (int y = 0; y < N; ++y) {
        if (cap[x][y] > 0) {
            if (augment(y)) {
                cap[x][y]--;
                cap[y][x]++;
                return true;
            }
        }
    }
    return false;
}

bool augment() {
    memset(visit, 0, sizeof(visit));
    augment(Source);
}

int flow() {
    int res = 0;
    while (augment()) {
        res++;
    }
    return res;
}

int main() {
    scanf("%d%d", &A, &B);
    
    Source = A + B;
    Sink = A + B + 1;
    N = A + B + 2;

    int sumA = 0;
    int sumB = 0;

    for (int a = 0; a < A; ++a) {
        scanf("%d", &cap[Source][a]);
        sumA += cap[Source][a];
    }
    for (int b = 0; b < B; ++b) {
        scanf("%d", &cap[A + b][Sink]);
        sumB += cap[A + b][Sink];
    }
    for(int a = 0; a < A; ++a) {
        for (int b = 0; b < B; ++b) {
            cap[a][A + b] = 1;
        }
    }
    if (sumA != sumB || flow() != sumA) {
        printf("-1\n");
    } else {
        for (int a = 0; a < A; ++a) {
            for (int b = 0; b < B; ++b) {
                bool unavoidable = false;
                if (cap[a][A + b] == 0) {
                    ++cap[Source][a];
                    ++cap[A + b][Sink];

                    if (!augment()) {
                        unavoidable = true;
                        --cap[A + b][Sink];
                        --cap[Source][a];
                    }
                }
                printf("%d", unavoidable);
                cap[a][A + b] = 0;
            }
            printf("\n");
        }
    }
    return 0;
}
