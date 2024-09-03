//
// Created by Lenovo on 2024-04-22.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 510;
int g[N][N];// 邻接矩阵存储
bool st[N]; // 判断有无遍历过
int dis[N], cnt[N]; // dis记录最短路 cnt记录当前点最短路经过的边数
int n, n1, n2;

void add (int a, int b, int c) {
   g[a][b] = min (c, g[a][b]);
}

//对于每个样例都进行初始化
void init() {
    memset(g, 0x3f3f3f3f, sizeof(g));
    for (int i = 1; i <= n ; i++) {
        g[i][i] = 0;
    }

    memset(st, false, sizeof(st));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(cnt , 0, sizeof (cnt));
}

bool spfa(){
    queue<int> q;
    for (int i = 1; i <= n ; i++) { //有孤立点的情况, 我们选用一个超级源点
        q.push(i);
        dis[i] = 0;
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false; // 更新状态, 此时点不为成功松弛的点
        for (int j = 1; j <= n ; j++) {
            if (dis[j] > g[t][j] + dis[t]) {
                dis[j] = g[t][j] + dis[t];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n ) { // 此时有n + 1个点, 如果最短路的边数 > n + 1 -1 = n,则返回true
                    return true;
                }
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return false;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        init();
        cin >> n >> n1 >> n2;
        for (int i = 0 ; i < n1 ; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            add(b, a, c);
        }
        for (int i = 0 ; i < n2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c); // 此时会覆盖之前的某一条单向边
        }

        if (spfa()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}