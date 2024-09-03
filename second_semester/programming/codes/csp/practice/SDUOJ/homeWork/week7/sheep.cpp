//
// Created by Lenovo on 2024-04-12.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int m , n;
int a[N];

//枚举任意两个山羊间的最小距离
bool check(int x) {
    int sum = 1 ; //放牛的个数
    int pre = a[0] ; // 此时的牛的位置
    for (int i = 1 ; i < n ; i++) {
        if (a[i] - pre >= x) { // 可以再放下一头
            sum ++;
            pre = a[i];
        }
    }

    if (sum >= m) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int l = 0, r = 1e9;
    while (l < r) {
        int mid =  l + r + 1 >> 1;
        if (check(mid) ) { // x可以放得下牛
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << l;
}