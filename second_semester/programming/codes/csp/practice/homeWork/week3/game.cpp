//
// Created by Lenovo on 2024-03-13.
//
#include "bits/stdc++.h"
using namespace std;
int n, k;
queue<int> players;
int cnt = 1;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++ ){
        players.push(i);
    }
// 1 2 3 4 5
// 1 3 5
    while (players.size() > 1) {
        //此时发言的小朋友
        auto t = players.front();
        players.pop();
        //淘汰小朋友
        if (cnt % 10 == k || cnt % k == 0) {
            cnt ++;
            continue;
        }
        players.push(t);
        cnt ++;
    }

    cout << players.front() ;
    return 0;
}