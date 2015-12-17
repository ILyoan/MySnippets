// baekjoon online judge 1924 (www.acmicpc.net/problem/1924)

#include <cstdio>

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char* day_of_week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
    int x, y;
    scanf("%d%d", &x, &y);

    int how_many_days = 0;

    for (int month = 1; month < x; ++month) {
        how_many_days += days[month - 1];
    }

    how_many_days += y;

    printf("%s\n", day_of_week[how_many_days % 7]);

    return 0;
}
