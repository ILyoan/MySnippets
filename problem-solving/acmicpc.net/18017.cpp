// baekjoon online judge 18017 (www.acmicpc.net/problem/18017)

#include <cstdio>

int secondLargest(int a, int b, int c) {
    if (b >= a && a >= c || c >= a && a >= b) {
        return a;
    } else if (a >= b && b >= c || c >= b && b >= a) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    printf("%d\n", secondLargest(a, b, c));;

    return 0;
}
