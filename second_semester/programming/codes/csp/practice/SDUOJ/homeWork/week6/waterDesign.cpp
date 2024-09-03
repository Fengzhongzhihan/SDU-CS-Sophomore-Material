//
// Created by Lenovo on 2024-04-03.
//
#include "bits/stdc++.h"
using namespace  std;
typedef long long LL;
const LL N = 2e5 + 10;
LL n, m, k;
LL p[N] ;

struct edge{
    LL a, b, w;
}edges[N];

//找到x节点的集合编号, 并进行路径压缩
LL find(LL x){
    if (p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}

//初始化
void init() {
    for (LL i = 0 ; i <= n; i++ ) {
        p[i] = i;
    }
}
bool cmp (edge a, edge b) {
    return a.w < b.w;
}
LL kruskal () {
    LL sw = 0;
    LL num = n;
    //从小到大遍历每条边
    for (LL i = 0 ; i < n + m ; i++) {
        auto t = edges[i]; // 找到此时的边
        LL a = t.a, b = t.b, w = t.w;
        LL pa = find(a), pb = find(b);
        //这两个点可以连接
        if (pa != pb) {
            p[pb] = pa;
            sw += w;
            num--;
        }
    }
    return num * k + sw;
}

int main() {
    cin >> n >> m >> k;
    init();
    for (LL i = 1 ; i <= n ; i++) {
        edges[i - 1] = {0, i, k};
    }
    for (LL i = n ; i < n + m; i++) {
        LL a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    sort(edges, edges + n + m, cmp);

    cout << kruskal() << " ";
}