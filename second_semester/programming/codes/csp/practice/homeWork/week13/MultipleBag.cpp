//
// Created by Lenovo on 2024-05-23.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll n, m;
ll w[N], v[N];
ll f[N], idx = 1;

void solve() {
    for (ll i = 1; i < idx ; i++) {
        for (ll j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll wei, vol, k;
        cin >> wei >> vol >> k;
        for (ll j = 1; j <= k; j *= 2) {
            w[idx] = j * wei;
            v[idx++] = j * vol;
            k -= j;
        }
        if (k) {
            w[idx] = k * wei;
            v[idx++] = k * vol;
        }
    }
    solve();
    cout << f[m];
}