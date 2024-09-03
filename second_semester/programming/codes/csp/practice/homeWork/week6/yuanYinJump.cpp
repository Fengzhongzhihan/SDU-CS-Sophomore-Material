//
// Created by Lenovo on 2024-04-02.
//
#include "bits/stdc++.h"
using namespace std;
int n, res;
string s;

bool isYuan (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

//aeioubaeio
int main() {
    cin >> n >> s;
    for (int i = 0 ; i < s.size() ; i++) {
        int cnt = 0;
        if (isYuan(s[i])) {
            int j = i;
            while (j < s.size() && isYuan(s[j])) {
                j++;
            }
            if (j > i) {
                res = max(j - i, res);
            }
            i = j;
        }
    }
    cout << res ;
}