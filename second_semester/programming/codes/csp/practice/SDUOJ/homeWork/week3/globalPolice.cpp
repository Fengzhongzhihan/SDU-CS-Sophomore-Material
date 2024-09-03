//
// Created by Lenovo on 2024-03-17.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 1e6 + 10;
int cty[N];
int n;
map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++ ){
        cin >> cty[i];
    }

    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < n )  {
        mp[cty[i]] ++;
        while (mp[cty[i]] > 1) {
            mp[cty[j]] --;
            j ++;
        }
        res = max (res, i - j + 1);
        i ++;
    }

    cout << res;
}