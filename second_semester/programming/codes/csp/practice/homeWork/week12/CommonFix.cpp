//
// Created by Lenovo on 2024-05-15.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 5010;
int f[N][N]; // f[i][j]表示a[1~i]和b[1~j]的最长公共子序列
int a[N], b[N];
int n, m;
int main() {
    cin >> n >> m;
    //初始化a,b;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= m ; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[n][m];
    return 0;
}