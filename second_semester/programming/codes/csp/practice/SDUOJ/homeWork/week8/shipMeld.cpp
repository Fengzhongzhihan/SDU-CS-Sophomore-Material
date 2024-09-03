//
// Created by Lenovo on 2024-04-22.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll w[N], tCost[N];
ll h[N], e[N], ne[N], idx;
ll dis[N], backUp[N];
bool st[N];
ll n, m, tt;

void add (ll a, ll b, ll c, ll d) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c; tCost[idx] = d;
    h[a] = idx++;
}

void spfa(ll x) { // 找出时间最短路
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(st, false, sizeof(st));
    queue<ll> q;
    q.push(1);
    dis[1] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false; // 更新状态, 此时点不为成功松弛的点
        for (ll i = h[t]; i != -1; i = ne[i]) {
            ll j = e[i];
            if (w[i] < x) {// 选用承重 >= x的边
                continue;
            }
            if (dis[j] > dis[t] + tCost[i]) {
                dis[j] = dis[t] + tCost[i];
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

bool check(ll x) {
    //选择 >= x 的边的最短路是否<t
    spfa(x);
    if (dis[n] <= tt) { //代表满足时间要求
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ll x; cin >> x;
    while (x--) {
        //初始化
        memset(h, -1, sizeof(h)); idx = 0;

        cin >> n >> m >> tt; // tt代表总时间的上限值

        for (ll i = 0 ; i < m ; i++) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            add(a, b, c, d);
            add(b, a, c, d); //双向边
        }

        //备份数组, 模仿w
        for (ll i = 0 ; i < idx; i++) {
            backUp[i] = w[i];
        }
        sort(backUp, backUp + idx);
        //进行二分路径中边承重量, 则此时选路一定得选择权重 >= ans 的边
        ll l = 0, r = idx - 1;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (check(backUp[mid])) { //能够满足时间的要求
                l = mid;
            }
            else { // 不能满足要求
                r = mid - 1;
            }
        }
        cout << backUp[l] << endl;
    }

    return 0;
}