// baekjoon online judge 7576 (www.acmicpc.net/problem/7576)

// Category: BFS
// Difficulty: Pupil

#include <stdio.h>

const int MAX_N = 1000;
const int MAX_QUEUE_SIZE = MAX_N * MAX_N + 1;

struct Point {
    int y;
    int x;
};

Point queue[MAX_QUEUE_SIZE];
bool tomato[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1][MAX_N + 1];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    int X, Y;
    scanf("%d%d", &X, &Y);

    int head = 0;
    int tail = 0;
    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            int a;
            scanf("%d", &a);
            tomato[y][x] = a != -1;
            if (a == 1) {
                Point start;
                start.y = y;
                start.x = x;
                queue[tail++] = start;
                visited[start.y][start.x] = true;
            }
        }
    }
    int step = 0;
    while (tail > head) {
        int queue_size = tail - head;
        while (queue_size--) {
            Point p = queue[head++];
            for (int d = 0; d < 4; ++d) {
                Point next;
                next.y = p.y + dy[d];
                next.x = p.x + dx[d];
                if (next.y < 0 || next.y >= Y || next.x < 0 || next.x >= X) {
                    continue;
                }
                if (!tomato[next.y][next.x]) {
                    continue;
                }
                if (!visited[next.y][next.x]) {
                    queue[tail++] = next;
                    visited[next.y][next.x] = true;
                }
            }
        }
        step++;
    }
    int res = step - 1;
    for (int y = 0; y < Y; ++y) {
        for (int x = 0; x < X; ++x) {
            if (tomato[y][x] && !visited[y][x]) {
                res = -1;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
