//
// Created by Lenovo on 2024-03-13.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 310;
int n;
int d2[N];
int d1[N];
bool visit[N][N][N];

void dfs(int x) {
    if (x > n) {
        if ((d1[n] + d1[n - 1]) / 2 == d2[n]) {
            //输出
            for (int i = 1; i <= n; i++) {
                cout << d1[i] << " ";
            }
            ::exit(0);
        }
        return;
    }
    else {
        //对于d1[x]进行枚举
       if (x == 1) {
           for (int i = 1;i <= 300; i++) {
               d1[x] = i;
               dfs(x + 1);
           }
       }
        else if (x == 2) {
            for (int i = 0; i < 2; i++) {
                d1[x] = d2[x - 1] * 2 - d1[x - 1] + i;
                if (d1[x] > 0) {
                    dfs(x + 1);
                }
            }
        }
        else {
            if (visit[x][d1[x - 2]][d1[x - 1]]) {
                return;
            }
           visit[x][d1[x - 2]][d1[x - 1]] = true;
            for (int i = 0; i < 3; i++) {
                d1[x] = 3 * d2[x - 1] - d1[x - 1] - d1[x - 2] + i;
                if (d1[x] > 0) {
                    dfs(x + 1);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d2[i];
    }
    //从第一家开始枚举
    dfs(1);

    return 0;
}