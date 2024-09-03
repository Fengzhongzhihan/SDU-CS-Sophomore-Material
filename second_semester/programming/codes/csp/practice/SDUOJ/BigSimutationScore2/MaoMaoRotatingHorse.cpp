#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int h[N], ne[N], e[N], idx;
int idx2ring[N];//idx2ring[i]表示第i个点属于第几个环
int indegree[N];
int ring2Likes[N];//ring2Likes[i]表示第i个环的喜欢度
int n;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    indegree[b]++;
}

void solve() {
    //找到所有入度为0的点
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    //将所有不在自环中的点的入度均变为0
    while (q.size()) {
        int t = q.front();
        q.pop();
        indegree[e[h[t]]] --;
        if (indegree[e[h[t]]] == 0) {
            q.push(e[h[t]]);
        }
    }
    //找到所有点属于哪个环
    int cnt = 0;//环的个数
    for (int i = 1; i <= n; i++) {
        if (indegree[i] != 0 && idx2ring[i] == 0) { // 入度不为0且没被标记过
            idx2ring[i] = ++cnt;
            int ver = i;
            //while循环找到环中的所有点
            do {
                idx2ring[ver] = cnt;
                ver= e[h[ver]];
            }while (ver != i);
        }
    }
    //找到每个环的喜欢度
    for (int i = 1; i <= n; i++) {
        if (idx2ring[i] != 0) {//在环中
            ring2Likes[idx2ring[i]] ++;
        }else {
            //不在环中, 找到该点能到达的环
            int ver = i;
            while (idx2ring[ver] == 0) {
                ver = e[h[ver]];
            }
            ring2Likes[idx2ring[ver]] --;
        }
    }
    //找到环的最大喜欢度
    int maxLikes = -1e5;
    for (int i = 1; i <= cnt; i++) {
        maxLikes = max(maxLikes, ring2Likes[i]);
    }
    //找到最大喜欢度下最大的编号值的环
    int maxIdx = 0;
    for (int i = n; i >= 1; i--) {
        if (ring2Likes[idx2ring[i]] == maxLikes) {
            maxIdx = i;
            break;
        }
    }
    //按照标号从小到大进行输出
    int minIdx = 0;
    for (int i = 1; i <= n; i++) {
        if (idx2ring[i] == idx2ring[maxIdx]) {
            minIdx = i;
            break;
        }
    }
    //输出该环
    int ver = minIdx;
    do {
        printf("%d ", ver);
        ver = e[h[ver]];
    }while (ver != minIdx);
}



int main() {
    memset(h , -1, sizeof(h));
    cin >> n;
    for (int i = 0;  i < n ; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    solve();
}