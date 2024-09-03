//
// Created by Lenovo on 2024-03-30.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e5 + 10;
struct matrix {
    int height, index;
};
int a[N], l[N], r[N];
matrix matrixs [N];
stack<matrix> stk;
int n ;
long long res = 0;
int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        matrixs[i] = {a[i], i};
    }
    // 单调栈确认每个点左侧第一个小于该点的坐标
    for (int i = 0; i < n ; i++) {
        auto t = matrixs[i];
        while (stk.size() && stk.top().height >= t.height) {
            stk.pop();
        }
        if (stk.size()) {
            l[i] = stk.top().index;
        }
        else {
            l[i] = -1;
        }
        stk.push(matrixs[i]);
    }
    // 单调栈确认每个点右侧第一个小于该点的坐标
    while(stk.size()) {
        stk.pop();
    }
    for (int i = n - 1; i >= 0 ; i--) {
        auto t = matrixs[i];
        while (stk.size() && stk.top().height >= t.height) {
            stk.pop();
        }
        if (stk.size()) {
            r[i] = stk.top().index;
        }
        else {
            r[i] = n;
        }
        stk.push(matrixs[i]);
    }
    // 按顺序找, 找出每一个矩形左侧第一个小于他的矩形和右侧第一个小于他的矩形
    for (int i = 0 ; i < n ; i++) {
        long long  height = matrixs[i].height;
        long long  bottom = r[i] - l[i] - 1;
        res = max (res, height * bottom);
    }

    cout << res ;
    return 0;
}