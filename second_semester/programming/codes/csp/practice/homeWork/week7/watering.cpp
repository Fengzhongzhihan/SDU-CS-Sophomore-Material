//
// Created by Lenovo on 2024-04-12.
//
#include "bits/stdc++.h"
using namespace  std;
int t, n;
double width, length;
const int N = 2e4 + 10;

struct Range{
    double l, r;
    bool operator < (const Range& a)const {
        return l < a.l; // 左端点排序
    }
}Ranges[N];

int greedy(int idx) {
    int res = 0; bool success = false;
    double st = 0, ed = length;
    for (int i = 0 ; i < idx; i++) {
        double r = -2e9;
        int j = i ;
        while (j < n && Ranges[j].l <= st) { // 找到能覆盖的最大右端点区间
            if (r < Ranges[j].r) {
                r = Ranges[j].r;
            }
            j++;
        }

        if (r < st) {
            return -1;
        }
        res ++; // 找到一个区间
        if (r >= ed) {
            success = true;
            break;
        }
        //更新st
        st = r;
        i = j - 1;
    }

    if (!success) {
        return -1;
    }
    return res;
}

int main() {
    t = 1;
    while (t--) {
        int idx = 0;
        cin >> n >> length >> width;
        for (int i = 0 ; i < n ; i++) {
            double pos, radius;
            double l ,r;
            cin >> pos >> radius;
            if (radius <= width / 2) {
                continue;
            }
            double len = sqrt(radius * radius - width * width / 4.0);
            l = pos - len, r = pos + len;
            Ranges[idx++] = {l, r};
        }
        sort(Ranges, Ranges + idx);
        cout << greedy(idx) << endl;
    }

    return 0;
}