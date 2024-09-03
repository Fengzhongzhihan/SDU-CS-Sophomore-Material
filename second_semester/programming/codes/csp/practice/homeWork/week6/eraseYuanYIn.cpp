//
// Created by Lenovo on 2024-04-02.
//
#include "bits/stdc++.h"
using namespace std;
int n;
string s;
string res = "";

bool isYuan (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

//aeioubaeiou
int main() {
    cin >> n >> s;
    for (int i = 0 ; i < s.size() ; i++) {
        int cnt = 0;
        if (isYuan(s[i])) {
            res += s[i];
            int j = i;
            while (j < s.size() && isYuan(s[j])) {
                j++;
            }
            i = j - 1;
        }
        //不是元音
        else {
            res += s[i];
        }
    }

    cout << res;
}