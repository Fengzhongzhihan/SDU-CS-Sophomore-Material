//
// Created by Lenovo on 2024-05-10.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
int m, mod, p, v;
int d[MAXN * 4], idx = 0; // 线段树

//void build(int x, int l ,int r) {
//    if (l == r) {
//        d[x] = a[l];
//        return;
//    }
//    int m = (l + r) / 2;
//    build (x * 2, l, m);
//    build (x * 2 + 1, m + 1, r);
//    d[x] = max(d[x * 2] , d[x * 2 + 1]);
//}
//将p位置 + v
void upd(int x, int l, int r, int p, int v) {
    if (l == r) {
        d[x] += v;
        return;
    }
    int m = (l + r) / 2;
    if (p <= m) {
        upd(x * 2, l, m, p, v);
    }
    else {
        upd(x * 2 + 1, m + 1, r, p, v);
    }
    d[x] = max(d[x * 2], d[x * 2 + 1]);
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
        return max(left, right);
    }
}
ll lastAns = 0;
int main () {
    cin >> m >> mod;
    for (int i = 0 ; i < m ; i++)
    {
        char op;
        scanf(" %c", &op);
        //点菜
        if (op == 'Q') {
            ll L; scanf("%lld", &L);
            ll ans = ask(1, 1, m, idx - L + 1, idx); // idx - L + 1 ~ idx的元素最大值
            printf("%lld\n", ans);
            lastAns = ans;
        }
            //加菜
        else {
            ll t ; scanf("%lld", &t);
            ll newt = (lastAns + t) % mod; //新的菜品味道
            //在idx处 + newt
            ++idx;
            upd(1, 1, m, idx, newt);//更新线段树
        }
    }
    return 0;
}