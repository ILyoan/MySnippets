// baekjoon online judge 2580 (www.acmicpc.net/problem/2580)

// Category: Backtrack
// Difficulty: Easy

#include <cstdio>
 
int sudoku[81];
int emptys[81];
int empty_cnt;
 
#define GETY(idx) ((idx) / 9)
#define GETX(idx) ((idx) % 9)
#define GETI(y, x) ((y) * 9 + (x))
 
bool solve(int empty_idx) {
    if (empty_idx == empty_cnt) {
        return true;
    }
 
    int idx = emptys[empty_idx];
     
    int y = GETY(idx);
    int x = GETX(idx);
 
    // candidates
    bool used[10] = { 0 };
    for (int xx = 0; xx < 9; ++xx) {
        used[sudoku[GETI(y, xx)]] = true;
    }
    for (int yy = 0; yy < 9; ++yy) {
        used[sudoku[GETI(yy, x)]] = true;
    }
    int ybox = y / 3 * 3;
    int xbox = x / 3 * 3;
    for (int yy = ybox; yy < ybox + 3; ++yy) {
        for (int xx = xbox; xx < xbox + 3; ++xx) {
            used[sudoku[GETI(yy, xx)]] = true;
        }
    }
 
    // try
    for (int i = 1; i <= 9; ++i) {
        if (!used[i]) {
            sudoku[idx] = i;
            if (solve(empty_idx + 1)) {
                return true;
            }
        }
    }
 
    // backtrack
    sudoku[idx] = 0;
    return false;
}
 
int main() {
    for (int i = 0; i < 81; ++i) {
        scanf("%d", &sudoku[i]);
        if (sudoku[i] == 0) {
            emptys[empty_cnt++] = i;
        }
    }
 
    solve(0);
 
    for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
            printf("%d ", sudoku[GETI(y, x)]);
        }
        printf("\n");
    }
 
    return 0;
}
