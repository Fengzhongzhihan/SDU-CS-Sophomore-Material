//
// Created by Lenovo on 2024-03-17.
//
#include "bits/stdc++.h"
using namespace  std;
int n;
map<string ,int >flower;
//记录最先获得这个分数的名字
map<int ,string> refer;
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        string name;
        int addScore, score;
        cin >> name >> addScore;

        if (flower.count(name) == 0) {
           score = 1000;
        }
        else {
            score = flower[name];
        }
        score += addScore;
        flower[name] = score;
        if (refer.count(score) == 0) {
            refer[score] = name;
        }
    }

    int minScore = 0x3f3f3f3f;
    string name ;
    //淘汰最少的分数
    for (map<string, int> ::iterator it = flower.begin(); it != flower.end(); it++) {
        if (it ->second < minScore) {
            name = it->first;
            minScore = it->second;
        }
    }
    //如果分数相同, 则淘汰最先获得这个分数的

    cout << refer[minScore] << endl;
    cout << minScore << endl;
}