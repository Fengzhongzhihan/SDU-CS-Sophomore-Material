#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int res;
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for (int i = 1; i < n; i++) {
        if (v[i] - v[i-1] == 1) {
            res ++;
        }
    }

    cout << res << endl;
}