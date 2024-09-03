//
// Created by Lenovo on 2024-04-22.
//
#include "bits/stdc++.h"
using  namespace std;
const int N = 1010;
int a[N], b[N];
int n;
int main() {
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    b[0] = (a[1] + a[0]) / 2; // 特判
    b[n - 1] = (a[n - 1] + a[n - 2]) / 2; // 特判

    for (int i = 1; i < n - 1; i++) {
        b[i] = (a[i] + a[i - 1] + a[i + 1]) / 3;
    }

    for (int i = 0 ; i < n ; i++) {
        cout << b[i] << " ";
    }
    return 0;
}