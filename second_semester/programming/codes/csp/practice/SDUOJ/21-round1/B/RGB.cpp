//
// Created by Lenovo on 2024-03-12.
//
#include "bits/stdc++.h"
using namespace  std;
string str;
int n;
int main() {
    cin >> n;
    cin >> str;
    int r = std::count(str.begin(), str.end(),'R');
    int b = std::count(str.begin(), str.end(),'B');
    int g = std::count(str.begin(), str.end(),'G');

    cout << min(min(r, b), g);
    return 0;
}
