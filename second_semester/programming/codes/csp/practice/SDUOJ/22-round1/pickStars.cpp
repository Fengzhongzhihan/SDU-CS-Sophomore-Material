//
// Created by Lenovo on 2024-03-12.
//
#include "bits/stdc++.h"
using namespace  std;
typedef pair<int, int >PII;
int n, m;
int k, t;
set<PII> stars;
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
        stars.insert({a, b});
    }
    //如果起点有星星
    if (stars.count({1, 1}) != 0) {
        stars.erase({1, 1});
        cnt++;
    }
    cin >> t;
    while (t--) {
        char op;
        int step;
        cin >> op >> step;
        if (op == 'W') {
            while (step--) {
                x--;
                if (stars.count({x, y}) != 0) {
                    stars.erase({x, y});
                    cnt++;
                }
            }
        }
        else if(op == 'A') {
            while (step--) {
                y--;
                if (stars.count({x, y}) != 0) {
                    stars.erase({x, y});
                    cnt++;
                }
            }
        }
        else if (op == 'S') {
            while (step--) {
                x++;
                if (stars.count({x, y}) != 0) {
                    stars.erase({x, y});
                    cnt++;
                }
            }
        }
        else {
            while (step--) {
                y++;
                if (stars.count({x, y}) != 0) {
                    stars.erase({x, y});
                    cnt++;
                }
            }
        }

    }

    cout << cnt;
}