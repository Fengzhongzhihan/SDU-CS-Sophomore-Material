//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
int t ;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;//答案为 a / (b + 1)
        int c = b + 1;
        int w = gcd(a, c);
        a /= w;
        c /= w;
        if (a == 0) {
            cout << 0 << endl;
            continue;
        }
        if (c == 1) {
            cout << a << endl;
            continue;
        }
        cout << a << " " << c << endl;
    }
}