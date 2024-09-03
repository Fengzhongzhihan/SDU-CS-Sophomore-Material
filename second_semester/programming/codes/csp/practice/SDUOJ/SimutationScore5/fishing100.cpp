//
// Created by Lenovo on 2024-05-13.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int n, m;
ll a[N];
ll need[N], bNeed[N];
//need : 1~i所需要的渔网个数
//bneed: i~n所需要的渔网个数
bool check(ll x) { // 耗费体力最多为x
    memset(need, 0, sizeof need);
    memset(bNeed, 0, sizeof bNeed);

    ll l = 0, r = 0;
    //work need
    priority_queue<ll> lHeap;
    for (int i = 1; i <= n; i++) {
        l += a[i];
        lHeap.push(a[i]);
        need[i] = need[i - 1];
        if (l > x) {
            l -= lHeap.top();
            lHeap.pop();
            need[i] ++;
        }
    }
    //work bneed
    priority_queue<ll> rHeap;
    for (int i = n; i >= 1; i--) {
        r += a[i];
        rHeap.push(a[i]);
        bNeed[i] = bNeed[i + 1];
        if (r > x) {
            r -= rHeap.top();
            rHeap.pop();
            bNeed[i] ++;
        }
    }
    //是否能在m个渔网内完成
    if (need[n] <= m || bNeed[1] <= m) return true;
    for (int i = 1; i < n; i++) {
        if (need[i] + bNeed[i + 1] <= m) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll l = 0, r = LONG_LONG_MAX;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;//能完成
        } else {
            l = mid + 1;//不能完成
        }
    }
    cout << l;
    return 0;
}