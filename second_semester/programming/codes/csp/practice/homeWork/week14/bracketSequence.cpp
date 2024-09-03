//
// Created by Lenovo on 2024-05-29.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 110;
long long  f[N][N]; // f[i][j]表示区间[i, j]的需要添加的括号数目
string s;

int main() {
    cin >> s;
    int n = s.size();
    memset(f, 0x3f3f3f3f, sizeof f);
    for (int i = 0; i <= n; i++) {
        f[i][i] = 1;
    }
    //不合法的全部置为0
    for (int i = 0; i <= n ; i++) {
        for (int j = 0; j < i; j++) {
            f[i][j] = 0;
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
            if ((s[i - 1] == '(' && s[j - 1] == ')') || (s[i - 1] == '[' && s[j - 1] == ']')) {
                f[i][j] = min(f[i][j], f[i + 1][j - 1]);
            }
        }
    }
    cout << f[1][n];
}