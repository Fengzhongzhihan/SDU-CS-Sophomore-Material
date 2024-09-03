//
// Created by Lenovo on 2024-03-17.
//
#include "bits/stdc++.h"
using namespace  std;
int n;

int minOP(string s) {
    // BABABABABABA ,偶数位为A, 奇数位为B
    for (int i = 0 ; i + 1 < n ; i++) {
        if (s[i] == s[i + 1]) {
            
        }
    }
}

int main() {
    for (int i = 0; i < n ; i++) {
        string s;
        cin >> s;
        cout << minOP(s) << endl;
    }

    return 0;
}