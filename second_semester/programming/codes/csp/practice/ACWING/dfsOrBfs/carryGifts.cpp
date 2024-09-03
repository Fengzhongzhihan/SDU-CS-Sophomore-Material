//
// Created by Lenovo on 2024-06-15.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1 << 24;
int w[N],  cnt;
int res =0, n, p, k;
int g[N];

void dfs1(int u, int s) { //u: 遍历到第几件礼物, k: 最多遍历到第几件礼物, s:当前的总和
    if (u == k) {
        w[cnt++] = s;
        return ;
    }
    //不选择当前礼物
    dfs1(u + 1, s);
    //选择当前礼物
    if (s + g[u] <= p) {
        dfs1(u + 1, s + g[u]);
    }
}

void dfs2(int u ,int s ) {
    if (u == n) {
        //二分查找, 找出左边第一个<=p - s的位置
        int l = 0, r = cnt - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if (w[mid] <= p - s) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        res = max(res, s + w[l]);
        return;
    }
    dfs2(u + 1, s);
    if (s + g[u] <= p) {
        dfs2(u + 1, s + g[u]);
    }
}

signed main() {
    cin >> p >> n;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    sort(g, g + n);
    reverse(g, g + n);
    k = n >> 1;
    dfs1(0, 0);
    //对w进行去重处理
    sort(w, w + cnt);
    int j = 1;
    for (int i = 1 ; i < cnt ;i++) {
        if (w[i] != w[i - 1]) {
            w[j++] = w[i];
        }
    }
    cnt = j;
    //对w进行二分查找
    dfs2(k, 0);
    cout << res;
    return 0;
}
