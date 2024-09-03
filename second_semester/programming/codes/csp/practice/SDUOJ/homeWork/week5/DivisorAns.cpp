//
// Created by Lenovo on 2024-03-30.
//
#include <bits/stdc++.h>

using namespace std;
// dd[i][j] 表示第i个元素的第j个质数的个数
long long dd[100001][100];
// 质数判断
bool prime(long long a)
{
    if (a == 1)
    {
        return false;
    }
    else if (a == 2)
    {
        return true;
    }

    for (long long i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}
// 快速幂计算并取模
long long P(long long x, long long n, long long mod)
{
    long long r = 1;
    while (n)
    {
        if (n & 1)
        {
            r = (r * x) % mod;
        }
        x = (x * x) % mod;
        n = n >> 1;
    }
    return r;
}

int main()
{
    long long n, m, max = 0;
    cin >> n >> m;
    long long res = 1;
    // 初始化
    for (long long i = 0; i < n + 1; i++)
    {
        for (long long j = 0; j < 100; j++)
        {
            dd[i][j] = 0;
        }
    }
    // m次操作
    for (long long i = 1; i <= m; i++)
    {
        long long l, r, c, b;
        cin >> l >> r >> c >> b;
        if (prime(c))
        { // c为质数
            dd[l - 1][c] += b; // 使用差分进行记录多次操作之后次方数
            dd[r][c] -= b;
            if (max < c) // 寻找最大的质因数，用于之后的寻找最大质因数
            {
                max = c;
            }
        }
        else
        { // c不为质数，将c转化为多个质数
            for (long long p = 2; p <= c; p++)
            {
                if (prime(p))
                {
                    while (c % p == 0)
                    {
                        dd[l - 1][p] += b;
                        dd[r][p] -= b;
                        c = c / p;
                        if (max < p)
                        {
                            max = p;
                        }
                    }
                }
            }
        }
    }
    // 枚举所有质数
    for (long long i = 2; i <= max; i++)
    {
        long long k = 0;
        long long min = dd[0][i];
        for (long long j = 0; j < n; j++)
        {
            k = k + dd[j][i]; // 求出第j个数的有多少个质数
            if (min > k)
            {
                min = k;
            }
        }
        res = res * P(i, min, 1000000007) % 1000000007;
    }
    cout << res << endl;
    return 0;
}