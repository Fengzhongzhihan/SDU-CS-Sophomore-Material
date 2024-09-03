#include "bits/stdc++.h"
using namespace std;
// 只能针对非负权边
int n;
const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int ans = 0;
int t = 0; // 记录第一次dfs最远的点
int cnt = 0;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dfs(int u, int father, int dis) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs (j, u, dis + w[i]);
    }
    if (ans < dis) {
        ans = dis;
        t = u;
    }
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b;
        add(a, b, 1);
        add(b, a, 1);
    }
    dfs(1, -1, 0);
    dfs(t, -1, 0);
    cout << ans << endl;
}
