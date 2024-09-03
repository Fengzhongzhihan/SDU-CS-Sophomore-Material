#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int times[N];
int n;
int main () {
    cin >> n;
    for (int i = 0;i < n; i++) {
        int x; cin >> x;
        times[x]++;
        cout << times[x] << " ";
    }

    return 0;
}