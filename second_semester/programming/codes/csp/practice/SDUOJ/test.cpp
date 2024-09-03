#include "bits/stdc++.h"
using namespace std;
const int N = 10;
int h[N], e[N], ne[N], idx;
int indgr[N];
int n, m;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    indgr[b]++;
}
vector<vector<int>> levers;

void topSort(){
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!indgr[i]) {
            q.push(i);
        }
    }

    while (q.size()) {
        int sz = q.size();
        vector<int> lever;
        for (int k = 0 ; k < sz; k++) {
            int t = q.front();
            q.pop();
            lever.push_back(t);
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                indgr[j]--;
                if (!indgr[j]) {
                    q.push(j);
                }
            }
        }
        levers.push_back(lever);
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    topSort();
    for (auto lever : levers) {
        cout << "lever: ";
        for (auto x : lever) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}