//
// Created by Lenovo on 2024-06-17.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], h[N], hs[N],  idx;
int n, m;
int dfn[N], id[N], dcount, scount; bool st[N];
int idSize[N];
int dIn[N], dOut[N];
void add(int h[], int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int x) {
    st[x] = true;
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            dfs1(j);
        }
    }
    dfn[dcount++] = x;
}

void dfs2(int x) {
    id[x] = scount;
    idSize[scount]++;
    for (int i = hs[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!id[j]) {
            dfs2(j);
        }
    }
}

void kosaraju() {
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            dfs1(i);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int p = dfn[i];
        if (!id[p]) {
            scount++;
            dfs2(p);
        }
    }
}
int main() {
    cin >> n ;
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    for (int i = 1; i <= n; i++) {
        int b;
        while (1){
            cin >> b;
            if (b == 0) {
                break;
            }
            add(h, i, b);
            add(hs, b, i);
        }
    }
    kosaraju();
    //找到入度为0的SCC数量
    for (int i = 1; i <= n; i++) {
        for (int j = h[i]; j != -1; j = ne[j]) {
            int k = e[j];
            if (id[i] != id[k]) {
                dIn[id[k]]++;
                dOut[id[i]]++;
            }
        }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1 ; i <= scount; i++) {
        if (dIn[i] == 0) {
            ans1 ++;
        }
        if (dOut[i] == 0) {
            ans2 ++;
        }
    }

    if (scount == 1) {
        cout << 1 << endl << 0 << endl;
        return 0;
    }
    ans2 = max(ans1, ans2);
    cout << ans1 << endl << ans2 << endl;
}