//
// Created by Lenovo on 2024-05-10.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll s[N];
ll n, m;

ll lowbit(ll x) {
    return x & (-x);
}

//p位置加x
void upd(ll p , ll x) {
    for (ll i = p ; i <= n ; i += lowbit(i)) {
        s[i] += x;
    }
}
//查询1~p的和
ll ask(ll p) {
    ll res = 0;
    for (ll i = p; i >= 1; i -= lowbit(i)) {
        res += s[i];
    }
    return res;
}

ll sum(ll l, ll r) {
   return ask(r) - ask(l - 1);
}
int main() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        upd(i, x);
    }

    while (m --) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll p, x;
            cin >> p >> x;
            upd(p, x);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << sum(l, r) << endl;
        }
    }
    return 0;
}