//
// Created by Lenovo on 2024-03-30.
//
// 因为不放心,全部开了long long
#include "bits/stdc++.h"
using namespace  std;
typedef  long long  LL;
const LL N = 1e5 + 10;
const LL mod = 1e9 + 7;
LL maxPrime = 0; // 出现的最大质数, 可节省一点点时间
LL res = 1; // 存储结果
LL n, m;
LL primes[N][110];// primes[i][j]表示第i个数含有值为j的质数的个数
LL st[N][110]; // 差分数组

// 快速幂
LL quickM(LL a, LL k) {
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


int main( ){
    cin >> n >> m;
    while (m--) {   //O(m log(c))
        LL l, r;
        LL c, b;
        cin >> l >> r >> c >> b;
        //将l~r区间的数乘上c^b, 则表示该区间的所有数的含有质数个数均加上c^b的质数个数
        //求c的对应质数的个数
        for (LL i = 2 ; i <= c / i; i++) {
            // c含有质数i
            if (c % i == 0) {
                //每有一个质数, 都在差分数组中加上b, 代表在primes数组[l~r]的位置均加上b
                while (c % i == 0) {
                    c /= i;
                    st[l][i] += b;// 使用差分数组来做 时间复杂度为O(1)
                    st[r + 1][i] -= b;
                }
                // 更新一下最大质数
                if (maxPrime < i) {
                    maxPrime = i;
                }
            }
        }
        // 如果操作完了, c还有数, 即它自身 如26 = 2 * 13
        if (c) {
            st[l][c] += b;
            st[r + 1][c] -= b;
            if (maxPrime < c) {
                maxPrime = c;
            }
        }
    }

    // O(n)
    for (LL j = 1; j <= 100; j++)
        //将差分数组还原成primes数组 O(n)
        for (LL i = 1 ; i <= n; i++) {
            primes[i][j] = primes[i - 1][j] + st[i][j];
        }

    // O(n)
    //此时我们得到了i位置的数对应的j质数的个数
    for (LL j = 2; j <= maxPrime; j++) {
        //找出最小的个数, 按照公式
        LL minNum  = primes[1][j]; // 注意我一开始初始化为mod是错的, 因为质数个数这个值可能很大, 但初始化值为第一个数永远不会错
        for (LL i = 2; i <= n ; i++) {
            if (minNum > primes[i][j]) {
                minNum = primes[i][j];
            }
            if (minNum == 0) {
                break; // 节省时间
            }
        }
        res = res * quickM(j, minNum) % mod; // 注意要%mod
    }

    cout << res;
    return 0;
}