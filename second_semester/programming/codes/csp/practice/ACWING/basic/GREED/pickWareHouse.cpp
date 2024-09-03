//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res =0 ;
    int sm = a[n / 2]; // n = 8  sm = a[4]  n = 9 sm = a[4]
    for (int i = 0 ; i < n ; i++) {
       res  += abs(a[i] - sm);
    }
    cout << res << endl;
    return 0;
}