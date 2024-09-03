//
// Created by Lenovo on 2024-05-08.
//
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 10;
int d[MAXN * 4], a[MAXN];

void build(int x, int l ,int r) {
    if (l == r) {
        d[x] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build (x * 2, l, m);
    build (x * 2 + 1, m + 1, r);
    d[x] = d[x * 2] + d[x * 2 + 1];
}

int p ,v; // 将p位置 + v
void upd(int x, int l, int r) {
    if (l == r) {
        d[x] += v;
        return;
    }
    int m = (l + r) / 2;
    if (p <= m) {
        upd(x * 2, l, m);
    }
    else {
        upd(x * 2 + 1, m + 1, r);
    }
    d[x] = d[x * 2] + d[x * 2 + 1];
}
//查询 p1 ~ p2的最大值
int ask (int x, int l , int r, int p1, int p2) {
    if (l == p1 && r == p2) {
        return d[x];
    }
    int m = (l + r) / 2;
    if (p2 <= m) {
        return ask (x * 2, l, m, p1, p2);
    }
    else if (p1 > m) {
        return ask (x * 2 + 1, m + 1, r, p1, p2);
    }
    else {
        int left = ask(x * 2, l, m, p1, m); // p1 ~ m
        int right = ask (x * 2 + 1, m + 1, r, m + 1, p2);//m+1 ~ p2
        return left + right;
    }
}