//
// Created by Lenovo on 2024-05-23.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 5010;
int n, m;
int v[N][N], w[N][N], s[N];
int f[N][N];
int cnt;
int groupNum;

void solve() {
    for (int i = 1; i <= groupNum ; i++) {
        for (int j = m; j >= 1; j--) {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= s[i]; k++) {
                if (j >= w[i][k]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - w[i][k]] + v[i][k]);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int wei, vol, groupIdx;
        cin >> wei >> vol >> groupIdx;
        s[groupIdx]++;//第几组
        w[groupIdx][s[groupIdx]] = wei;
        v[groupIdx][s[groupIdx]] = vol;
        groupNum = max(groupNum, groupIdx);
    }
    solve();
    cout << f[groupNum][m];
}