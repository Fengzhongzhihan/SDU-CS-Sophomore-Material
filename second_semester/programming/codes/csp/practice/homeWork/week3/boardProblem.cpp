//
// Created by Lenovo on 2024-03-14.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 10;
int n, k;
char g[N][N];
bool col[N];
int res;

//遍历到第u行, 一共选了kk个数
void dfs (int u, int kk) {
    if (kk == k) {
        res++;
        return;
    }
    if (u >= n) {
        return;
    }

    //遍历每一列
    for (int j = 0; j < n; j++) {
        //可走, 列都没有走过,
        if(g[u][j] == '#' && !col[j]) {
            col[j] = true;
            dfs(u + 1, kk + 1);
            col[j] = false;
        }
    }
    //不选这一行
    dfs(u + 1, kk);
}
int main() {
    while (1) {
        cin >> n >> k;
        if (n == -1 && k == -1) {
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n ; j++) {
                cin >> g[i][j] ;
            }
        }
        res = 0;
        memset(col, false, sizeof(col));
        dfs(0, 0);
        cout << res << endl;
    }

    return 0;
}