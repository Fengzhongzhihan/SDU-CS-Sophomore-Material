//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10, M = N << 1;
int h[N], e[M], ne[M], w[M], idx;
bool st[N]; int dist[N], cnt[N];
void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int n, k;
bool spfa() {//求最长路
    memset(dist, -0x3f3f3f3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    stack<int> q;
    q.push(0), dist[0] = 0, st[0] = true;
    while (q.size()) {
        int t = q.top();q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1) {//此时有n + 1个点
                    return true;
                }
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    //保证合理
    memset(h, -1, sizeof h);
    for (int i =1; i <= n; i++) {
        // x[i] - x[0] >= 1 求最小值, 找最长路
        add(0, i , 1);
    }
    for (int i = 0 ; i  < k; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        switch(x) {
            case 1:  // x[a] == x[b]
                add(a, b, 0);
                add(b, a, 0);
                break;
            case 2: // x[a] <= x[b] - 1  x[b] - x[a] >= 1
                add(a, b, 1);
                break;
            case 3://x[a] >= x[b]
                add(b, a, 0);
                break;
            case 4://x[a] >= x[b] + 1
                add(b, a, 1);
                break;
            case 5://x[a] <= x[b]
                add(a, b, 0);
                break;
            default:
                break;
        }
    }
    if (spfa()) {
        cout <<"-1" << endl;
    }else {
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            res += dist[i];
        }
        cout << res;
    }
    return 0;
}