//
// Created by Lenovo on 2024-03-22.
//
//
// Created by Lenovo on 2024-03-21.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N];

// 9 10 7 6 8
void buyGoods() {
    long long ans = 0, cnt = 0;
    int bIndex = 0, sIndex = 0;
    for (int i = 0; i < n; i++) {
        //遍历到最后一个位置了, 如果可以卖直接卖了
        if (i == n - 1) {
            if (a[sIndex] > a[bIndex]) {
                cnt += 2;
                ans += a[sIndex] - a[bIndex];
            }
            break;
        }
        //如果下一家的价格更高, 则卖的位置 = i + 1, 买的位置不动
        if (a[i] <= a[i + 1]) {
            sIndex = i + 1;
        }
        // 如果下一家的价格 <= 这一家的价格
        else {
            if (a[sIndex] > a[bIndex]) {
                cnt += 2;
                ans += a[sIndex] - a[bIndex];
            }
            sIndex = bIndex = i + 1;
        }
    }

    cout << ans <<" " << cnt << endl;
}

int main() {
    cin >> m;
    while (m--) {
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        buyGoods();
    }

    return 0;
}