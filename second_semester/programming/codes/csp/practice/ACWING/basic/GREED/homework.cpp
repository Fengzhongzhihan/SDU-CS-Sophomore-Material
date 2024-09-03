//
// Created by Lenovo on 2024-06-09.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
bool st[N];
int n;
struct hk{
    int ddl, score;
    bool operator < (const hk &t) const {
        return score >  t.score;
    }
}hks[N];

bool cmp(hk a, hk b){
    if (a.ddl == b.ddl) return a.score > b.score;
    else return a.ddl < b.ddl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> hks[i].ddl >> hks[i].score;
    }
    sort(hks, hks + n, cmp);
    int res = 0, t = 1; //表示第t天
    priority_queue<hk> q;//小根堆
    for (int i = 0 ; i < n ; i++) {
        if (t <= hks[i].ddl && !st[t]) {
            st[t] = true;
            t ++;
            res += hks[i].score;
            q.push(hks[i]);
        }else {
            if (q.size() && q.top().score < hks[i].score && q.top().ddl <= hks[i].ddl) {
                res += hks[i].score - q.top().score;
                q.pop();
                q.push(hks[i]);
            }
        }
    }
    cout << res << endl;
}