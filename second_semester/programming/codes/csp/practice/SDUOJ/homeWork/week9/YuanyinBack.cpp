//
// Created by Lenovo on 2024-04-25.
//
#include "bits/stdc++.h"
using namespace std;
int n;
int ans = 1;
string s;

bool isYuan(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int expandNum(int l, int r) {
    int k = 0;
    while (l >= 0 && r <= n) {
        if (s[l] == s[r]) {
            l--;
            r++;
            k++;
        }
        else {
            break;
        }
    }

    return k;
}

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0 ; i < n; i++) {
        if (isYuan(s[i])) {
            s[i] = '0';
        } //将所有小写字母都设为0
    }
    for (int i = 0 ; i < n ; i++) {//以这个点进行两边扩展
        int k1 = expandNum(i, i + 1); // 回文串长度偶数的情况
        int k2 = expandNum(i - 1, i + 1); //  回文串长度奇数的情况
        int res = max(2 * k1, 2 * k2 + 1);
        ans = max(ans, res);
    }

    cout << ans;
}