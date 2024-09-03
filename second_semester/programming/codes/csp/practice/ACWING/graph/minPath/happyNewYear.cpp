#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int e[N], ne[N], h[N], w[N], idx;
bool st[N];
int n , m, s[6]; // s[i]代表第i个目的地的编号
int res = 0x3f3f3f3f;
int d[6][N];// d[i][j]表示从下标i到编号j的最短距离

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa(int x, int dist[]) {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}


signed main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    s[0] = 1;
    for (int i = 1; i <= 5 ;i++) {
        cin >> s[i];
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    memset(d, 0x3f3f3f3f, sizeof d);
    for (int i = 0 ; i < 6; i++) {
        spfa(s[i], d[i]);
    }
    //枚举所有的顺序
    vector<int> path = {1, 2, 3, 4, 5};//代表s下标的全排列, 对应5个目的地
    do {
        int sum = d[0][s[path[0]]];//从1到第一个目的地
        for (int i = 0 ; i < 4; i++) {
            sum += d[path[i]][s[path[i + 1]]];
        }
        res = min(res, sum);
    } while (next_permutation(path.begin(), path.end()));

    cout << res;
}