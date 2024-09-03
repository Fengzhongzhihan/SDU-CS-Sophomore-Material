#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> xp;
set<int> yp;
set<int> zp;
vector<int> dis;
vector<char> pos;
typedef long long LL;

void init() {
    xp.insert(0);xp.insert(n);
    yp.insert(0);yp.insert(n);
    zp.insert(0);zp.insert(n);
}

LL maxcake() {

    LL mx = 0,  my = 0,  mz= 0;
    //O(m)
    for (set<int> :: iterator it = xp.begin(), nextIt = next(it); nextIt != xp.end(); it++, nextIt++) {
        if (*nextIt - *it > mx) {
            mx = *nextIt - *it;
        } 
    }

      for (set<int> :: iterator it = yp.begin(), nextIt = next(it); nextIt != yp.end(); it++, nextIt++) {
        if (*nextIt - *it > my) {
            my = *nextIt - *it;
        } 
    }
      for (set<int> :: iterator it = zp.begin(), nextIt = next(it); nextIt != zp.end(); it++, nextIt++) {
        if (*nextIt - *it > mz) {
            mz = *nextIt - *it;
        } 
    }

    LL res = mx * my * mz;
    return res;
}

int main() {
    cin >> n >> m;
    init ();
    for (int i = 0; i < m; i++) {
        char op; cin >> op;
        pos.push_back(op);
    }    
    for (int i = 0; i < m; i++) {
        int y; cin >> y;
        dis.push_back(y);
    }
    //初始化
    for (int i = 0; i < m; i ++) {
        if (pos[i] == 'x') {
            xp.insert(dis[i]);
        }
        else if (pos[i] == 'y') {
            yp.insert(dis[i]);
        }
        else {
            zp.insert(dis[i]);
        }

        cout << maxcake() << endl;
    }

    return 0;
}