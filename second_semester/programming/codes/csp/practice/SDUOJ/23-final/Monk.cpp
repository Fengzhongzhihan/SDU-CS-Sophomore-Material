//
// Created by Lenovo on 2024-06-14.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 3010;
#define  int long long
int dp[N][2]; // dp[i][1/0]代表前i个关卡是否降伏的最少攻击力
struct ene{
    int at, kind, add;
}ene[N];
int n, w;

//bool dfs(int u, int ww, int at) {
//    if (u == n && ww >= w) {
//        return true;
//    }
//    if (ene[u].at >= at) {
//        return false;
//    }
//    if (ene[u].kind == 1) {//可以收服
//        return dfs(u + 1, ww, at + ene[u].add) || dfs(u + 1, ww + 1, at);
//    }else {//只能杀了
//        return dfs(u + 1, ww, at + ene[u].add);
//    }
//}

//bool solve() {
//    int cnt = 0;
//    for (int i = 1 ; i <= n; i++) {
//        if (ene[i].kind == 1) {
//            dp[i][0] = min (dp[])
//        }
//    }
//}


signed main() {
    cin >> n >> w;
    int l = 0, r  = 0 ;
    for (int i = 1 ; i <= n ; i++) {
        cin >> ene[i].at >> ene[i].kind >> ene[i].add;
        r = max(r, ene[i].at);
    }
    while (l < r) {
        int mid = l + r >> 1;
        if (solve()) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
}