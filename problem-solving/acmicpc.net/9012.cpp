// baekjoon online judge 9012 (www.acmicpc.net/problem/9012)

#include <cstdio>

bool isValidParenthesis(char* s) {
    int opened = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') {
            opened += 1;
        } else {
            opened -= 1;
        }
        if (opened < 0) {
            return false;
        }
    }
    return opened == 0;
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        char input[51];
        scanf("%s", input);
        printf("%s\n", isValidParenthesis(input) ? "YES" : "NO");
    }

    return 0;
}
