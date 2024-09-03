//
// Created by Lenovo on 2024-06-09.
//
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
PII ranges[N];
int n;
int cnt = 0;

void solve() {
    int ed = -2e9;
    for (int i = 0  ; i < n ; i++) {
        if (ed == -2e9) {
            ed = ranges[i].second;
            cnt++;
        }else {
            if (ranges[i].first >= ed) {
                cnt++;
                ed = ranges[i].second;
            }else {
                ed = min (ed, ranges[i].second);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ;  i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    sort(ranges, ranges + n);
    solve();
    cout << cnt << endl;
    return 0;
}