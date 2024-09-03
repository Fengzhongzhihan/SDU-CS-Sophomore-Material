//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i + 1] == a[i]) {
            cout << "1"<< endl;
            return 0;
        }else if (i + 2 < n && a[i + 2] == a[i] ) {
            cout << "2/3" << endl;
            return 0;
        }
    }
    cout << "1/2" << endl;
    return 0;
}