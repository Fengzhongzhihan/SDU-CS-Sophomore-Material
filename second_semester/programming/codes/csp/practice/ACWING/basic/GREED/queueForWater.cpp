//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N =   1e5 + 10;
int n;
int t[N];
long long res = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n);
    for (int i = 0 ; i < n ; i++) {
        res += (n - 1 - i) * t[i];
    }
    cout << res;
    return 0;
}