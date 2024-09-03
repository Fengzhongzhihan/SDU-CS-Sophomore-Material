//
// Created by Lenovo on 2024-06-19.
//
#include "bits/stdc++.h"
using  namespace std;
int T, n;
const int N = 110;
int a[N];
int f_up[N], f_down[N];//f_up[i]表示以i为结尾的最长上升子序列. f_down[i]表示以i为开头的最长下降子序列
int main() {
    cin >> T;
    while (T--) {
        memset(f_up, 0, sizeof f_up);
        memset(f_down, 0, sizeof f_down);
         cin >> n;
         for (int i = 1 ; i  <= n ;i++) {
            cin >> a[i];
         }
         for (int i = 1; i  <= n ; i++) {
                f_up[i] = f_down[i] = 1;
         }
        for (int i = 1; i <= n ;i ++) {
            for (int j  = 1; j <= i ; j++) {
                if (a[j] < a[i]) {
                    f_up[i] = max(f_up[i], f_up[j] + 1);
                }
            }
        }

        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= i; j--) {
                if (a[j] < a[i]) {
                    f_down[i] = max(f_down[i], f_down[j] + 1);
                }
            }
        }
        int max_len = 0;
        for (int i = 1; i <= n ; i++) {
            max_len = max(max_len, max(f_up[i], f_down[i]));
        }
        cout << max_len << endl;
    }
}