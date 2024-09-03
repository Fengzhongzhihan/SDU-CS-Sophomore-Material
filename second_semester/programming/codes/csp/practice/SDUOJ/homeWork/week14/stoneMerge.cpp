//
// Created by Lenovo on 2024-05-29.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 310;
int f1[N][N], f2[N][N]; // f1[i][j]表示区间[i, j]合并成一个石头的最大值, f2[i][j]表示区间[i, j]合并成一个石头的最小值
int n;//石头的数量
int a[N], tmp[N], s[N]; // a[i]表示第i个石头的价值, tmp[i]表示第i个石头的价值, s[i]表示前i个石头的价值和
int res1, res2;//res1表示最大值, res2表示最小值
//f1[i][j]表示区间[i, j]合并成一个石头的最大值
void dp() {
    //初始化数组
    memset(f1, 0, sizeof f1);
    memset(f2, 0x3f3f3f3f, sizeof f2);
    for (int i = 1; i <= n; i++) {
        f2[i][i] = 0;
    }
    //动态规划
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i ; k < j; k++) {
                f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + s[j] - s[i - 1]);
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

}

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    res1 = 0, res2 = INT_MAX;
    for (int i = 1; i <= n; i++) {
        //初始化tmp数组, 将圈划分为两部分
        int idx = 0;
        for (int j = i; j <= n; j++) {
            tmp[++idx] = a[j];
        }
        for (int j = 1; j < i ; j++) {
            tmp[++idx] = a[j];
        }
        //初始化好了tmp数组, 初始化s数组前缀和
        for (int j = 1; j <= n; j++) {
            s[j] = s[j - 1] + tmp[j];
        }
        //初始化好了s数组, dp
        dp();
        res1 = max(res1, f1[1][n]);
        res2 = min(res2, f2[1][n]);
    }
    cout << res2 << endl << res1;
}