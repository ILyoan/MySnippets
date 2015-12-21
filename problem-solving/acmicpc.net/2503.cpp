// baekjoon online judge 2503 (www.acmicpc.net/problem/2503)

#include <cstdio>

const int MAX_N = 100;

struct Baseball {
    int number;
    int strike;
    int ball;
};

Baseball baseball[MAX_N + 1];


bool is_valid_guess(int a, int b, int c, Baseball* baseball, int n) {
    for (int i = 0; i < n; ++i) {
        int number_a = baseball[i].number / 100;
        int number_b = (baseball[i].number / 10) % 10;
        int number_c = baseball[i].number % 10;

        int strikes = 0;
        if (a == number_a) {
            strikes += 1;
        }
        if (b == number_b) {
            strikes += 1;
        }
        if (c == number_c) {
            strikes += 1;
        }

        int balls = 0;
        if (a == number_b || a == number_c) {
            balls += 1;
        }
        if (b == number_a || b == number_c) {
            balls += 1;
        }
        if (c == number_a || c == number_b) {
            balls += 1;
        }

        if (strikes != baseball[i].strike || balls != baseball[i].ball) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &baseball[i].number);
        scanf("%d", &baseball[i].strike);
        scanf("%d", &baseball[i].ball);
    }

    int valid_count = 0;

    for (int a = 1; a <= 9; ++a) {
        for (int b = 1; b <= 9; ++b) {
            if (b == a) {
                continue;
            }
            for (int c = 1; c <= 9; ++c) {
                if (c == b || c == a) {
                    continue;
                }
                if (is_valid_guess(a, b, c, baseball, n)) {
                    valid_count += 1;
                }
            }
        }
    }

    printf("%d\n", valid_count);

    return 0;
}
