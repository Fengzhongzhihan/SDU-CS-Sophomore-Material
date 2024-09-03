//
// Created by Lenovo on 2024-03-30.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e5 + 10;
typedef  long long  LL;
const LL mod = 1e9 + 7;
LL res = 1;
int n, m;
LL s[N];
double st[N]; // 差分数组
LL primes[N][110]; // 表示质数的个数
// a的k次方
LL quickM(LL a, int k) {
    LL ans = 1;
    // k == 0
    while (k) {
        // 最后一位为1
        if (k & 1) {
            ans = ans * a % mod;
        }
        k >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void insert(int l , int r , LL c) {
    st[l] = LL(st[l] * c) % mod;
    st[r + 1] /= c;
}

int main( ){
    cin >> n >> m;
    for (int i = 0 ; i <= n ; i++ ) {
        s[i] = st[i] = 1;
    }
    while (m--) {
        int l, r;
        LL c, b;
        cin >> l >> r >> c >> b;
        LL qm = quickM(c, b);
        insert(l, r, qm);
    }
    for (int i = 1 ; i <= n; i++) {
        s[i] = LL(st[i] * s[i - 1]) % mod; // s[1] = 1  s[2] = 2 * 1 = 2 s[3] = 2 * 4 = 8
    }

    // 求n个数的最大公约数
    for (LL i = 1; i <= n ; i++ ) {
        LL t = s[i]; //t代表需要筛的数
        for (LL j = 2; j <= t / j; j++ ) {
            //筛质数
            if (t % j == 0) {
                LL cnt = 0;//质数的个数
                while (t % j == 0) {
                   cnt++;
                   t /= j;
                }
                primes[i][j] = cnt;
            }
        }
        if (t > 1) {
            primes[i][t] = 1;
        }
    }

    //最后算出来每个质数的最小值
    for (int j = 1; j <= 100; j++) {
        LL minNum = primes[1][j];
        for (int i = 1; i <= n ; i++) {
            if (minNum > primes[i][j]) {
                minNum = primes[i][j];
            } ;
            if (minNum == 0) {
                break;
            }
        }

        res = res * quickM(j, minNum) % mod;
    }

    cout << res;
    return 0;
}