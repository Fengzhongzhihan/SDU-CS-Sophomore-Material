//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, m;
int cow[N];
double s[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + cow[i] - x;
    }
    double minFi = 0x3f3f3f3f;
    for  (int i = 1 , j = m ; j <= n ; i++, j++) {
        minFi = min(minFi, s[i - 1]);
        if (s[j] - minFi >= 0) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> cow[i];
    }
    double l = 0, r = 2000;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid)) {//如果该平均值满足要求
            l = mid;
        }else {
            r = mid;
        }
    }
    cout << (int) (r * 1000);
    return 0;
}