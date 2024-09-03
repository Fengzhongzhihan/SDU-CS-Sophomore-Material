//
// Created by Lenovo on 2024-05-15.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int n;
long long f[4][N]; // f[i][j]表示第j列选择了第i行的最小值
long long g[4][N];

int main() {
    cin >> n;
    //初始化g
    for (int i = 1 ; i <= 3 ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> g[i][j];
        }
    }

    //初始化
    for (int i = 1; i <= 3; i++) {
        f[i][1] = 0;
    }
    for (int j = 2; j <= n ; j++) {
        for (int i = 1; i <= 3; i++) { //枚举第j列选择第i行
            f[i][j] = min (min(f[1][j - 1] + abs(g[i][j] - g[1][j - 1]),
                               f[2][j - 1] + abs(g[i][j] - g[2][j - 1])),
                           f[3][j - 1] + abs(g[i][j] - g[3][j - 1]));
        }
    }

    cout << min(min(f[1][n], f[2][n]), f[3][n]);
}