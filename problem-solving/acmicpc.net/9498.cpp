// baekjoon online judge 9498 (www.acmicpc.net/problem/9498)

#include <cstdio>

char grade(int x) {
    if (x >= 90) {
        return 'A';
    } else if (x >= 80) {
        return 'B';
    } else if (x >= 70) {
        return 'C';
    } else if (x >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}
int main() {
    int x;
    scanf("%d", &x);
    printf("%c\n", grade(x));

    return 0;
}
