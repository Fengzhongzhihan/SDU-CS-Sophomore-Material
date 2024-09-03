//
// Created by Lenovo on 2024-06-12.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
const int N = 1e6 + 10;
int tr[N];
int lowbit(int x) {
    return x & (-x);
}

int query(int u) {
    int res = 0;
    for (int i = u; i >= 1; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

void add(int u, int v) {
    for (int i = u; i  <= n; i+= lowbit(i)) {
        tr[i] += v;
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n ; i++) {
        int x; cin >> x;
        add(i, x);
    }
    while (m--) {
        int op, i, x;
        cin >> op >> i >> x;
        if (op == 1) {
            add(i, x);
        }else {
            cout << query(x) - query(i - 1) << endl;
        }
    }
    return 0;
}