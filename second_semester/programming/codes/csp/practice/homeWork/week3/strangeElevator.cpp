//
// Created by Lenovo on 2024-03-13.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 410;
int n, a, b;
int k[N];
bool st[N];

int bfs() {
    // 第一个存储楼层数, 第二个存储距离(操作次数)
    queue<pair<int, int >> q;
    //每次都要初始化, 因为有多次输入和输出
    memset(st, false, sizeof(st));
    //将初始状态放入队列中
    q.push({a, 0});
    st[a] = true;
    //套用bfs模板
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int u = t.first, dis = t.second;
        //如果找到了目标点, 返回dis即可
        if (u == b) {
            return dis;
        }
        //更新两个周边点, up和down
        int up = u + k[u];
        int down = u - k[u];
        //如果没有遍历过(到达过这层楼), 则放入队列
        if (!st[up] && up >= 1 && up <= n) {
            q.push({up, dis + 1});
            st[up] = true;
        }
        if (!st[down] && down >= 1 && down <= n) {
            q.push({down, dis + 1});
            st[down] = true;
        }
    }
    //如果没有找到, 则返回-1
    return -1;
}

int main() {
    while (1) {
        //起始状态A, 结束状态B
        cin >> n ;
        if (n == 0) {
            break;
        }
        cin >> a >> b;
        for (int i = 1; i <= n ; i++) {
            cin >> k[i];
        }
        cout << bfs() << endl;
    }
    return 0;
}