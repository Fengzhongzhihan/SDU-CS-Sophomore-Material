//
// Created by Lenovo on 2024-05-23.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 5010;
int n, m;
int w[N], v[N];
int f[N];

void solve() {
    for (int i = 1; i <= n ; i++) {
        for (int j = w[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    solve();
    cout << f[m];
}