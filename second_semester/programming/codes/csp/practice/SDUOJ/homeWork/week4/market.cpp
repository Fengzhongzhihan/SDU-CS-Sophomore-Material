//
// Created by Lenovo on 2024-03-21.
//
#include "bits/stdc++.h"
using namespace std;
typedef  long long LL ;
const int N = 1e5 + 10;
int n, m;
int a[N];

void buyGoods() {
    LL ans = 0, cnt = 0;
    int bIndex = 0, sIndex = 0; // 分别代表买的位置和卖的位置
    // 从第二家开始遍历
    for (int i = 1; i < n ; i++) {
        //如果比买的价格小的话, 就更新买的位置和卖的位置
        if (a[i] < a[bIndex]) {
            bIndex = i;
            sIndex = i;
        }
        //如果比卖的价格大的话, 就更新卖的位置
        if (a[i] >= a[sIndex]) {
            sIndex = i;
            //遍历到最后一家的话, 如果价格比买的大的话直接卖了
            if (sIndex == n - 1) {
                if (a[sIndex] > a[bIndex]) {
                    ans += a[sIndex] - a[bIndex];
                    cnt += 2;
                }
            }
            //如果下一家店的价格比这家店小
            else if (a[sIndex + 1] < a[sIndex]) {
                if (a[sIndex] > a[bIndex]) {//如果赚钱
                    ans += a[sIndex] - a[bIndex];
                    cnt += 2;
                    //记得更新
                    bIndex = sIndex + 1;
                    sIndex += 1;
                }
            }
        }
    }

    cout << ans <<" " << cnt << endl;
}

int main() {
    cin >> m;
    while (m--) {
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        buyGoods();
    }

    return 0;
}