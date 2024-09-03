#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n ,m;
int h1[N], e1[N], ne1[N], idx1; // 正图
int h2[N], e2[N], ne2[N], idx2; // 反图
int h3[N], e3[N], ne3[N], idx3; // 反图
int c[N], dfn[N], dcount, scount; // 后序
bool vis[N];
bool st[N];
map<string ,int>mp;
map<int, string>mp2;
int Indegree[N];
struct ConPoint{
    vector<int> points;
}ConPoints[N];

void add1(int a, int b) {
    e1[idx1] = b;
    ne1[idx1] = h1[a];
    h1[a] = idx1++;
}

void add2(int a, int b) {
    e2[idx2] = b;
    ne2[idx2] = h2[a];
    h2[a] = idx2++;
}

void add3(int a,int b) {
    e3[idx3] = b;
    ne3[idx3] = h3[a];
    h3[a] = idx3++;

}
//找出后序列
void dfs1(int x) {
    st[x] = true;
    for (int i = h1[x]; i != -1; i = ne1[i]) {
        int j = e1[i];
        if (!st[j]) {
            dfs1(j);
        }
    }
    dfn[dcount++] = x; // 后序列
}
//找出对应的强连通分量
void dfs2(int x) {
    c[x] = scount;
    ConPoints[scount].points.push_back(x);
    for (int i = h2[x]; i != -1; i = ne2[i]) {
        int j = e2[i];
        if (!c[j]) {
            dfs2(j);
        }
    }
}

void kosaraju() {
    //第一遍dfs
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            dfs1(i);
        }
    }
    //第二遍
    for (int i = n - 1; i >= 0 ; i--) {
        int p = dfn[i];
        if (!c[p]) {
            ++scount;
            dfs2(p);
        }
    }
}

void topSort() {
    queue<int>q;
    for (int i = 1; i <= scount; i++) {
        if (Indegree[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        set<string> s;
        for (int i = 0 ; i < ConPoints[t].points.size(); i++) {
            s.insert(mp2[ConPoints[t].points[i]]);
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it << endl;
        }
        for (int i = h3[t]; i != -1; i = ne3[i]) {
            int j = e3[i];
            if (--Indegree[j] == 0) {
                q.push(j);
            }
        }
    }

}

int main() {
    memset(h1, -1 ,sizeof(h1));
    memset(h2, -1 ,sizeof(h2));
    memset(h3, -1, sizeof(h3));
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        string name;
        cin >> name;
        mp[name] = i;
        mp2[i] = name;
    }
    cin >> m;
    for (int i = 0 ; i < m ; i++) {
        string a, b;
        cin >> a >> b;
        int idx1 = mp[a], idx2 = mp[b];
        add1(idx1, idx2);
        add2(idx2, idx1);
    }

    kosaraju();
    //遍历每条边, 端点在不同的SCC中, 则标记出边, 找出压缩点后入度为0的点
    for (int i = 1; i <= n; i++) {
         for (int j = h1[i]; j != -1 ; j = ne1[j]) {
            int k = e1[j]; // i到k的边
            if (c[i] != c[k] && !vis[c[i]]) {// k入度不为0的点
                Indegree[c[k]]++;
                add3(c[i], c[k]);
                vis[c[i]] = true;
            }
        }
    }

    //拓扑排序
    topSort();
    return 0;
}