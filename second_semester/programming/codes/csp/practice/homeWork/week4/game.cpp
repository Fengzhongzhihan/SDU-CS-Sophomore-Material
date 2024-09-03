//
// Created by Lenovo on 2024-03-21.
//
#include "bits/stdc++.h"
using namespace  std;
const int  N = 1e5 + 10;
int n;
long long k;
long long a[N];
int cnt;

int main() {
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    sort (a, a + n);

    for (int i = 0; i + 1 < n ; i++) {
        if (a[i + 1] - a[i] <= k ) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}