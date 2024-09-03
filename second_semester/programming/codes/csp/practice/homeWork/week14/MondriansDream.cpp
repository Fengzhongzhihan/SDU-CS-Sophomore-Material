//
// Created by Lenovo on 2024-05-29.
//
#include "bits/stdc++.h"
using namespace std;
int n, m;
const int N = 12, M = 1 << N;
long long f[N][M];
bool st[M]; // 记录状态是否合法
int main() {
    cin >> n >> m;
    //预处理, 把有连续的0为偶数的状态都标记为true
    for (int i = 0 ; i < 1 << n; i++) {//枚举所有状态
        int cnt = 0 ;// 记录连续的0的个数
        st[i] = true;
        for (int j = 0 ; j < n; j++) {//枚举所有行
            if (i >> j & 1) {//如果第j行为1
                if (cnt & 1) {//如果连续的0的个数为奇数
                    st[i] = false;
                    break;
                }
            }else {
                cnt ++;
            }
        }
        //处理最后一段
        if (cnt & 1) {
            st[i] = false;
        }
    }
    //把前一列和后一列都不冲突的加入最终答案
    memset(f, 0, sizeof f);
    f[0][0] = 1;//代表第0列只有一种方案, 不存在伸向第一列的方块
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 1 << n; j++) {//遍历每一列的所有状态
            for (int k = 0 ; k < 1 << n; k++) {//遍历前一列的所有状态
                if ((j & k) == 0 && st[j | k]) {//如果前一列和后一列都不冲突, 即都为1, 且j | k满足预处理的要求, j | k代表该列的真实状态
                    f[i][j] += f[i - 1][k];//这一列的方案数加上前一列列的方案数
                }
            }
        }
    }
    cout << f[m][0] << endl;//表示遍历完且没有伸向下一列的方块
}