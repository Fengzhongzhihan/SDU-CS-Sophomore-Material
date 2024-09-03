//
// Created by Lenovo on 2024-03-20.
//
#include "bits/stdc++.h"
using namespace std;
int n;
int cnt, x, y, t = 1;
bool xWork, yWork;
int atHand = 1;
// 表示x, y还剩多少时间可以结束
int xT, yT;

void placePaper() {
    if (atHand == 0 || (xWork && yWork)) {
        return ;
    }
    if (atHand == 1) {
        if (!xWork) {
            xWork = true;
            xT = x;
            atHand = 0;
        }
        else if (xWork && !yWork) {
            yWork = true;
            yT = y;
            atHand = 0;
        }
    }
        //at Hand >= 2, 可以同时放入两个机器
    else {
        if (!xWork ) {
            xWork = true;
            xT = x;
            atHand--;
        }
        if (!yWork) {
            yWork = true;
            yT = y;
            atHand--;
        }
    }

}

int main() {
    // 每xs, ys复印一份出来
    cin >> n;
    cin >> x >> y;
    //保证x <= y, x效率更高
    if (x >= y) {
        swap(x, y);
    }

    placePaper(); //先放入x
    // t= 1 开始回合
    while (cnt < n) {
        //每回合开始先进行更新状态, 如果已经达到要求了, 则break, 否则再放复印件

        if (xWork) {
            if (xT > 0){
                xT --;
            }
            if (xT == 0) {
                cnt ++;
                atHand += 2;
                xWork = false;
            }
        }
        if (yWork) {
            if (yT > 0) {
                yT --;
            }
            if (yT == 0) {
                cnt ++;
                atHand += 2;
                yWork = false;
            }
        }

        if (cnt >= n) {
            break;
        }
        placePaper();
        //处理x, y机器
        t ++;
    }

    cout << t;
}