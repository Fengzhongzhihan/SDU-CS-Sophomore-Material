//
// Created by Lenovo on 2024-06-14.
//
#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m;
const int N = 210;
struct point{
    double x, y, z;
}p[N];
bool st[N];
signed main() {
    cin >>  n >> m;
    for (int i = 1 ; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    st[1] = true;
    for (int i = 2; i <= m; i++) {
        double res = 0;
        int bestP;
        //枚举所有栖息地
        for (int j = 1; j <= n; j++) {
            double minVal = 0x3f3f3f3f;
            if (st[j]) continue;
            //枚举所有已经选择的栖息地
            for (int k = 1; k <= n; k++) {
              if (!st[k]) continue;
              //j栖息地到k栖息地的距离
              double dis = sqrt((p[j].x - p[k].x) * (p[j].x - p[k].x) + (p[j].y - p[k].y) * (p[j].y - p[k].y)
                      + (p[j].z - p[k].z) * (p[j].z - p[k].z));
                if (dis < minVal) {
                    minVal = dis;
                }
            }
            if (minVal > res) {
                res = minVal;
                bestP = j;
            }
        }
        st[bestP] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i]) {
            printf("%lld ", i);
        }
    }
    return 0;
}