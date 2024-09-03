//
// Created by Lenovo on 2024-05-13.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int n, m;
const int N = 2e5 + 10;
ll a[N], s[N];

int main() {
    cin >> n >> m;
    ll ans = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == 0) {
        // 1 2 3 4 5
        // |i 2 3 4 5
        // 1 2 3 4 5|i
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            ll l = s[i - 1];
            ll r = s[n] - s[i - 1];
            ans = min(ans, max(l, r));
        }
        cout << ans << endl;
    } else {
        for (int i = 1; i <= n + 1 ; i++) {
            priority_queue<ll>lHeap, rHeap;
            ll l = 0, r = 0;
            for (int j = 1; j <= n; j++) {
                if (j < i) {
                    lHeap.push(a[j]);
                    l += a[j];
                } else  {
                    rHeap.push(a[j]);
                    r += a[j];
                }
            }
            //m个超级渔网
            for (int mm = 0 ; mm < m; mm++) {
                if (l > r) {
                    l -= lHeap.top();
                    lHeap.pop();
                }
                else {
                    r -= rHeap.top();
                    rHeap.pop();
                }
            }
            ans = min (ans, max(l, r));
        }

        cout << ans << endl;
    }
}