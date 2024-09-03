//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, tt, k;
int t[N], v[N], w[N];
int f1[N], f2[N];
signed main() {
    cin >> n >> tt >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> t[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> v[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> w[i];
    }
    //求解选取前k个地铁站, 时间总量为t的最大价值
    for (int i = 1; i <= k; i++) {
        int extra = 2 * (t[k] - t[i]); // 从第i个地铁站到第k个地铁站的往返时间, 代表至少得满足从第i个地铁站回来
        for (int j = tt; j >= v[i] + extra; j--) {
            f1[j] = max(f1[j], f1[j - v[i]] + w[i]);
        }
    }
    for (int i = n; i >= k; i--) {
        int extra = 2 * (t[i] - t[k]);
        for (int j = tt; j >= v[i] + extra; j--) {
            f2[j] = max(f2[j], f2[j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= tt; i++) {
        ans = max(ans, f1[i] + f2[tt - i]);
    }
    cout << ans << endl;
    return 0;
}