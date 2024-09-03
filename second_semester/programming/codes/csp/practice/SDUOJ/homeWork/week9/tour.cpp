//
// Created by Lenovo on 2024-04-26.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 10;
int n, m;
typedef long long ll;
ll e[N], h[N], ne[N], idx; // 链式前向星
double w[N]; // 记录边权
ll aa[N], bb[N], vv[N], pp[N]; // 读入数据
double d[N], cnt[N]; // spfa判断负环
bool st[N]; // spfa判断负环

void add (int a, int b, double c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

//判断负环
bool spfa()
{
    queue<int> q;
    //初始化图
    memset (d, 0x3f3f3f3f, sizeof(d));
    memset (st, false, sizeof(st));
    memset (cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n ;i ++ ){
        q.push(i);
        d[i] = 0;
    }

    while(q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t] ; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) { // 此时j为最短路的点
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) {
                    return true;
                }

                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

bool check(double x) {
    //初始化图
    memset(h, -1, sizeof(h));
    for (int i = 0 ; i < m ; i++) {
        e[i] = ne[i] = w[i] = 0;
    }
    idx = 0;
// 将边权改为 p * ans - v
    for (int i  = 0 ; i < m; i++) {
        double w = pp[i] * x - vv[i];
        add(aa[i], bb[i], w);
    }

    if (spfa()) {     //有负环
        return false;
    }
    else {
        return true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        cin >> aa[i] >> bb[i] >> vv[i] >> pp[i];
    }

    double l = 0, r = 1e3;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid)) { // 无负环
            r = mid;
        }
        else { // 有负环
            l = mid;
        }
    }

    printf("%.1f", l);
}