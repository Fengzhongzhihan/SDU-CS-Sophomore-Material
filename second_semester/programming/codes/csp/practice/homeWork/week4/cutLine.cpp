//
// Created by Lenovo on 2024-03-20.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e5 + 10;
int rope[N];
int n, k;
double sumLength = 0 ;

bool check(double x) {
    int cnt = 0 ;
    for (int i = 0 ; i <  n ; i++) {
        int num = rope[i] / x;
        cnt += num;
    }
    //表示可以满足要求, 绳子可以再长些
    if (cnt >= k) {
        return true;
    }
    //表示截取的每段长度长了
    return false;
}

int main() {
    cin >> n >> k;

    // n段绳子, 要截出k段长度相同的绳子
    for (int i = 0 ; i < n ; i++) {
        cin >> rope[i];
        sumLength += rope[i];
    }

    sort(rope, rope + n, greater<int>());

    // 最长的长度 : sumLength / k, 最短的长度 : 0
    double l = 0 , r = sumLength / k;
    while (r - l > 1e-6) {
        double x = (l + r) / 2;
        if (check(x)) {
            l = x;
        }
        else {
            r = x;
        }
    }

    cout <<  r << endl;
}