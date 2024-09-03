//
// Created by Lenovo on 2024-03-14.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 30;
int n, k;
int num[N];
int res;

bool primeNumber(int x ){
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
//遍历到下标为u的数, 目前一共有kk个数相加, 和为sum
void dfs (int u, int kk, int sum){
    if (kk == k) {
        if (primeNumber(sum)) {
            res++;
        }
        return;
    }
    if (u >= n ) {
        return;
    }
    //选第u个数
    dfs(u + 1, kk + 1, sum + num[u]);
    //没选第u个数
    dfs(u + 1, kk, sum);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    dfs(0, 0, 0);

    cout << res;
}