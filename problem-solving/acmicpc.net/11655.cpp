// baekjoon online judge 11655 (www.acmicpc.net/problem/11655)

#include <cstdio>

const int MAX_LENGTH = 100;

char str[MAX_LENGTH + 1];
char rot[MAX_LENGTH + 1];

void rot13(char* dst, char* src) {
    for (int i = 0; src[i]; ++i) {
        if (src[i] == ' ') {
            dst[i] = ' ';
        } else if (src[i] >= '0' && src[i] <= '9') {
            dst[i] = src[i];
        } else if (src[i] >= 'A' && src[i] <= 'Z') {
            dst[i] = (src[i] - 'A' + 13) % 26 + 'A';
        } else {
            dst[i] = (src[i] - 'a' + 13) % 26 + 'a';
        }
    }
}

int main() {
    gets(str);

    rot13(rot, str);

    printf("%s\n", rot);

    return 0;
}
