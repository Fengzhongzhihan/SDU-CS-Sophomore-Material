//
// Created by Lenovo on 2024-03-17.
//
#include "bits/stdc++.h"
using namespace  std;
int n;

int minOP(string s ) {
    queue<pair<string, int>> q;
    unordered_map<string, int> mp;
    string start = s;
    string end1 = "", end2 = "";
    for (int i = 0; i < s.size() / 2; i++) {
        end1 += "A";
        end1 += "B";
        end2 += "B";
        end2 += "A";
    }
    if (s.size() % 2 != 0) {
        end1 += "A";
        end2 += "B";
    }
    q.push({start, 0});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        string str = t.first;
        int time = t.second;
        if (str == end1 || str == end2) {
            return time;
        }

        //开始扩展
        for (int i = 0; i + 1 < str.size(); i++) {
            if (str[i] == str[i + 1]) {
                //两个都是A
                if (str[i] == 'A') {
                    // AB
                    string tmp = str;
                    tmp[i + 1] = 'B';
                        //没遍历过
                        if (mp.count(tmp) == 0) {
                            mp[tmp]++;
                            q.push({tmp, time + 1});
                        }
                        // BA
                        tmp = str;
                        tmp[i] = 'B';
                        if (mp.count(tmp) == 0) {
                            mp[tmp]++;
                            q.push({tmp, time + 1});
                        }
                        // BB
                        tmp = str;
                        tmp[i] = 'B', tmp[i + 1] = 'B';
                        if (mp.count(tmp) == 0) {
                            mp[tmp]++;
                            q.push({tmp, time + 1});
                        }
                    }
                    //两个都是B
                else {
                    // BA
                    string tmp = str;
                    tmp[i + 1] = 'A';
                    //没遍历过
                    if (mp.count(tmp) == 0) {
                        mp[tmp]++;
                        q.push({tmp, time + 1});
                    }
                    // AB
                    tmp = str;
                    tmp[i] = 'A';
                    if (mp.count(tmp) == 0) {
                        mp[tmp]++;
                        q.push({tmp, time + 1});
                    }
                    // AA
                    tmp = str;
                    tmp[i] = 'A', tmp[i + 1] = 'A';
                    if (mp.count(tmp) == 0) {
                        mp[tmp]++;
                        q.push({tmp, time + 1});
                    }
            }

        }
    }
}

}


int main() {

    cin >> n;
    for (int i = 0; i < n ; i++) {
        string s;
        cin >> s;
        cout << minOP(s) << endl;
    }

    return 0;
}