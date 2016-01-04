// baekjoon online judge 1463 (www.acmicnum_primes.net/problem/1463)

// Category: BFS
// Level: Pupil.

#include <cstdio>

const int MAX_N = 1000000;

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
    int container[MAX_N + 1];
};

Queue queue;
bool visited[MAX_N + 1];

int solve(int n) {
    int step = 0;

    queue.push(n);
    visited[n] = true;

    while (!queue.isEmpty()) {
        int queue_size = queue.size();
        for (int i = 0; i < queue_size; ++i) {
            int x = queue.pop();
            if (x == 1) {
                return step;
            }
            if (x % 2 == 0 && !visited[x / 2]) {
                queue.push(x / 2);
                visited[x / 2] = true;
            }
            if (x % 3 == 0 && !visited[x / 3]) {
                queue.push(x / 3);
                visited[x / 3] = true;
            }
            if (!visited[x - 1]) {
                queue.push(x - 1);
                visited[x - 1] = true;
            }
        }
        step += 1;
    }

    return -1;
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", solve(N));

    return 0;
}
