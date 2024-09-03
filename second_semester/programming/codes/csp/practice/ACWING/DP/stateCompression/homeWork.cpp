//
// Created by Lenovo on 2024-06-20.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 16;
int f[1 << N]; //表示完成集合S被扣的最少分数
int T, n;
int pre[1 << N]; //表示完成集合S的前一个状态
int times[1 << N]; //表示完成集合S的总时间

struct hk{
    int t, ddl;
    string name;
}hks[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        memset(times, 0, sizeof times);
        memset(f, 0x3f3f3f3f, sizeof f);
        for (int i = 0; i < n; i++) {
            cin >> hks[i].name >> hks[i].ddl >> hks[i].t;
        }
        for (int i = 0 ; i < 1 << n; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i >> j & 1) {
                    times[i] += hks[j].t;
                }
            }
        }
        //初始化
        f[0] = 0; //表示不写作业的时候, 扣分为0
        pre[0] = -1;
        //每种状态
        for (int i = 0 ; i < 1 << n; i++) {
            for (int j = 0 ; j  < n; j++) {
                //表明计划中没有这个作业
                if (!(i >> j & 1)) {
                    int s = i | (1 << j);
                    int next = f[i] + max(0, times[i] + hks[j].t - hks[j].ddl);
                    if (f[s] > next) {
                        f[s] = next;
                        pre[i | 1 << j] = i;
                    }
                }
            }
        }
        cout << f[(1 << n) - 1] << endl;
        //打印状态
        vector<string> ans;
        int E = (1 << n) - 1;
        while (pre[E] != -1) {
            ans.push_back(hks[int(log2(E - pre[E]))].name);
            E = pre[E];
        }
        for (int i = ans.size() - 1; i >= 0; i-- ) {
            cout << ans[i] << endl;
        }
    }

}