//
// Created by Lenovo on 2024-03-13.
//
#include "bits/stdc++.h"
using namespace  std;
int res;
int last;

int main() {
    int x;
    while (1) {
        cin >> x;
        // 如果x == 0, 则退出
        if (x == 0) {
            break;
        }
        // 如果x == 1, 则res只加1分, 并更新last
        else if (x == 1) {
            res++;
            last = 1;
        }
        // 如果x == 2, 跳到了中心
        else {
            //如果last是1分, 则这次只能加2分
            if (last == 1) {
                res += 2;
                last = 2;
            }
            //否则这次可以多加2分
            else {
                last += 2;
                res += last;
            }
        }
    }

    cout << res;
}