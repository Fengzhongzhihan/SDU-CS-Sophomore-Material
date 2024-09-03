//
// Created by Lenovo on 2024-05-08.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll s[N], d[N];
#define lb(x) ((x) & (-(x)))

//返回1~p的和
ll ask(ll p) {
    ll res = 0;
    for (int i = p; i >= 1; i -= lb(i)) {
        res += s[i];
    }
    return res;
    //p = 11 1011
    //s[11] + s[10] + s[8]
    //s[11] = d[11]
    //s[10] = d[10] + d[9]
    //s[8] = d[8] + ... + d[1]
}
//查询
ll sum (ll l, ll r) {
    return ask(r) - ask(l - 1); // 返回l~r的和
}

void upd(int p, int x) {
    for (int i = p; i <= 100000; i += lb(i)) {
        s[i] += x;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];//输入
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += sum(d[i] + 1, 100000);//查询比d[i] + 1大的此时的元素个数
        upd(d[i], 1);//将d[i] ++;
    }

    cout << res;
    return 0;
}
