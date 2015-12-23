// baekjoon online judge 2178 (www.acmicnum_primes.net/problem/2178)

// Category: BFS, shortest path.
// Level: Pupil.

#include <cstdio>

const int MAX_N = 100;

int N, M;
char A[MAX_N + 1][MAX_N + 1];

struct Point {
    int x;
    int y;
};

struct Queue {
    Queue() : head(0), tail(0) {}

    void init() {
        head = 0;
        tail = 0;
    }

    void push(Point p) {
        container[tail++] = p;
    }

    bool isEmpty() {
        return head == tail;
    }

    int size() {
        return tail - head;
    }

    Point top() {
        return container[head];
    }

    Point pop() {
        return container[head++];
    }

    int head;
    int tail;
    Point container[MAX_N * MAX_N + 1];
};

Queue queue;
bool visited[MAX_N + 1][MAX_N + 1];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int solve(Point start, Point end) {
    queue.push(start);
    visited[start.y][start.x] = true;

    int dist = 1;

    while (!queue.isEmpty()) {
        int queue_size = queue.size();
        while (queue_size-- > 0) {
            Point point = queue.pop();

            if (point.y == end.y && point.x == end.x) {
                return dist;
            }

            for (int k = 0; k < 4; ++k) {
                int ny = point.y + dy[k];
                int nx = point.x + dx[k];

                if (ny >= 0 && ny < N && nx >= 0 && nx < M && A[ny][nx] == '1' && !visited[ny][nx]) {
                    Point next;
                    next.y = ny;
                    next.x = nx;
                    queue.push(next);
                    visited[ny][nx] = true;
                }
            }
        }
        dist += 1;
    }

    return -1;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%s", A[i]);
    }

    Point start, end;
    start.y = 0;
    start.x = 0;
    end.y = N - 1;
    end.x = M - 1;

    printf("%d\n", solve(start, end));

    return 0;
}
