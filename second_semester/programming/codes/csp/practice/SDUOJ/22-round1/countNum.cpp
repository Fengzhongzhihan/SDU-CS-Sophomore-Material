#include<bits/stdc++.h>
using namespace std;
const int N = 60;
int cnt = 1;
int n, m;
int clap[N];

bool contain(int x ){
    while (x) {
        if (x % 10 == 7) {
        return true;
        }
        x /= 10;
    }
    return false;
}

int main() {
    cin >> n >> m;
    while (cnt <= m) {
        if (cnt % 7 == 0 || contain(cnt)) {
            if (cnt % n == 0) {
                clap[n] ++;
            }
            else {
                clap[cnt % n] ++;
            }
        }

        cnt ++;
    }

    for (int i = 1; i <= n; i++) {
        cout << clap[i] << " "; 
    }

    return 0;
}