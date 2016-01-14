// baekjoon online judge 9019 (www.acmicpc.net/problem/9019)

// Category: BFS
// Difficulty: Easy

#include <stdio.h>

const int MAX_N = 10000;


int queue[MAX_N + 1];
int from[MAX_N + 1];
char cmds[MAX_N + 1];

void print_command(int k) {
    if (from[k] != k) {
        print_command(from[k]);
        putchar(cmds[k]);
    }

}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int a, b;
        scanf("%d%d", &a, &b);

        for (int i = 0; i < MAX_N; ++i) {
            cmds[i] = 0;
            from[i] = -1;
        }

        int head = 0;
        int tail = 0;
        int step = 0;
        queue[tail++] = a;
        from[a] = a;
        while (head < tail) {
            int k = queue[head++];

            if (k == b) {
                print_command(k);
                putchar('\n');
                break;
            }

            int next_d = (2 * k) % MAX_N;
            if (from[next_d] < 0) {
                queue[tail++] = next_d;
                cmds[next_d] = 'D';
                from[next_d] = k;
            }

            int next_s = k == 0 ? 9999 : k - 1;
            if (from[next_s] < 0) {
                queue[tail++] = next_s;
                cmds[next_s] = 'S';
                from[next_s] = k;
            }

            int next_l = (k * 10 + k / 1000) % MAX_N;
            if (from[next_l] < 0) {
                queue[tail++] = next_l;
                cmds[next_l] = 'L';
                from[next_l] = k;
            }

            int next_r = k / 10 + 1000 * (k % 10);
            if (from[next_r] < 0) {
                queue[tail++] = next_r;
                cmds[next_r] = 'R';
                from[next_r] = k;
            }
        }
    }

    return 0;
}
