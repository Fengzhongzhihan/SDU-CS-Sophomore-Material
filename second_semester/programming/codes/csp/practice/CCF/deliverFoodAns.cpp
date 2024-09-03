#include "bits/stdc++.h"
using namespace std;
const int  N = 1e3 + 10;
int n, m, k, d;
int g[N][N]; // 0表示能走, -1表示不能走, 其余数字表示客户的订单量
struct Point {
    int x, y, d;
};
typedef long long LL;
queue<Point> q;

int main() {
    cin >> n >> m >> k >> d;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        //把分店都放进来
        q.push({x, y, 0});
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

    long long  res = 0;
    int dx[] = {-1, 0 , 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        //扩展周围
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            //合法, 能走
            if (x >= 1 && x <= n && y >= 1 && y <= n && g[x][y] != -1) {
                res += g[x][y] * (t.d + 1);
                q.push({x, y, t.d + 1});
                g[x][y] = -1;
            }
        }
    }

    cout << res;
    return 0;
}