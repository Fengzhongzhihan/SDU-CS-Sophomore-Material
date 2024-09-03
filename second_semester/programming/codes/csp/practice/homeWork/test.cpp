#include "bits/stdc++.h"
using namespace std;
vector<int> a;

int main() {
    //初始化数据
    for (int i = 1; i <= 5; i++) {
        a.push_back(i);
        a.push_back(i);
    }
    for (vector<int> :: iterator it = a.begin(); it != a.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    std::sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (vector<int> :: iterator it = a.begin(); it != a.end(); it++) {
        cout << (*it) << " ";
    }

    return 0;
}