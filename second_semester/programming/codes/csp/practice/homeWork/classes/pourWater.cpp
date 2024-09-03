//
// Created by Lenovo on 2024-03-17.
//
//
// Created by Lenovo on 2024-03-14.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 10;
int m, ca, cb, demand;
typedef  pair <int ,int > PII;
// 初始状态 (Ca Cb) , (Ca, 0), (0, Cb), (0, 0)
// 中间状态 (A B) -> (A, 0) / (0, B) / (0, A + B) / (A - (Cb - B), Cb) / (A + B, 0) / (Ca, b - (Ca - A)) / (Ca, B) / (A, Cb)
// 目标状态 (B == demand)

//每一个结点都对应着一个ans vector数组

struct node {
    int a, b;
    vector<int> ans;
};

int dis[N][N];

void bfs () {
    memset(dis , -1 , sizeof (dis));

    queue<node> q;
    node initialNode;
    initialNode.a = 0, initialNode.b = 0;
    q.push(initialNode);
    dis[0][0] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int a = t.a;
        int b = t.b;
        int d = dis[a][b];
        //如果b == demand 返回结果
        if (b == demand) {
            cout << t.ans.size() << " ";
            for (int i = 0;  i < t.ans.size(); i++) {
                cout << t.ans[i] << " ";
            }
            cout << endl;
            return;
        }

        PII op[] = {{0, b}, {a, 0}, {0, a + b}, {a - (cb - b), cb}, {a + b, 0}, {ca, b - (ca - a)}, {ca, b}, {a, cb}};
        for (int i = 0 ; i < 8; i++) {
            // a倒入b  a + b <= cb
            if (i == 2 && a + b > cb) {
                continue;
            }
            // a倒入b a + b > cb
            if (i == 3 && a + b <= cb) {
                continue;
            }
            // b倒入a a + b < ca
            if (i == 4 && a + b > ca) {
                continue;
            }
            // b倒入a a + b > ca
            if (i == 5 && a + b <= ca) {
                continue;
            }
            int x = op[i].first, y = op[i].second;
            if (dis[x][y] == -1) {
                node tmp = {x, y};
                tmp.ans = t.ans;
                dis[x][y] = d + 1;
                //记录前驱节点
                if (i == 6) tmp.ans.push_back(1);
                else if (i == 7) tmp.ans.push_back(2);
                else if (i == 0) tmp.ans.push_back(3);
                else if (i == 1) tmp.ans.push_back(4);
                else if (i == 4 || i == 5) tmp.ans.push_back(5);
                else tmp.ans.push_back(6);
                q.push(tmp);
            }
        }

    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m ;i++) {
        cin >> ca >> cb >> demand;
        bfs() ;
    }

    return 0;
}