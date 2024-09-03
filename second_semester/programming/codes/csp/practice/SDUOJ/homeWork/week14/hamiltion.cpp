//
// Created by Lenovo on 2024-05-29.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 20, M = 1 << N;
int n;
int f[M][N], w[N][N];

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j  < n ; j++) {
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;//代表走过了零号点的最短路径长度为0
    for (int i = 0 ; i < 1 << n ; i++) {
        for (int j = 0 ; j < n; j++) {
            if (i >> j & 1) { // i的第j位是1, 代表状态i中走过了j点, 此时j为目的地
                for (int k = 0 ; k < n ; k++) { // 枚举所有点
                    if ((i - (1 << j)) >> k & 1) { // i去掉j, 如果走过了k点
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1];
    return 0;
}