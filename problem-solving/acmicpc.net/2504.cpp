// baekjoon online judge 2504 (www.acmicpc.net/problem/2504)

#include <cstdio>

const int MAX_LEN = 30;

char str[MAX_LEN + 1];

int idx;
bool invalid;

int eval();

int evalParenthesis() {
    idx += 1;

    if (str[idx] == ')') {
        idx += 1;
        return 2;
    } else {
        int v = eval();
        if (str[idx] == ')') {
            idx += 1;
            return 2 * v;
        } else {
            return 0;
        }
    }
}

int evalBracket() {
    idx += 1;

    if (str[idx] == ']') {
        idx += 1;
        return 3;
    } else {
        int v = eval();
        if (str[idx] == ']') {
            idx += 1;
            return 3 * v;
        } else {
            return 0;
        }
    }
}

int eval() {
    int value = 0;
    while (str[idx]) {
        if (str[idx] == '(') {
            int v = evalParenthesis();
            if (v == 0) {
                return 0;
            } else {
                value += v;
            }
        } else if (str[idx] == '[') {
            int v = evalBracket();
            if (v == 0) {
                return 0;
            } else {
                value += v;
            }
        } else {
            break;
        }
    }
    return value;
}

int main() {
    scanf("%s", str);

    idx = 0;
    int value = eval();

    if (str[idx]) {
        value = 0;
    }

    printf("%d\n", value);

    return 0;
}
