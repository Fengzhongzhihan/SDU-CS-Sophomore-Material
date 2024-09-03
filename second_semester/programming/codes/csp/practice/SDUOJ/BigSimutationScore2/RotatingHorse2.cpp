

#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int h[N], ne[N], e[N], idx;
int n;
bool st[N];
int p[N];
int cnt[N];
vector<vector<int>> AllCircles;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void bfs(int x) {
    queue<pair<int ,vector<int>>> q;
    vector<int>v;
    v.push_back(x);
    st[x] = true;
    q.push({x, v});
    int circleNum = 0;
    while(q.size()) {
        auto t = q.front();
        q.pop();
        int ver = t.first;
        auto order = t.second;
//        遍历t的临边
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (st[j]) {
                //找到环
                if (j == x) {
                    AllCircles.push_back(order);
                }else {
                    
                }
            }else {
                vector<int> newOrder(order);
                newOrder.push_back(j);
                q.push({j, newOrder});
                st[j] = true;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            bfs(i);
        }
    }


    //找出最大的集合
    int maxLove = 0, maxIdx = 0;
    for (int i = 0 ; i < AllCircles.size(); i++) {
        auto circle = AllCircles[i];
        int love = circle.size();
        if (maxLove < love) {
            maxLove = love;
            maxIdx = i;
        }
    }

    auto t = AllCircles[maxIdx];
    for (int i = 0 ; i < t.size(); i++) {
        cout << t[i] << " ";
    }
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