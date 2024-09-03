//
// Created by Lenovo on 2024-06-19.
//
#include "bits/stdc++.h"
using namespace std;
int T, R, C;
const int N = 110;
int f[N][N]; // 表示走到第i个位置, 第j个位置的最大花生个数
int g[N][N];
int main() {
    cin >> T;
    while (T--) {
        cin >> R >> C;
        memset(f, 0, sizeof f);
        for (int i = 0 ; i < R; i++) {
            for (int j = 0 ; j < C; j++) {
                cin >> g[i][j];
            }
        }
        f[0][0] = g[0][0];
        for (int i = 0  ; i < R ; i++) {
            for (int j = 0 ; j < C ; j++) {
                if (i - 1 >= 0 ) {
                    f[i][j] = max(f[i][j], f[i - 1][j] + g[i][j]);
                }
                if (j - 1 >= 0) {
                    f[i][j] = max(f[i][j], f[i][j - 1] + g[i][j]);
                }
            }
        }
        cout << f[R - 1][C - 1] << endl;
    }
    return 0;
}