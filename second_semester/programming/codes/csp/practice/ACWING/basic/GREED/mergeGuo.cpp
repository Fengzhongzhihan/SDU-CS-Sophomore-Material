//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
priority_queue<int, vector<int>, greater<int>> heap;
int n;
int main() {
    cin >> n;
    int res = 0 ;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        heap.push(x);
    }
    while (heap.size() != 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        heap.push(a + b);
        res += (a + b);
    }
    cout << res;
    return 0;
}