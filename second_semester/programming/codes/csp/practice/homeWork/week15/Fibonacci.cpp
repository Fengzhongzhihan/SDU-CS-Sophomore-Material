//
// Created by Lenovo on 2024-06-08.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 2;
int  mod;

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

//初始化A(1, 1) 代表F(1) = 1, F(2) = 1
signed main() {
    int n, T;
    cin >> T;
    while (T-- ) {
        cin >> n >> mod;
        int a[N] = {1, 1};
        int b[N][N] = {
                {0, 1},
                {1, 1}
        };
        int k = n - 1;
        while (k) {
            if (k & 1) mul(a, b);
            mul(b, b);
            k >>= 1;
        }
        cout << a[0] << endl;
    }
    return 0;
}
