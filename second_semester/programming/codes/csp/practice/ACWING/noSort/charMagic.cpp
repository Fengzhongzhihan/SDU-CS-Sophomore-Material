//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
string s;
int n, m;
int cnt[26][N];//i字母在j位置出现的总次数
int sum[26][N];//每个字母出现的总次数
// 统计区间字母出现的次数的最大值
int solve(int l ,int r) {
    int mx = 0;
    for (int i = 0;  i < 26; i++){
        mx = max(mx, sum[i][r] - sum[i][l - 1]);
    }
    return r - l + 1 - mx;
}

int main() {
    cin >> n >> m;
    cin >> s;
    for (int i = 0 ; i < n ; i++) {
        cnt[s[i] - 'a'][i + 1]++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i][j - 1] + cnt[i][j];
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l ,r) << endl;
    }
    return 0;
}