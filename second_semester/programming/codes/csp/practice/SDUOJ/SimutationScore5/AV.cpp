//
// Created by Lenovo on 2024-06-07.
//
//#include "bits/stdc++.h"
//using namespace std;
//#define  int long long
//const int N = 5010;
//int g[N][N];
//bool st[N];
//int minW[N];
//bool sure[N];
//int n, m;
//int res = 0;
//typedef pair<int ,int >PII;
//void add(int a, int b, int c) {
//    g[a][b] = min (g[a][b], c);
//}
//
//void bfs() {
//    queue<PII> q;// x: 编号， y : 到根结点边数
//    q.push({1, 0});
//    st[1] = true;
//    memset(minW, 0x3f3f3f3f, sizeof(minW));
//    minW[0] = 0;
//    int nowEdge = 1;
//    while (q.size()) {
//        auto t = q.front();
//        //遍历当前新加入的所有节点
//        int u = t.first, edgeNum = t.second;
//        res += edgeNum * minW[u];
//        q.pop();
//        //遍历t的邻接点
//        for (int j = 1 ; j <= n; j++) {
//            if (g[u][j] != INT_MAX) {
//                minW[j] = min(minW[j], g[u][j]);
//                if (!st[j]) {//如果还没加入队列， 则加入队列
//                    st[j] = true;
//                    q.push({j, edgeNum + 1});
//                }
//            }
//        }
//    }
//}
//
//void solve() {
//    bfs();
//}
//
//signed main() {
//    cin >> n >> m;
//    for (int i = 1 ; i <= n; i++) {
//        for (int j = 1 ; j <= n ; j++) {
//            g[i][j] = INT_MAX;
//        }
//    }
//    for (int i = 0 ; i < m; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        add(a, b, c);
//        add(b, a, c);
//    }
//
//    solve();
//    cout << res;
//}
#include "bits/stdc++.h"
using namespace std;
#define  int long long
int n;
const int N = 5010;
int a[N], v[N];
int res = 0;
//x代表a中已经枚举的数的个数, sum表示总和
int dfs(int u, int x, int i, int sum) {
    if (x == i || u > n) {
        return sum;
    }
    int d1 = dfs(u + 1, x + 1, i, sum + a[u] * v[x + 1]);//选
    int d2 = dfs(u + 1, x, i, sum);//不选
    return max(d1, d2);
}

signed main() {
    cin >> n;
    for (int i =1 ; i <= n ; i++) {
        cin >> v[i];
    }
    for (int i =1 ; i <= n ;  i++) {
        cin >> a[i];
    }
    //v中前i个元素和a中前i个元素
    for (int i =1 ; i <= n ; i++) {
        res = max(res, dfs(1, 0, i, 0));
    }
    cout << res;
}