//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> PII;
const int N = 160, INF = 0x3f3f3f3f;
double g[N][N];
int n;
PII s[N];

double len(PII a, PII b) {
    return sqrt(pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2));
}

void floyd() {
    for (int k = 1 ; k <= n ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int x, y;
        cin >> x >> y;
        s[i] = {x, y};
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j++) {
            char c; cin >> c;
            if (c == '0') {
                if (i != j)
                    g[i][j] = INF;
            }else {
                g[i][j] = len(s[i], s[j]);
            }
        }
    }
    floyd();
    //求出在同一个牧场里面的直径的最大值
    double ans1 = 0, ans2 = 0x3f3f3f3f;
    double maxDis[N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] != INF) {
                maxDis[i] = max(maxDis[i], g[i][j]);
            }
            ans1 = max(ans1, maxDis[i]);
        }
    }
    //求出在不同牧场之间的最小值
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (g[i][j] == INF) {
                ans2 = min(ans2, maxDis[i] + maxDis[j] + len(s[i], s[j]));
            }
        }
    }
    double ans = max(ans1, ans2);
    printf("%.6lf", ans);
}