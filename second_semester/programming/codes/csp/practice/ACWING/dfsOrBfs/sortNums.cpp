//
// Created by Lenovo on 2024-06-05.
//
#include "bits/stdc++.h"
using namespace std;
int n;
const int N = 8;
int path[N];
bool st[N];

void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            path[x] = i;
            st[i] = true;
            dfs(x + 1);
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
}