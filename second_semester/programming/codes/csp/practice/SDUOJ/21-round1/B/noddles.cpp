//
// Created by Lenovo on 2024-03-12.
//
#include "bits/stdc++.h"
using namespace  std;
const int N = 2e5 + 10;
int n, m, k;
//每个时间对应着配料
struct noodle {
    int finishedTime;
    int contain;
};
list<noodle> noodles;

struct buyer{
    int arrivedTime;
    int demand;
};
list<buyer> buyers;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    vector<int> finishedTimes;
    for (int i =0 ;i < n; i++) {
        int time;
        cin  >> time;
        finishedTimes.push_back(time);
    }

    vector<int> contains;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int ans = 0;
        // 001 010 100
        // 001 011 111
        while(x--) {
            int contain;
            cin >> contain;
            if (contain == 1) {
                ans = ans | 1;
            }
            else if (contain == 2) {
                ans = ans | 2;
            }
            else {
                ans = ans | 4;
            }
        }
        contains.push_back(ans);
    }
    //整合
    for (int i = 0; i < n; i++) {
        noodle tmp = {finishedTimes[i], contains[i]};
        noodles.push_front(tmp);
    }

    vector<int> arrivedTimes;
    for (int i = 0 ;i < m; i++ ){
        int time; cin >> time;
        arrivedTimes.push_back(time);
    }

    vector<int> demands;
    for (int i = 0; i < m; i++) {
        int x ; cin >> x;
        int cmp = 0;
        while (x--) {
            int y; cin>>y;
            if (y == 1) {
                cmp = cmp | 1;
            }
            else if (y == 2) {
                cmp = cmp | 2;
            }
            else {
                cmp = cmp | 4;
            }
        }
        demands.push_back(cmp);
    }
//整合
    for (int i = 0 ; i < m ; i++) {
        buyer tmp = {arrivedTimes[i], demands[i]};
        buyers.push_back(tmp);
    }

    while(buyers.size()) {
        auto by = buyers.front();
        buyers.pop_front();
        bool isfind = false;
        //遍历每一碗面条
        for (list<noodle> ::iterator it = noodles.begin(); it != noodles.end(); it ++) {
            auto nd = (*it);
            if (nd.finishedTime <= by.arrivedTime && ((nd.contain & by.demand) == by.demand)) {
                cout << by.arrivedTime - nd.finishedTime << endl;
                noodles.erase(it);
                isfind = true;
                break;
            }
        }
        if (!isfind) {
            cout << "Angry" << endl;
        }
    }

    return 0;
}
