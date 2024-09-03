//
// Created by Lenovo on 2024-06-15.
//
#include "bits/stdc++.h"
using namespace std;
int n ;
const int N = 110;
int path[N];
bool st[N];

bool dfs(int u , int k) { //u表示当前层数, k表示限制搜索层数
    if (u == k) {
        return path[u - 1] == n;
    }
    memset(st, 0, sizeof st);
    for (int i = u - 1; i >= 0; i--) { //遍历所有组合
        for (int j = i; j >= 0; j--) {
            int s = path[i] + path[j];
            if (s > n || s <= path[u - 1] || st[s]) continue;
            path[u] = s;
            st[s] = true;
            if (dfs(u + 1, k)) return true;
        }
    }
    return false;
}

int main() {
    path[0] = 1;
    while (cin >> n, n) {
        int k = 1;
        while (!dfs(1, k)) {
            k++;
        }
        for (int i = 0 ;i  < k ;i++) {
            cout << path[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}