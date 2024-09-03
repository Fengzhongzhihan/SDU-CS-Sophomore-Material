//
// Created by Lenovo on 2024-04-26.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 210;
int e[N], ne[N], h[N], idx;
double x[N], y[N], z[N];
double fx, fy, fz;
double ans[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//力类
struct FV{
    double x, y, z;
    double mo;
    FV(double xx, double yy, double zz) {
        x = xx, y = yy, z = zz;
        mo = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); // 求模
    }
};

//给定外加力sF 和 方向向量 dF, 算出对应的引力波fi
FV YinliBo(FV sF, FV dF){
    if (sF.mo == 0) {
        FV res (0, 0, 0);
        return res;
    }
    double innerMulti = sF.x * dF.x + sF.y * dF.y +sF.z * dF.z;
    double cosVal = innerMulti / (sF.mo * dF.mo);
    double xx = dF.x / dF.mo, yy = dF.y / dF.mo, zz = dF.z / dF.mo;
    FV res (xx * sF.mo * cosVal, yy * sF.mo * cosVal, zz * sF.mo * cosVal);
    return res;
};

//给定外加力sF 和 引力波fi 求出对应的引力压迫
double pushVal(FV sF, FV YinliBo) {
    double xx = sF.y * YinliBo.z - sF.z * YinliBo.y;
    double yy = sF.z * YinliBo.x - sF.x * YinliBo.z;
    double zz = sF.x * YinliBo.y - sF.y * YinliBo.x;
    FV res(xx, yy, zz);
    return res.mo;
}

void solve(int p, FV Push, int source) {
    double res = 0;// push val
    bool flag = true;
    for (int i = h[p]; i != -1; i = ne[i]) { // 遍历每条边, 并进行求解引力压迫
        int j = e[i];
        if (j == source) {
            continue;
        }
        flag = false; // 判断是否还有别的边会产生引力波
        FV dF (x[j] - x[p], y[j] - y[p], z[j] - z[p]); // dF不可能为0向量
        FV qi = YinliBo(Push, dF); //产生了新的引力波, 可能为0向量
        res += pushVal(Push, qi); // 加上该边对应的引力波产生的引力压迫
        solve(j, qi, p);
    }
    if (!flag)
        ans[p] = res;
    else {
        ans[p] = Push.mo; // 如果是叶子结点, 直接赋值为压力F的模
    }
}

int t, n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }
        memset(h, -1, sizeof(h));
        for (int i = 0 ; i < n - 1; i++) {
            int a,b;
            cin >> a >> b;
            add(a, b);
            add(b, a); // 无向边
        }
        int p ;
        cin >> p >> fx >> fy >> fz;
        FV initPush (fx, fy, fz);
        solve(p, initPush, 0);
        for (int i = 1; i <= n; i++) {
            printf("%lf\n", ans[i]);
        }
    }

    return 0;
}