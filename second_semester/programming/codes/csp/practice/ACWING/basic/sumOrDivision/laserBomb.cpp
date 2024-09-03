//
// Created by Lenovo on 2024-06-04.
//
#include "bits/stdc++.h"
using namespace std;
int n, r;
const int N = 5010;
int s[N][N];

int query(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x + 1][y + 1] += w;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }
    int res = 0;
    r = min(r, 5001);
    for (int i = r; i <= 5001; i++ ) {
        for (int j = r; j <= 5001 ; j++) {
            res = max(res, query(i - r + 1, j - r + 1, i, j));
        }
    }
    cout << res;
    return 0;
}