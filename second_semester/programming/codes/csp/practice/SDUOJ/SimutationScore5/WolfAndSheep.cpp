//
// Created by Lenovo on 2024-05-13.
//
#include "bits/stdc++.h"
using namespace std;
int n, m, p, qq, t;
const int N = 110;
bool st[N][N][2]; // 羊. 狼. 1在左岸, 0在右岸

struct Node { // 存储左岸的数目
    int s, w, c; // 羊. 狼. 1在左岸, 0在右岸
    int cnt; // 步数
};
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> p >> qq;
        for (int i = 0 ; i < N; i++) {
            for (int j = 0; j < N; j++) {
                st[i][j][0] = false;
                st[i][j][1] = false;
            }
        }
        queue<Node> q;
        q.push({n, m, 1, 0});
        st[n][m][1] = true;
        bool isWork = false;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            int s = t.s, w = t.w, c = t.c, cnt = t.cnt;
            //左侧没有羊了, 则到达了终点
            if (s == 0) {
                cout << cnt << endl;
                isWork = true;
                break;
            }
            //转移
            for (int i = 0 ; i <= p; i++) { // 上船羊
                for (int j = 0; j <= p; j++) {// 上船狼
                    if (i + j > p) {
                        continue;
                    }
                    int space = p - i - j; // 空位数
                    //左 -> 右
                    if (c == 1) {
                        if (s - i < 0 || w - j < 0) {// 超出边界
                            continue;
                        }
                        Node newNode = {s - i, w - j, 0, cnt + 1}; // 人不在左边, 在右侧, 需要确保左侧安全
                        if (newNode.w > newNode.s + qq && newNode.s != 0) { // 左侧的狼 > 羊且有羊, 会吃羊
                            continue;
                        } else {
                            if (!st[newNode.s][newNode.w][0]) {
                                st[newNode.s][newNode.w][0] = true;
                                q.push(newNode);
                            }
                        }
                    } // 右->左
                    else {
                        if (s + i > n || w + j > m) {// 超出边界
                            continue;
                        }
                        Node newNode = {s + i, w + j, 1, cnt + 1}; // 人不在右边, 在左侧, 需要确保右侧安全
                        if ((m - newNode.w) > (n - newNode.s) + qq && (n - newNode.s) != 0) { // 右侧的狼 > 羊且有羊, 会吃羊
                            continue;
                        } else {
                            if (!st[newNode.s][newNode.w][1]) {
                                st[newNode.s][newNode.w][1] = true;
                                q.push(newNode);
                            }
                        }
                    }
                }
            }

        }
        if (!isWork) {
            cout << "-1" << endl;
        }
    }
    return 0;
}