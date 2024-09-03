#include "bits/stdc++.h"
using namespace std;

int n;
const int N = 10010, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int ans = 0;
bool st[N];
int diameter_count = 0;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dfs(int u) {
    int dist = 0; // 向下的最大距离
    int d1 = 0, d2 = 0; // 最长路和次长路
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        int d = dfs(j) + w[i]; // 以j为根的子树向下的最大距离
        dist = max(dist, d); // 以u为根的子树向下的最大距离
        if (d >= d1) {
            d2 = d1; d1 = d;
        } else {
            if (d >= d2) {
                d2 = d;
            }
        }
    }
    // 更新最大直径长度
    if (d1 + d2 > ans) {
        ans = d1 + d2;
        diameter_count = 1; // 发现新的直径长度，重置计数器
    } else if (d1 + d2 == ans) {
        diameter_count++; // 当前路径长度等于直径长度，增加计数器
    }
    return dist; // 以u为根的子树向下的最大距离
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
    dfs(1);
    cout << ans << " " << diameter_count;
}
