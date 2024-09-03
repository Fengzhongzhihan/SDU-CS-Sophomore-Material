//
// Created by Lenovo on 2024-03-12.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e4 + 10;
bool g[N][N];
bool row[N];
bool col[N];
int n, m;
int k, t;
int x = 1, y = 1;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    if (g[1][1]) {
        cnt++;
        g[1][1] = false;
    }
    cin >> t;
    while(t--) {
        char op; int step;
        cin >> op >> step;
        if (op == 'W') {
            if (col[y]) {
                x -= step;
                continue;
            }
            int des = x - step;
            for (int i = des; i <= x; i++) {
                if (g[i][y]) {
                    cnt++;
                    g[i][y] = false;
                }
            }
            x -= step;
            bool check = false;
            for (int i = 0; i <= n; i++) {
                if (g[i][y]) {
                    check = true;
                }
            }
            if (!check) {
                col[y] = true;
            }
        }
        else if (op == 'A') {
            if (row[x]) {
                y -= step;
                continue;
            }
            int des = y - step;
            for (int j = des; j <= y; j++) {
                if (g[x][j]) {
                    cnt ++;
                    g[x][j] = false;
                }
            }
            y -= step;
            bool check = false;
            for (int i = 0 ; i <= m; i++) {
                if (g[x][i]) {
                    check = true;
                }
            }
            if (!check) {
                row[x] = true;
            }
        }
        else if (op == 'S') {
            if (col[y]) {
                x += step;
                continue;
            }
            int des = x + step;
            for (int i = x; i <= des; i++) {
                if (g[i][y]) {
                    cnt++;
                    g[i][y] = false;
                }
            }

            x += step;
            bool check = false;
            for (int i = 0; i <= n; i++) {
                if (g[i][y]) {
                    check = true;
                }
            }
            if (!check) {
                col[y] = true;
            }
        }
        else {
            if (row[x]) {
                y += step;
                continue;
            }
            int des = y + step;
            for (int j = y; j <= des; j++) {
                if (g[x][j]) {
                    cnt++;
                    g[x][j] = false;
                }
            }
            y += step;
            bool check = false;
            for (int i = 0 ; i <= m; i++) {
                if (g[x][i]) {
                    check = true;
                }
            }
            if (!check) {
                row[x] = true;
            }
        }
    }

    cout << cnt;
}