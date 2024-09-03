//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 6010;
int h[N],ne[N],e[N], idx;
bool has_father[N];
int n;
int happy[N];
int f[N][2] ; // f[i][0]代表选择i节点，f[i][1]代表不选择i节点
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    f[x][0] = happy[x];
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[x][1] += max(f[j][0], f[j][1]);
        f[x][0] += f[j][1];
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> happy[i];
    }
    for (int i = 0 ; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_father[a] = true;
    }

    int root = 1;
    while (has_father[root]) root++;

    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}