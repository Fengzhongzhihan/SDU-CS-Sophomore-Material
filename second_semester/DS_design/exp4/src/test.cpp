//
// Created by Lenovo on 2024-05-06.
//

#ifndef NETWORKAMPIFIER_GRAPH_H
#define NETWORKAMPIFIER_GRAPH_H
#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 10;

class Node{
public :
    Node * parent;
    int press, lever, cnt;
    bool status;
    Node (Node *parent, int press, int lever, int cnt, bool status) : parent(parent), press(press), lever(lever), cnt(cnt), status(status) {}
    Node () {}
};

class compare{
public:
    bool operator()(const Node* a, const Node* b) {
        return a->cnt > b->cnt;
    }

};

class Graph{
public:
    int n, m, pMax;
    int e[N], h[N], ne[N], idx, w[N];
    int ans ;
    int inDegree[N],topS[N];
    int p[N];
    void add(int a, int b, int c) ;
    Graph(int n, int m, int pMax);
    bool status[N]; // 放置状态
    bool st[N]; // 选中状态
    void topSort() ;
    void solve1();
    void solve2();
    void dfs1(int l, int cnt);
    void branchBound();
};

void Graph::topSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        topS[++cnt] = t;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            inDegree[j]--;
            if (inDegree[j] == 0) {
                q.push(j);
            }
        }
    }
    if (cnt != n) {
        cout << "拓扑排序不存在" << endl;
    }
}

//回溯法
void Graph::solve1() {
    topSort();
    status[1] = true;
    p[1] = pMax;
    dfs1(2, 0);
}

//分支定界法
void Graph::solve2() {
    topSort();
    branchBound();
}

void Graph::add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
    inDegree[b]++;
}

Graph::Graph(int n, int m, int pMax) {
    this->n = n;
    this->m = m;
    this->pMax = pMax;
    memset(h, -1, sizeof h);
    memset(inDegree, 0, sizeof inDegree);
    memset(p, 0, sizeof p);
    memset(topS, 0, sizeof topS);
    memset(status, false, sizeof status);
    memset(st, false, sizeof st);
    memset(w, 0, sizeof(w));
    idx = 0;
    ans = INT_MAX;
}

//决策目前这个u点放置还是不放置
void Graph::dfs1(int l, int cnt) {
    int u = topS[l]; // u是现在的结点, 我们只考虑它对后续结点的影响
    if (l > n) { // 迭代完毕, 更新
        ans = min (ans, cnt);
        return;
    }

    //找到u的前驱节点的最小值
    int pre = INT_MAX;
    for (int k = 1; k <= l - 1; k++) {
        for (int i = h[topS[k]]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j == u) {
                pre = min (pre, p[topS[k]] - w[i]);
            }
        }
    }

    //找到u的后驱结点是否存在 < 0 的情况
    bool flag = false;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (pre - w[i] < 0) {
            flag = true;
            break;
        }
    }

    //两种情况都要放置u
    if (pre < 0 || flag) {
        status[u] = true;
        p[u] = pMax;
        //剪枝
        if (++cnt >= ans) {
            return;
        }
        dfs1(l + 1, cnt);
    }
    else {
        //可放置可不放置

        //不放置
        status[u] = false;
        p[u] = pre;
        //剪枝
        if (cnt >= ans) {
            return;
        }
        dfs1(l + 1, cnt);
        //放置
        status[u] = true;
        p[u] = pMax;
        //剪枝
        if (++cnt >= ans) {
            return;
        }
        dfs1(l + 1, cnt);
    }
}

void Graph::branchBound() {
    priority_queue<Node*, vector<Node*>, compare> heap;
    Node *activePoint = new Node(nullptr, pMax, 2, 0, false);
    int level = 2;
    while (level <= n - 1) {
        int u = topS[level];
        int pre = INT_MAX;
        for (int k = 1; k <= level - 1; k++) {
            for (int i = h[topS[k]]; i != -1; i = ne[i]) {
                int j = e[i];
                if (j == u) {
                    auto t = activePoint;
                    //将activePoint 移动到对应的结点上
                    for (int v = level - 1; v > k; v--) {
                        t = t ->parent;
                    }
                    pre = min(pre, t->press - w[i]);
                }
            }
        }

        bool flag = false;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (pre - w[i] < 0) {
                flag = true;
                break;
            }
        }

        Node *newNode;
        if (pre < 0 || flag) {
            //放置
            newNode = new Node(activePoint, pMax, activePoint->lever + 1, activePoint->cnt + 1, true);
            heap.push(newNode);
        }
        else {
            //不放置
            newNode = new Node(activePoint, pre, activePoint->lever + 1, activePoint->cnt, false);
            heap.push(newNode);
            //放置
            newNode = new Node(activePoint, pMax, activePoint->lever + 1, activePoint->cnt + 1, true);
            heap.push(newNode);
        }

        activePoint = heap.top();
        heap.pop();
        level = activePoint->lever;
    }

    ans = activePoint->cnt;
}

#endif //NETWORKAMPIFIER_GRAPH_H

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    Graph g(n, m, d);
    for (int i = 0 ; i < m ; i++) {
        int a, b , c;
        cin >> a >> b >> c;
        g.add(a, b, c);
    }
    g.solve2();
    cout << g.ans << endl;
    return 0;
}