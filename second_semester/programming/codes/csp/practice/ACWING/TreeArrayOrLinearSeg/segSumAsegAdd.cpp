//
// Created by Lenovo on 2024-06-12.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
const int N = 1e6 + 10;
int d[N], di[N], a[N];

int lowbit(int x) {
    return x & (-x);
}

int query(int c[], int u) {
    int res = 0;
    for (int i = u; i >= 1; i -= lowbit(i)) {
        res += c[i];
    }
    return res;
}

void add(int c[], int u, int v) {
    for (int i = u; i  <= n; i+= lowbit(i)) {
        c[i] += v;
    }
}
//返回1~r的和
int getSum(int r) {
   return query(d,r) * (r + 1) - query(di, r);
}

signed main() {
    cin >> n >> m;
    for (int i = 1 ; i <= n  ; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        add(d, i, a[i] - a[i - 1]);
        add(di, i, i * (a[i] - a[i - 1]));
    }
    while (m--) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l, r;
            cin >> l >> r;
            int res = getSum(r) - getSum(l - 1);
            cout << res << endl;
        }
        else {
            int l, r, c;
            cin >> l >> r >> c;
            add(d, l, c);
            add(d, r + 1, -c);
            add(di, l, c * l);
            add(di, r + 1, -c * (r + 1));
        }
    }
}