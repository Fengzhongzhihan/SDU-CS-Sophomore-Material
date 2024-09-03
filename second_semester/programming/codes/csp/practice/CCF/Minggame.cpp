//
// Created by Lenovo on 2024-03-16.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 110;
const int M= 1e4;
int n, m, t;
typedef  pair <int, int > PII;
//坐标 -> 时间段
map<PII, PII> mp;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[N][N][M];

int bfs() {
    //坐标, 时间
    queue<pair<PII, int> > q;
    q.push({{1, 1}, 0});
    while (q.size()) {
        auto k = q.front();
        q.pop();
        int time = k.second;
        int xx = k.first.first;
        int yy = k.first.second;
        if (xx == n && yy == m) {
            return time;
        }
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + xx;
            int y = dy[i] + yy;
            if (x < 1 || x > n || y < 1 || y > m) {
                continue;
            }
            //没有危险点
            if (!visit[x][y][time + 1] && x >= 1 && x <= n && y >= 1 && y <= m) {
                q.push({{x, y}, time + 1});
                visit[x][y][time + 1] = true;
            }
        }
    }

    return 0;
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < t; i ++) {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        for (int j = a; j <= b; j++)
        visit[r][c][j] = true;
    }

    cout << bfs();

    return 0;
}