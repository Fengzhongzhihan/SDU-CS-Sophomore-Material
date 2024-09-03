//
// Created by Lenovo on 2024-04-22.
//
#include "bits/stdc++.h"
using  namespace std;
const int N = 2010;
struct seg{
    int l, r;
    bool operator < (const seg& a) {
        return l < a.r;
    }
};

seg hSegs[N];
seg wSegs[N];
int ans;

int main() {
    int n;
    cin >> n;
    int a, b;
    for (int i = 0 ; i < n ; i++) {
        cin >> a >> b;
        hSegs[i] = {a, b};
    }

    for (int i = 0 ; i < n ; i++) {
        cin >> a >> b;
        wSegs[i] = {a, b};
    }

    sort(hSegs, hSegs + n);
    sort(wSegs, wSegs + n);

    for (int i = 0 ; i < n ; i++) {
        auto t = wSegs[i];
        for (int j = 0 ; j < n ; j++) {
            auto m = hSegs[j];
            //区间不相交
            if (m.r < t.l || m.l > t.r) {
                continue;
            }
            else {
                if (m.l >= t.l) {
                    ans += min (m.r, t.r) - m.l;
                }
                else {
                    ans += min (m.r, t.r) - t.l;
                }
            }
        }
    }

    cout << ans ;
}