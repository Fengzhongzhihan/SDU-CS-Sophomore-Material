//
// Created by Lenovo on 2024-03-29.
//
#include "bits/stdc++.h"
using namespace  std;
int n, m;
const int N = 1e6 + 10;
//每一个字母都建立一个stone序列, 存储出现的个数
int stone[N][27], s[N][27];
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

    cin >> m;
    while (m--) {
        int l , r;
        cin >> l >> r;
        bool flag = true;
        //判断每一个元素是否出现过
        for (int j = 1; j <= 26 ;j++) {
            int cnt = s[r][j] - s[l - 1][j];
            if (cnt == 0) {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }

    }
}