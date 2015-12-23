// baekjoon online judge 7562 (www.acmicnum_primes.net/problem/7562)

// Category: BFS, shortest path.
// Level: Pupil.

#include <cstdio>

const int MAX_L = 300;

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
    Point container[MAX_L * MAX_L + 1];
};

int L;
Queue queue;
bool visited[MAX_L + 1][MAX_L + 1];

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int findSteps(Point start, Point dest) {
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            visited[i][j] = false;
        }
    }
    queue.init();

    int step = 0;

    queue.push(start);
    visited[start.y][start.x] = true;

    while (!queue.isEmpty()) {
        int queue_size = queue.size();
        while (queue_size-- > 0) {
            Point point = queue.pop();

            if (point.x == dest.x && point.y == dest.y) {
                return step;
            }

            for (int k = 0; k < 8; ++k) {
                int nx = point.x + dx[k];
                int ny = point.y + dy[k];
                if (nx >= 0 && nx < L && ny >= 0 && ny < L && !visited[ny][nx]) {
                    Point next;
                    next.x = nx;
                    next.y = ny;

                    queue.push(next);

                    visited[ny][nx] = true;
                }
            }

        }
        step += 1;
    }
    return -1;
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%d", &L);

        Point start, dest;
        scanf("%d%d", &start.x, &start.y);
        scanf("%d%d", &dest.x, &dest.y);

        printf("%d\n", findSteps(start, dest));
    }

    return 0;
}
