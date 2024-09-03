//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
int n;
const int N = 1e5 + 10;
struct Range{
    int l, r;
    bool operator< (const Range &W) const {
        return l < W.l;
    }
};
priority_queue<int, vector<int>, greater<int>>q;
Range ranges[N];
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++ ) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    sort(ranges, ranges + n);
    q.push(ranges[0].r);
    for (int i = 1 ; i < n ; i++) {//遍历所有区间
        auto range = ranges[i];
        if (range.l > q.top()) {//更新最大的右端点
            q.pop();
            q.push(range.r);
        }else {
            q.push(range.r);
        }
    }
    cout << q.size();
    return 0;
}