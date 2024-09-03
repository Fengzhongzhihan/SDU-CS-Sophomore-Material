//
// Created by Lenovo on 2024-06-08.
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 3;
const int  mod = 998244353;
//A表示绿蓝为偶数的方案数, B表示绿蓝都为奇数的方案数, C表示绿蓝有一个为偶数的方案数
// A[i] = A[i - 1] + C[i - 1]
// B[i] = B[i - 1] + C[i - 1]
// C[i] = 2 * A[i - 1] + 2 * B[i - 1] + C[i - 1]
//ans[i] [A, B, C] = ans[i-1] * [1, 0, 1]^-1 [0, 1, 1]^-1 [2, 2, 1]^-1

void mul(int A[], int B[][N]) { //一维向量乘二维向量, 结果保存到A中
    int C[N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i] = (C[i] + A[j] * B[j][i] % mod) % mod;
        }
    }
    for (int i = 0; i < N; i++) {
        A[i] = C[i];
    }
}

void mul(int A[][N], int B[][N]) { //二维向量乘二维向量, 结果保存到A中
    int C[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = C[i][j];
        }
    }
}
signed main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n ;
        //初始化
        int a[N] = {1, 0, 2}; //一个格子时, A = 1, B = 0, C = 2
        int b[N][N] = {
                {1, 0, 2},
                {0, 1, 2},
                {1, 1, 1}
        };
        int k = n - 1;
        //快速幂
        while (k) {
            if (k & 1) {
                mul(a, b);
            }
            mul(b, b);
            k >>= 1;
        }
        cout << a[0] << endl;
    }
}