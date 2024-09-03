//
// Created by Lenovo on 2024-06-12.
//
#include "bits/stdc++.h"
using namespace std;
const int M = 1e6 + 10;
int m, p;
struct node{
    int l, r;
    int v;
}tr[4 * M];
int last = 0, n = 0;

//构建以u为根节点, l~r的线段树
void build(int u, int l, int r) {
    tr[u] = {l, r};
    if(l == r) return;
    int mid = l + r >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
}
//更新以u为根节点, x节点的值为v
void upd(int u , int x, int v){
    if (tr[u].l == tr[u].r) {
        tr[u].v = v;
        return;
    }
    else {
        int mid = tr[u].l  + tr[u].r >> 1;
        //找到x所在子树
        if (x <= mid) upd(u * 2, x, v);
        else upd(u * 2 + 1, x, v);
        //此时已经更新好了子节点
        tr[u].v = max(tr[u * 2].v, tr[u * 2 + 1].v);
    }
}

//返回以u为根节点l ~ r的最大值
int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].v;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid) {
        v = query(2 * u, l , r);
    }
    if (r > mid) {
        v = max(v, query(2 * u + 1, l, r));
    }
    return v;
}

int main(){
    cin >> m >> p;
    build(1, 1, m);
    for (int i = 0 ;i < m ; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l; cin >> l;
            last = query(1, n - l + 1, n);
            cout << last << endl;
        }else {
            int t; cin >> t;
            upd(1, n + 1, ((long long)t + last) % p);
            n++;
        }
    }
}