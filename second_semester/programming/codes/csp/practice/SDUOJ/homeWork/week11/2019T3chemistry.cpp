//
// Created by Lenovo on 2024-04-24.
//
#include "bits/stdc++.h"
using namespace std;
// 存储元素集合, 元素 + 个数
struct ele_set{
    map<string, int> mp;

    bool operator == (const ele_set & other) const {
        return mp == other.mp;
    }

    void operator += (const ele_set &other) {
        for (auto &[k, v]: other.mp) {
            mp[k] += v;
        }
    }

    void operator *= (const int x) {
        for (auto &[k, v] : mp) {
            mp[k] *= x;
        }
    }
};

//将字符串按'='分割开
vector<string> split(string &s, char c) {
    vector<string> res;
    stringstream ss(s);
    string cur;
    while (getline(ss, cur, c)) {
        res.push_back(cur);
    }
    return res;
}

//读取一个元素
string r_ele(string &s, int &p ) {
    string res = "";
    res += s[p], ++p; // 先读取一个字母
    //如果还有一个字母, 比如Na的a, 则读入
    if (p < s.size()&& islower(s[p])) {
        res += s[p];
        p++;
    }
    return res;
}
//读取一个整数
int r_int(string &s, int &p) {
    int res  =0;
    while (p < s.size() && isdigit(s[p])) {
        res = res * 10 + s[p] - '0';
        ++ p;
    }

    //特判, 没有整数则默认为1
    if (res == 0) {
        res = 1;
    }
    return res;
}

//将传入的字符串转化为ele_set, 包含多少元素 + 个数
ele_set str2set(string &s, int &p) {
    ele_set res;
    int multi = r_int(s, p); // 先读入一个
    while (p < s.size()) {
        if (s[p] == '(') {
            ++p;
            res += str2set(s, p);
        }
        else if (s[p] == ')') {
            ++p;
            res *= r_int(s, p); // 读入一个系数 比如 Ca(CO3)2
            break;
        }
        else {
            string el = r_ele(s, p); // 正常读入一个元素
            res.mp[el] += r_int(s, p); //读入系数
        }
    }

    res *= multi;
    return res;
}

bool solve(string &s) {
    vector<string>fms = split(s, '='); // 得到左右两边的等式
    ele_set res[2] ; //存储左右两边
    for (int i = 0 ; i < 2; i ++) {
        vector<string> tmp = split(fms[i], '+'); // 将每一个化学方程式变为对应的化学式
        for (int j = 0; j < tmp.size(); j++) {
            int p = 0;
            res[i] += str2set(tmp[j], p);
        }
    }
    if (res[0] == res[1]) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (solve(s)) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }
    }

    return 0;
}