//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, st, ed;
struct Range{
    int l, r;
    bool operator< (const Range &W) const {
        return l < W.l;
    }
};
vector<Range> ranges;
bool isFind = false;

int main() {
    cin >> st >> ed >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
    }
    sort(ranges.begin(), ranges.end());
    int res = 0 ;
    int ss = st, ee = ed;
    for (int i = 0 ; i < n ; i++) {
        int r = -2e9;
        int j = i;
        while (j < n && ranges[j].l <= ss) {//左端点可以覆盖的, 取右端点最大值
            r = max(r, ranges[j].r);
            j++;
        }
        if (r == -2e9) {//不能覆盖
            isFind = false;
            break;
        }
        res ++;
        if (r >= ee) {
            isFind = true;
            break;
        }
        ss = r;
        i = j - 1;
    }
    if (!isFind) {
        cout << -1 << endl;}
    else {
        cout << res << endl;
    }
    return 0;
}