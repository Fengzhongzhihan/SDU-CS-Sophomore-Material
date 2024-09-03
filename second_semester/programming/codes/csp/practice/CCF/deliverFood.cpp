//
// Created by Lenovo on 2024-03-13.
//
#include "bits/stdc++.h"
using namespace std;
const int  N = 1e3 + 10;
int n, m, k, d;
int g[N][N]; // 0表示能走, -1表示不能走, 其余数字表示客户的订单量
typedef pair <int, int > PII;
typedef long long LL;
int dis[N][N];
queue<PII> q;

int main() {
    cin >> n >> m >> k >> d;
    memset(dis, -1, sizeof(dis));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        //把分店都放进来
        q.push({x, y});
        dis[x][y] = 0;
    }

    for (int i = 0; i < k; i++ ) {
        int x, y , c;
        cin >> x >> y >> c;
        g[x][y] += c;
    }

    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = -1;
    }

    LL res = 0;
    int dx[] = {-1, 0 , 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        //扩展周围
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            //合法, 能走
            if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] != -1 && dis[x][y] == -1) {
                dis[x][y] = dis[t.first][t.second] + 1;
                res += g[x][y] * dis[x][y];
                q.push({x, y});
            }
        }
    }

    printf("%lld\n", res);
    return 0;
}