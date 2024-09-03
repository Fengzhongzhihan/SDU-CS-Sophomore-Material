//
// Created by Lenovo on 2024-03-27.
//
#include "bits/stdc++.h"
using namespace std;
//const int N = 1e4 + 10;
//int a[N], st[N];
//int n, mx, res;
//int main() {
//    cin >> n;
//    for (int i = 0 ; i < n ; i++) {
//        int x; cin >> x;
//        a[x] ++;
//    }
//    for (int i = 0 ; i < N; i++) {
//        if (mx < a[i]) {
//            mx = a[i];
//            res = i;
//        }
//    }
//    cout << res;
//}
map <int , int > mp;
int mx, res;
int n;

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int x ; cin >> x;
        mp[x]++;
    }
    for (map<int, int > ::iterator it = mp.begin(); it != mp.end(); it ++ ) {
        if (it -> second > mx) {
            mx = it ->second;
            res = it->first;
        }
    }
    cout << res;
}