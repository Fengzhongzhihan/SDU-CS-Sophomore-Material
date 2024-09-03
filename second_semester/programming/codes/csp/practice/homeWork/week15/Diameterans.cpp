#include "bits/stdc++.h"
using namespace std;
#define int long long
int n;
const int N = 1e6 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int f1[N], f2[N]; // f1[i]表示以i为根的子树中，到达叶子节点的最长路径，f2[i]表示以i为根的子树中，到达叶子节点的次长路径
int f1_count[N]; // 记录每个节点的子树中最长路径的数量
int f2_count[N]; // 记录每个节点的子树中次长路径的数量
int ans = 0, cnt = 0;
void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int father) {
    f1[u] = f2[u] = 0;//初始化
    f1_count[u] = f2_count[u] = 1;//初始化
    //遍历所有子节点
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs(j, u);//递归
        int d = f1[j] + w[i];//子节点的最大路径和权值
        //分类处理, 更新f1和f2
        if (d > f1[u]) {
            f2[u] = f1[u];
            f2_count[u] = f1_count[u];
            f1[u] = d;
            f1_count[u] = f1_count[j];
        } else if (d == f1[u]) {
            if (d == f2[u]) {
                f1_count[u] += f1_count[j];
            } else {
                f2[u] = f1[u];
                f1_count[u] += f1_count[j];
            }
        } else if (d > f2[u]) {
            f2[u] = d;
            f2_count[u] = f1_count[j];
        } else if (d == f2[u]) {
            f2_count[u] += f1_count[j];
        }
    }

    int xcnt = 0 ;//记录直径的数量
    //统计最大路径的出现次数
    int c1 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        int d = f1[j] + w[i];
        if (d == f1[u]) {
            c1 ++;
        }
    }
    if (c1 > 1) {//如果多个最大距离, 此时每一个子节点都对应了一个最大距离, 但每个节点最大距离的个数未必相同
        //找到对应的最大距离的子节点
        int sum = 0;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j == father) continue;
            int d = f1[j] + w[i];
            if (d == f1[u]) {
                //例如有3个子节点个数分别为3, 4, 5, 则我们需要求出3 * 4 + 4 * 5 + 3 * 5 = 47
                xcnt += sum * f1_count[j];
                sum += f1_count[j];
            }
        }
    }else {
        xcnt = f1_count[u] * f2_count[u];
    }

    if (ans < f1[u] + f2[u]) {
        ans = f1[u] + f2[u];
        cnt = xcnt;
    }else if (ans == f1[u] + f2[u]){
        cnt += xcnt;
    }
}

signed main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b ;
        add(a, b, 1);
        add(b, a, 1);
    }
    // 从1号节点开始dfs, 以它为根节点
    dfs(1, -1);
    cout << ans << " " << cnt;
    return 0;
}