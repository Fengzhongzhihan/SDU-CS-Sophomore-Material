//
// Created by Lenovo on 2024-04-12.
//

#include "bits/stdc++.h"
using namespace std;
struct node {
    string str;
    string op;// 已经经过了哪些操作
};

queue <node> q;
map<string, int> d; // 表示操作次数, 同时判断一个字符串是否遍历过
string st = "12345678", ed = "";

void bfs() {
    q.push({st, ""});
    d[st] ++;
    while(q.size())  {
        auto t = q.front();
        q.pop();

        string str = t.str, op = t.op;
        if (str == ed) {
            cout << op.size() << endl;
            cout << op ;
            return;
        }
        //遍历三种状态
        // A交换两行 12345678 87654321
        string swapRow = str;
        std::reverse(swapRow.begin(), swapRow.end());
        if (!d.count(swapRow)) {
            q.push({swapRow, op + "A"});
            d[swapRow] ++;
        }
        // B将最右边一列插入最左边 第4, 8个数作为第1, 5个数 12345678  41236785
        string insertCol = "";
        insertCol = insertCol + str[3] + str[0] + str[1] + str[2] + str[5] + str[6] + str[7] + str[4];
        if (!d.count(insertCol)) {
            q.push({insertCol, op + "B"});
            d[insertCol] ++;
        }
        // C顺时针旋转90度 12345678 17245368
        string spin = "";
        spin = spin + str[0] + str[6] + str[1] + str[3] + str[4] + str[2] + str[5] + str[7];
        if (!d.count(spin)) {
            q.push({spin, op + "C"});
            d[spin] ++;
        }
    }
    return;
}

int main() {
    for (int i = 0 ; i < 8 ; i++) {
        int x; cin >> x;
        ed += (x + '0');
    }
    bfs();
}