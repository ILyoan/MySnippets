// baekjoon online judge 3111 (www.acmicpc.net/problem/3111)
 
// category: implementation, stack
// difficulty: medium
 
#include <cstdio>
#include <cstring>
 
const int MAX_A_LEN = 25;
const int MAX_T_LEN = 300000;
 
char A[MAX_A_LEN + 1];
char T[MAX_T_LEN + 1];
int ALen;
int TLen;
 
int LST[MAX_T_LEN + 1];
int RST[MAX_T_LEN + 1];
int LC;
int RC;
 
bool match_left() {
    int offset = LC - ALen;
    if (offset < 0) return false;
    for (int k = 0; k < ALen; ++k) {
        if (T[LST[offset + k]] != A[k]) return false;
    }
    for (int k = 0; k < ALen; ++k) {
        int idx = LST[offset + k];
        T[idx] = '*';
        while (RC > 0 && RST[RC - 1] <= idx) {
            RC--;
        }
    }
    LC -= ALen;
    return true;
}
 
void add_left(int idx) {
    if (T[idx] != '*') {
        LST[LC++] = idx;
    }
}
 
bool match_right() {
    if (RC < ALen) return false;
    for (int k = 0; k < ALen; ++k) {
        if (T[RST[RC - k - 1]] != A[k]) return false;
    }
    for (int k = 0; k < ALen; ++k) {
        int idx = RST[RC - k - 1];
        T[idx] = '*';
        while (LC > 0 && LST[LC - 1] >= idx) {
            LC--;
        }
    }
    RC -= ALen;
    return true;
}
 
void add_right(int idx) {
    if (T[idx] != '*') {
        RST[RC++] = idx;
    }
}
 
int main() {
    scanf("%s%s", A, T);
 
    ALen = strlen(A);
    TLen = strlen(T);
 
    int li = 0;
    int ri = TLen - 1;
 
    while (true) {
        bool match = false;
        while (true) {
            if (match_left()) {
                match = true;
                break;
            }
            if (li >= TLen) break;
            add_left(li++);
        }
        if (!match) break;
        match = false;
        while (true) {
            if (match_right()) {
                match = true;
                break;
            }
            if (ri < 0) break;
            add_right(ri--);
        }
        if (!match) break;
    }
    for (int i = 0; T[i]; ++i) {
        if (T[i] != '*') {
            putchar(T[i]);
        }
    }
    putchar('\n');
 
    return 0;
}
