//
// Created by Lenovo on 2024-05-15.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
const int MAXNUM = 1e6;
int n, a[N];
long long  cnt[N];// cnt[i]表示i出现的次数
long long  f[N];//表示选取前i个数的时候总最大值
int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    f[1] = cnt[1] * 1;
    f[2] = max(f[1], cnt[2] * 2);
    for (int i = 3 ; i <= MAXNUM  ; i++) {
        f[i] = max(f[i - 1], f[i - 2] + cnt[i] * i); //不选这个数选前i-1个数, 选了这个数选前i-2个数
    }

    cout << f[MAXNUM] ;
}