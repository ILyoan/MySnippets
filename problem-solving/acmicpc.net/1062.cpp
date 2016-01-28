// baekjoon online judge 1062 (www.acmicpc.net/problem/1062)

// Category: brute force
// Difficulty: easy

#include <cstdio>

const int MAX_N = 50;
const int MAX_K = 26;
const int MAX_LEN = 15;

int N, K;
char words[MAX_N + 1][MAX_LEN + 1];
bool teach[26];

int max(int a, int b) { return a > b ? a : b; }

int solve(char ch, int k) {
    if (k < 0) {
        return 0;
    }
    if (ch > 'z') {
        int res = 0;
        for (int i = 0; i < N; ++i) {
            bool ok = true;
            for (int j = 0; words[i][j]; ++j) {
                if (!teach[words[i][j] - 'a']) {
                    ok = false;
                    break;
                }
            }
            res += ok;
        }
        return res;
    }
    int res = 0;
    if (ch == 'a' || ch == 'n' || ch == 't' || ch == 'i' || ch == 'c') {
        teach[ch - 'a'] = true;
        res = max(res, solve(ch + 1, k - 1));
    } else {
        teach[ch - 'a'] = true;
        res = max(res, solve(ch + 1, k - 1));
        teach[ch - 'a'] = false;
        res = max(res, solve(ch + 1, k));
    }
    return res;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s", words[i]);
    }
    printf("%d\n", solve('a', K));
}
