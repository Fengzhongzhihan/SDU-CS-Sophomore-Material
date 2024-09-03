//
// Created by Lenovo on 2024-03-26.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e7 + 100;
char str[N];
char outPut[N];
int s, idx, k; //idx表示outPut的长度. k 表示bytes的长度
int now; //遍历到bytes的哪个地方了
int bytes[N];

void dealIntroArea() {
    while (now < k) {
        int t = bytes[now++];
        // 最高位为0
        if ((t & 0x80) == 0) {
            break;
        }
    }
}

void outPutLiteral (int len){
    for (int i = 0 ; i < len; i++) {
        int x = bytes[now++];
        char c1, c2;
        if (x / 16 >= 10) {
            c1 = x / 16 - 10 + 'a';
        }
        else {
            c1 = x / 16 + '0';
        }
        if (x % 16 >= 10) {
            c2 = x % 16 - 10 + 'a';
        }
        else {
            c2 = x % 16 + '0';
        }
        // 将x对应的十六进制表示存入对应的outPut序列
        outPut[idx++] = c1;
        outPut[idx++] = c2;
    }
}

void dealLiteralVal(int t) {
    // 11110000
    int l = t / 4, len = 0;
    //若l <= 60
    if (l < 60) {
        len = l + 1;
    }
    //若l > 60
    else {
        int cnt;
        if (l == 60) {
            cnt = 1;
        }
        else if (l == 61) {
            cnt = 2;
        }
        else if (l == 62) {
            cnt = 3;
        }
        else {
            cnt = 4;
        }
        int p = 256;
        for (int i =0 ; i < cnt; i++) {
            len += bytes[now++] * pow(p, i);
        }
        len ++;
    }
    outPutLiteral(len);
}

void outPutTraceBack(int o, int l) {
    int len = idx;
    // 回溯o个字节, 输出l个字节, 不会重复输出
    if (o >= l) {
        //
        for (int i = len - 2 * o; i < len - 2 * o + 2 * l; i++) {
            outPut[idx++]  = outPut[i];
        }
    }
    // 会重复输出 o < l
    else {
        // 直接算出来会重复输出多少次
        int cnt = 0;
        int time = l / o, ext = l % o;
        string rep = "";
        string ans = "";
        for (int i = len - 2 * o ;i < len; i ++)  {
            rep += outPut[i];
        }
        for (int i = 0 ; i < time; i++) {
            ans += rep;
        }
        for (int i = len - 2 * o ; i < len - 2 * o + ext * 2; i++) {
            ans += outPut[i];
        }
        for (int i = 0 ; i <ans.size(); i++) {
            outPut[idx++] = ans[i];
        }
    }
}

//回溯引用
void dealTraceBack(int t) {
    int o = 0, l = 0;
    // 判断低两位为01
    if (t % 4 == 1) {
        l = t / 4 % 8 + 4;
        // 提取前3位
        int oh3 = t / 32;
        int ol8 = bytes[now++];
        o = ol8 + oh3 * 256;
    }
    // 低两位为 10
    else {
        l = t / 4 + 1;
        int low = bytes[now++];
        int high = bytes[now++];
        o = low + high * 256;
    }

    outPutTraceBack(o, l);
}


void dealDataArea() {
    // 判断属于哪种类型
    while (now < k) {
        int t = bytes[now++];
        //是字面量
        if ((t & 3) == 0) {//注意带括号
           dealLiteralVal(t);
        }
        //是回溯量 , 末尾为01 / 10
        else {
            dealTraceBack(t);
        }
    }
}

int main() {
    cin >> s; // 表示一共多少字节
    for (int i = 0 ; i < 2 * s; i++) {
        cin >> str[i];
    }
    // ce : 1100 1110 12 14  12 * 16 + 14 =
    // 初始化bytes
    string tmp = "";
    for (int i = 0; i < 2 * s; i++) {
        tmp += str[i];
        if (i % 2 == 1) {
            // tmp[0] = b tmp[o] = 11 + '0'
            if (!isdigit(tmp[0])) {
                tmp[0] = tmp[0] - 'a' + 10 + '0';
            }
            if (!isdigit(tmp[1])) {
                tmp[1] = tmp[1] - 'a' + 10 + '0';
            }
            bytes[k++] = ((tmp[0] - '0') * 16 + (tmp[1] - '0'));
            tmp = "";
        }
    }

    //处理导引区
    dealIntroArea();
    //处理数据域
    dealDataArea();

    for (int i = 0 ; i < idx ; i++ ) {
        cout << outPut[i];
        if (i % 16 == 15) {
            cout << endl;
        }
    }
}