//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
long long a[N], b[N];
int main() {
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    long long  pos = 0, neg = 0;
    for (int i = 2; i <= n; i++) {
        if (b[i] > 0) {
            pos += b[i];
        } else {
            neg += -b[i];
        }
    }
    cout << min(pos, neg) + abs(pos - neg) << endl;
    cout << abs(pos - neg) + 1;
}