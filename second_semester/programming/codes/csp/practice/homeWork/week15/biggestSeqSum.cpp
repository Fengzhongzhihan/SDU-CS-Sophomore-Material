//
// Created by Lenovo on 2024-06-07.
//
#include "bits/stdc++.h"
using namespace std;
#define  int long long
const int N = 1e6 + 10;
int a[N], s[N];
int n, m;
deque<int>q;
signed main()  {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int res = LONG_LONG_MIN;
    //找出最大和的子序列
    int idx = 0;
    for (int i = 1; i <= n; i++) {
     //从S[i - m]到S[i - 1]中找出最小的S[j]
//        int minS = s[minIdx];
//        for (int j = minIdx; j <= i; j++) {
//            minS = min(minS, s[j]);
//        }
        //使用单调队列维护最小值
        while (q.size() && q.back() > s[i - 1]) {
            q.pop_back();
        }
        q.push_back(s[i - 1]);
        if (i - m - 1 >= 0 && q.front() == s[i - m - 1]) {
            q.pop_front();
        }
        res = max(res, s[i] - q.front());
    }
    cout << res;
}