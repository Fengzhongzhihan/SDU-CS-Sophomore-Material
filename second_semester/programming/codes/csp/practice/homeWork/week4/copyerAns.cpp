//
// Created by Lenovo on 2024-03-20.
//
#include "bits/stdc++.h"
using namespace std;
long long n, x, y;
bool check(long long t) {
    return (t / x + (t - x) / y) >= n;
}
// 3 / 1 = 3      2 / 1 = 2
int main() {
    cin >> n >> x >> y;
    if (x > y) {
        swap (x, y);
    }
    long long l = 0, r = n * y;
    while (l < r) {
        long long mid = (l + r) / 2;
        // 目的 : 找到满足check 的最小的时间
        if (check(mid)) {
            r = mid;
        }
        //时间太短
        else {
            l = mid + 1;
        }
    }
    cout << r;
    return 0;
}