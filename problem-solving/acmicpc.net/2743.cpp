// baekjoon online judge 2743 (www.acmicpc.net/problem/2743)

#include <cstdio>

const int MAX_LENGTH = 100;

char str[MAX_LENGTH + 1];

int strlen(char* str) {
    int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

int main() {
    scanf("%s", str);

    int len = strlen(str);

    printf("%d\n", len);

    return 0;
}
