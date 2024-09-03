//
// Created by Lenovo on 2024-05-15.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
const int MOD = 998244353;
int n, m, k;
long long f[N]; // f[i]表示爬到i阶楼梯的方案数目
long long sum[N];//表示0~i阶楼梯的总方案数目
bool st[N];
int main() {
    cin >> n >> m >> k;
    f[0] = 1;//爬到0阶楼梯的方案数目为1
    sum[0] = 1;
    for (int i = 0 ; i < m ; i++) {
        int x;
        cin >> x;
        st[x] = true;//x阶楼梯不可走, 方案数为0
    }
    for (int i = 1; i <= n ; i++) {
        if (st[i]) {
            f[i] = 0; sum[i] = sum[i - 1];//如果i阶楼梯不可走, 该层方案数为0
        }
        else {//如果i阶楼梯可走
            f[i] = sum[i - 1];//爬到i阶楼梯的方案数目为爬0 ~ i - 1阶楼梯的总方案数目
            if (i - k - 1 >= 0) {
                f[i] = (f[i] - sum[i - k - 1] + MOD) % MOD;
            }
        }
        sum[i] = (sum[i - 1] + f[i]) % MOD;
    }

    cout << f[n] << endl;
}