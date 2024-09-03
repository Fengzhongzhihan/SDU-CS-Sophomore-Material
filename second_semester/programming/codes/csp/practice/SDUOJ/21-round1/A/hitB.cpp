#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, c, dx, dy;
LL ly, wx, cntl, cntw;
typedef pair<long long, long long >PLL;
set <PLL> row;
set <PLL> col;

//who == 1代表小L, who == 2代表小W
void hitB ( ) {
    while (col.size()) {
    //处理两个人都离第一个靶子很远的情况
    LL toy = col.begin()->first - ly;
    LL tox = row.begin()->first - wx;
    if (toy >= dy && tox >= dx ) {
        LL tt = min (toy / dy, tox / dx);
        ly += tt * dy;
        wx += tt * dx;
    }

    //小l
        //如果在同一水平线上, 直接射击
        if (ly == col.begin()->first) {
            int i = c;
            while (i-- && col.size()) {
                if (col.begin()->first == ly) {
                    cntl++;
                    row.erase({col.begin()->second, col.begin()-> first});
                    col.erase(col.begin());
                }
                else {
                    break;
                }
            }
        }
        //如果不射击
        else {
            ly = min (col.begin()->first, ly + dy);
        }
    //小w
        //如果在同一竖直线上, 直接射击
        if (wx == row.begin()->first) {
            cntw++;
            col.erase({row.begin()->second, row.begin()-> first});
            row.erase(row.begin());
        }
        //如果不射击
        else {
            wx = min (row.begin()->first, wx + dx);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c >> dy >> dx;
    
    for (int i =0 ; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        row.insert({x, y});
        col.insert({y, x});
    }

    ly = 1;
    wx = 1;

    hitB();

    cout << cntl << " " << cntw;
    return 0;
}