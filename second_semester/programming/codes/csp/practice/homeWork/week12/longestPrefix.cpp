//
// Created by Lenovo on 2024-05-15.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N], b[N], s[N]; // f[i]表示前i个数的最长上升子序列 s[i]表示前i个数的最长上升子序列的最大值

int lowbit(int x) {
    return x & -x;
}

int sum(int p) {//求s[1]~s[p]的最大值
    int res = 0;
    for (int i = p ; i ; i -= lowbit(i)) {
        res = max(res, s[i]);
    }
    return res;
}

void upd(int p, int x) {// 更新s[p]的值
    for (int i = p ; i <= n ; i += lowbit(i)) {
        s[i] = max(s[i], x);
    }
}

int main() {
    // 2 1 1 4 7 5 6
    // 1 2 4 5 6 7
    //
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    memcpy(b, a, sizeof(a));
    sort(b, b + n);
    //去重, 求出b的大小m
    int m = unique(b, b + n) - b;
    int res = 0;
    for (int i = 0; i < n ; i++) {
        // 求出a[i]在b中的位置
        // 枚举上，这个过程相当于求解枚举上，这个过程相当于求解小于A[i]的元素的f[i]最大值
        // 小于A[i]使用映射解决
        // f[i]用树状数组维护
        int k = lower_bound(b, b + m, a[i]) - b + 1;
        int t = sum(k - 1) + 1;//求出前k-1个数的最长上升子序列的最大值
        res = max(res, t);
        upd(k, t);//更新s[k]的值
    }
    cout << res;
    return 0;
}