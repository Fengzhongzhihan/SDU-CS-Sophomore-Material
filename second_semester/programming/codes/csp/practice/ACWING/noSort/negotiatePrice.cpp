//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5 + 10;
int price[N];
int res = 0;
int bestPrice = 0;
signed main() {
    int n; cin >> n;
    for (int i = 0; i < n ; i++) {
        cin >> price[i];
    }
    sort(price, price + n);
    for (int i = 0 ; i < n ; i++) {
        int sumMoney = price[i] * (n - i);
        if (res < sumMoney) {
            res = sumMoney;
            bestPrice = price[i];
        }
    }
    cout << res << " " << bestPrice;
    return 0;
}