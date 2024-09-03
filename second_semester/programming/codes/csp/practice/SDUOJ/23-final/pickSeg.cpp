
#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
const int N = 1e6 + 10;
int T;
int maxLength[N];//以i为右端点的最长区间长度
struct range{
    int l, r, len;
}ranges[N];
bool compare(range a , range b) {
    return a.r < b.r;
}

bool comparel(range a, range b) {
    return a.l < b.l;
}

void solve() {
    //按右端点排序
    sort(ranges + 1, ranges + n + 1, compare);
    int l = ranges[1].l, r = ranges[1].r, len = ranges[1].len;
    for (int i = 1; i <= r; i++) {
        maxLength[i] = len;
    }
    for (int i = 2; i <= n; i++) {
        auto t = ranges[i];
        maxLength[t.r] = max(t.len, maxLength[r]);
        //更新r到t.r之间的maxLength
        for (int j = r + 1; j < t.r; j++) {
            maxLength[j] = maxLength[r];
        }
        l = t.l, r = t.r, len = t.len;
    }

    //按左端点排序
    sort(ranges + 1, ranges + n + 1, comparel);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        auto t = ranges[i];
        res = max(res, maxLength[t.l] + t.len);
    }
    cout << res << endl;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].len = ranges[i].r - ranges[i].l;
    }
    solve();
}