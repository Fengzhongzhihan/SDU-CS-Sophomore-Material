//
// Created by Lenovo on 2024-06-13.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5 + 10;
int w[N], totalW, n;
int res  = LONG_LONG_MAX;
int carry[N];//carry[i]表示第i个缆车承载量
//当前遍历到第u个小猫, 一共找了cnt个缆车
void dfs(int u, int cnt) {
    if (u == n) {
        res = min(res, cnt);
        return;
    }
    if (cnt >= res) return;
    //寻找可以放得下的缆车
    for (int i = 0 ; i < cnt ; i++) {
        //在第i个缆车里面放猫
        if (carry[i] + w[u] <= totalW) {
            carry[i] += w[u];
            dfs(u + 1, cnt);
            carry[i] -= w[u];
        }
    }
    //新开一个缆车
    carry[cnt] = w[u];
    dfs(u + 1, cnt + 1);
}

signed main() {
    cin >> n >> totalW;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w, w + n, greater<int>());
    dfs(0, 0);
    cout << res << endl;
}