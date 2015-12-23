// baekjoon online judge 2178 (www.acmicnum_primes.net/problem/2178)

// Category: BFS, shortest path.
// Level: Pupil.

#include <cstdio>

const int MAX_N = 100000;
const int MAX_RANGE = 2 * MAX_N + 1;

struct Queue {
    Queue() : head(0), tail(0) {}

    void init() {
        head = 0;
        tail = 0;
    }

    void push(int x) {
        container[tail++] = x;
    }

    bool isEmpty() {
        return head == tail;
    }

    int size() {
        return tail - head;
    }

    int top() {
        return container[head];
    }

    int pop() {
        return container[head++];
    }

    int head;
    int tail;
    int container[MAX_RANGE];
};

int N, M;
Queue queue;

bool visited[MAX_RANGE];

void pushQueue(int x) {
    if (x >= 0 && x < MAX_RANGE && !visited[x]) {
        queue.push(x);
        visited[x] = true;
    }
}

int findTime(int n, int m) {
    int time = 0;
    queue.push(n);
    while (!queue.isEmpty()) {
        int queue_size = queue.size();
        while (queue_size--) {
            int x = queue.pop();
            if (x == m) {
                return time;
            }
            pushQueue(x - 1);
            pushQueue(x + 1);
            pushQueue(2 * x);
        }
        time += 1;
    }
    return -1;
}

int main() {
    scanf("%d%d", &N, &M);
    printf("%d\n", findTime(N, M));

    return 0;
}
