//
// Created by Lenovo on 2024-05-23.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 5010;
int n, m;
int w[N], v[N];
int f[N][N];
bool chosen[N][N];

void solve() {
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= w[i]) {
                    if (f[i][j] < f[i - 1][j - w[i]] + v[i]) {
                        f[i][j] = f[i - 1][j - w[i]] + v[i];
                        chosen[i][j] = true;//选了第i个物品
                    }
                }
        }
    }
}

void printSolution() {
    int i = n, j = m;
    vector<int> ans;
    while (i > 0) {
        if (chosen[i][j]) {
            ans.push_back(i);
            j -= w[i];
        }
        i--;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    solve();
    cout << f[n][m] << endl;
    printSolution();
}