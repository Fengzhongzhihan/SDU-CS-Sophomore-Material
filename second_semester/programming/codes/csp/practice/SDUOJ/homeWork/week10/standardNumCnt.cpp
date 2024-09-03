//
// Created by Lenovo on 2024-05-10.
//
#include "bits/stdc++.h"
using namespace std;
int n;
const int N = 1e5 + 10;
int a[N];
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int minValue = a[0], maxValue = a[n - 1];
    // 1 2 3 3
    // 1 2 3 3 3
   //分奇偶数讨论求中位数
   cout << maxValue << " ";
    if (n % 2 == 0) {
        int tmp1 = a[n / 2 - 1], tmp2 = a[n / 2];
        //如果tmp1 + tmp2是奇数
        if ((tmp1 + tmp2) % 2 == 0) {
            cout << (tmp1 + tmp2) / 2 << " ";
        } else {
            cout << (tmp1 + tmp2) / 2 << ".5 ";
        }
    } else {
        cout << a[n / 2] << " ";
    }
    cout << minValue ;
    return 0;
}