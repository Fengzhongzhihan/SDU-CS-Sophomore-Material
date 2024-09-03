//
// Created by Lenovo on 2024-04-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int p[N];
int n, m;

//找到x节点的集合编号, 并进行路径压缩
int find(int x) {

    if (p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}
int main() {
    cin >> n >> m;
    int cnt = n - 1; // 此时需要建立的边的个数, 初始化为顶点个数 - 1
    //初始化并查集
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        // 如果a == b ,则是自环, 不需要处理
        if (a == b) {
            cout << cnt << endl;
            continue;
        }
        int pa = find(a) ;
        int pb = find(b);
        //代表两个顶点不在同一个集合中, 则连接成功
        if (pa != pb) {
            p[pa] = pb;//需要的边数-1
            cout << --cnt << endl;
        }
        else {
            cout << cnt << endl;
        }
    }

    return 0;
}