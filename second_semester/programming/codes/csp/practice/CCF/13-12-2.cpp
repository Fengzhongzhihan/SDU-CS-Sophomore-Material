//
// Created by Lenovo on 2024-03-27.
//
#include "bits/stdc++.h"
using namespace std;
int idx;
int mode = 11, check, cnt = 1;
//ISBN码的首位数字表示书籍的出版语言，例如0代表英语；
// 第一个分隔符“-”之后的三位数字代表出版社，例如670代表维京出版社；第二个分隔之后的五位数字代表该书在出版社的编号；最后一位为识别码
// x- xxx - xxxxx - x
int main() {
    string num;
    cin >> num;
    for (int i = 0 ; i < num.size(); i++) {
        if (num[i] == '-') {
            num.erase(num.begin() + i);
        }
    }

    for (int i = 0 ; i < num.size() - 1; i++) {
        check += (num[i] - '0') * cnt++ % 11;
    }

    if (check == )
}