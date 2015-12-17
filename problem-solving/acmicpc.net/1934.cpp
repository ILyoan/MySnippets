// baekjoon online judge 1934 (www.acmicpc.net/problem/1934)

#include <cstdio>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; ++tc) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lcm(a, b));
    }

    return 0;
}
