// baekjoon online judge 1339 (www.acmicpc.net/problem/1339)

// category: brute force
// difficulty: easy

#include <cstdio>

const int MAX_N = 10;
const int MAX_LENGTH = 8;

int N;
char S[MAX_N + 1][MAX_LENGTH + 1];
bool appear[26];
int assign[26];
bool assigned[10];

int max(int a, int b) { return a > b ? a : b; }

int eval() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int n = 0;
        for (int j = 0; S[i][j]; ++j) {
            n = n * 10 + assign[S[i][j] - 'A'];
        }
        sum += n;
    }
    return sum;
}

int answer = 0;
int solve(char digit) {
    if (digit > 'Z') {
        return eval();
    } else {
        int res = 0;
        if (appear[digit - 'A']) {
            for (int i = 0; i <= 9; ++i) {
                if (!assigned[i]) {
                    assigned[i] = true;
                    assign[digit - 'A'] = i;
                    res = max(res, solve(digit + 1));
                    assigned[i] = false;
                }
            }
        } else {
            res = solve(digit + 1);
        }
        return res;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", S[i]);
        for (int j = 0; S[i][j]; ++j) {
            appear[S[i][j] - 'A'] = true;
        }
    }
    printf("%d\n", solve('A'));

    return 0;
}
