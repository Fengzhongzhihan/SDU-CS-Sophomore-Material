//
// Created by Lenovo on 2024-03-29.
//
#include "bits/stdc++.h"
using namespace  std;
int n, m;
const int N = 1e6 + 10;
int res = N;
//每一个字母都建立一个stone序列, 存储出现的个数
int stone[N][27], s[N][27];

bool check(int l , int r) {
    for (int j = 1; j <= 26 ;j++){
         if (s[r][j] - s[l - 1][j] == 0) {
             return false;
         }
    }
    return true;
}
// 二维
int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        char c; cin >> c;
        stone [i][c - 'A' + 1] = 1;
    }
    for (int j = 1 ; j <= 26 ; j++) {
        for (int i = 1 ; i <= n ; i++) {
            s[i][j] = s[i - 1][j] + stone[i][j];
        }
    }

    //判断每个区间是否满足要求
    int i = 1, j = 1;
    while (i <= n && j <= n) {
        while (j <= n && !check(i, j)) {
            j++;
        }
        if (j > n) {
            break;
        }
        while (i <= n && check(i, j)) {
            i++;
        }
        res = min (res, j - i + 2);
    }

    cout << res;
}
