//
// Created by Lenovo on 2024-04-12.
//
#include"bits/stdc++.h"
using namespace  std;
int n;
priority_queue<int, vector<int>, greater<int>> MinHeap; // 小根堆
priority_queue<int, vector<int>, less<int>> MaxHeap; // 大根堆
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int x ; cin >> x;
        MinHeap.push(x);
        MaxHeap.push(x);
    }
    int lastNum; cin >> lastNum ;
    //求最大值
    while (MinHeap.size() > 1) {
        int a = MinHeap.top();
        MinHeap.pop();
        int b = MinHeap.top();
        MinHeap.pop();
        MinHeap.push(a * b + 1);
    }

    //求最小值
    while (MaxHeap.size() > 1) {
        int a = MaxHeap.top();
        MaxHeap.pop();
        int b = MaxHeap.top();
        MaxHeap.pop();
        MaxHeap.push(a * b + 1);
    }

    cout << MinHeap.top() - MaxHeap.top() ;
}