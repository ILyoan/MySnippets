// baekjoon online judge 10799 (www.acmicpc.net/problem/10799)

#include <cstdio>

char str[100001];
int stack[100001];

int main() {
    scanf("%s", str);
    int top = 0;
    int ans = 0;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '(') {
            stack[top++] = i;
        }
        else {
            if (stack[--top] == i - 1) {
                ans += top;
            }
            else {
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}