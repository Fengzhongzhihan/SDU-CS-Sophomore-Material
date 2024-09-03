//
// Created by Lenovo on 2024-06-19.
//
#include "bits/stdc++.h"
using namespace std;
int n, m;
const int N = 1010;
int f[N];
int v[N], w[N];

void solve() {
    for (int i = 1 ; i <= n  ; i++) {
        for (int j = m ; j >= v[i] ; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
};

int main() {
    cin >> m >> n;
    for (int i = 1 ; i  <= n ; i++) {
        cin >>  v[i] >> w[i];
    }
    solve();
    cout << f[m] << endl;
}