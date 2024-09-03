//
// Created by Lenovo on 2024-06-03.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 50010;
pair <int ,int > cows[N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        int x, y;
        cin >> x >> y;
        cows[i].first = x + y; cows[i].second = y;
    }
    sort(cows, cows + n);
    int sum = 0 , res = -2e9;
    for (int i = 0 ; i < n; i++) {
        auto cow = cows[i];
        int ss = cow.second;
        int ww = cow.first - cow.second;
        res = max(res, sum - ss);
        sum += ww;
    }
    cout << res;
    return 0;
}