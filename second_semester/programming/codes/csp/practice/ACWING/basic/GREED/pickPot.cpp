//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n;
struct Range{
    int l, r;
    bool operator< (const Range &W) const {
        return l < W.l;
    }
};
vector<Range> ranges;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
    }
    sort(ranges.begin(), ranges.end());
    int cnt = 0;
    int ed = -2e9;
    for (auto range:ranges) {
        if (ed == -2e9) {
            ed = range.r;
            cnt++;
        }else {
            if (range.l > ed) {
                cnt ++;
                ed = range.r;
            }else {
                ed = min(ed, range.r);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}