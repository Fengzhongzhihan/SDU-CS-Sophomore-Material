//
// Created by Lenovo on 2024-06-13.
//
#include "bits/stdc++.h"
using namespace std;
int n, m ,T;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int cnt = 0;
const int N = 10;
bool st[N][N];
void dfs(int x, int y, int step) {
    if (step == n * m - 1) {
        cnt++;
        return;
    }
    for (int i = 0 ; i < 8; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) continue;
        st[a][b] = true;
        dfs(a, b, step + 1);
        st[a][b] = false;
    }
}

int main() {
    cin >> T;
    while (T--) {
        memset(st, 0, sizeof st);
        cnt = 0;
        int x, y;
        cin >> n >> m >> x >> y;
        st[x][y] = true;
        dfs(x, y, 0);
        cout << cnt << endl;
    }
}