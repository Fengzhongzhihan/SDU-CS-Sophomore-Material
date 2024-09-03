//
// Created by Lenovo on 2024-06-13.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e2 + 10;
int k, n;
int stx, sty, edx, edy;
int dx[]= {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int g[N][N];
bool st[N][N];

bool dfs(int x, int y) {
    if (x == edx && y == edy) return true;
    st[x][y] = true;
    for (int k = 0 ; k < 4; k++) {
        int a = x + dx[k], b = y + dy[k];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (g[a][b] || st[a][b]) continue;
        if (dfs(a, b)) return true;
    }
    return false;
}

int main() {
    cin >> k ;
    while(k--) {
        cin >> n;
        memset(st, 0, sizeof st);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                char c; cin >> c;
                if (c == '.') g[i][j] = 0;
                else if (c == '#') g[i][j] = 1;
            }
        }
        cin >> stx >> sty >> edx >> edy;
        if (g[stx][sty]|| g[edx][edy]) {
            cout << "NO" << endl;
            continue;
        }
        if(dfs(stx, sty)) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}