//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 10;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];
//遍历到第u行
void dfs(int u) {
    if (u == n) {
        for (int i = 0 ; i < n ; i++) {
            puts(g[i]);
        }
        cout << endl;
        return;
    }
    for (int i = 0 ; i < n ; i++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            g[i][j] = '.';
        }
    }
    cin >> n;
    dfs(0);
}