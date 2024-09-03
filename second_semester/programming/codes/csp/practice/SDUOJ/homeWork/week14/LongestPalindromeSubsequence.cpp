//
// Created by Lenovo on 2024-05-29.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 5010;
string s;
long long f[N][N];//f[i][j]表示区间[i, j]的最长回文子序列长度

int main() {
    cin >> s;
    int n = s.size();
    for (int i = 1; i <= n ; i++) {
        f[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            if (s[i - 1]  == s[j - 1]) {
                f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
            }
        }
    }

    cout << f[1][n];
}