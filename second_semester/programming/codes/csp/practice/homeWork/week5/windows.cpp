//
// Created by Lenovo on 2024-03-30.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e6 + 10;
deque<int> q; // 双端队列, 存储下标
int n , k;
int a[N];

// i = 3    i - 3 + 1 = 1
int main() {
    cin >> n >> k;
    for (int i =0 ; i < n ; i++) {
        cin >> a[i];
    }
    // 找min
    //1 3 -1 -3 5 3 6 7
    for (int i = 0 ; i < n; i++) {
        //判断队头是否要出队
        while (q.size() && q.back() > a[i]) {
            q.pop_back();
        }
        //将i入队
        q.push_back(a[i]);
        //队头是否要出队
        if (i - k >= 0 && q.front() == a[i - k]) {
            q.pop_front();
        }
        if (i + 1 >= k) {
            cout << q.front() << " ";
        }
    }
    cout << endl;
    q.clear();
    // 找max
    for (int i = 0 ; i < n; i++) {
        //判断队头是否要出队
        while (q.size() && q.back() < a[i]) {
            q.pop_back();
        }
        //将i入队
        q.push_back(a[i]);
        //队头是否要出队
        if (i - k >= 0 && q.front() == a[i - k]) {
            q.pop_front();
        }
        if (i + 1 >= k) {
            cout << q.front() << " ";
        }
    }
}