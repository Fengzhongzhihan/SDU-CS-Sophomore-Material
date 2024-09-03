#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, res;

int main() {
    string start = "01";
    string cp = start;
    string str ;
    cin >> n;
    cin >> str;
    while (cp.size() < n) {
        int len = cp.size();
        string tmp = "";
        for (int i = 0 ; i < len ; i++) {
            tmp += (cp[i] - '0') ^ 1 + '0';
        }
        cp += tmp;
    }

    int len = str.length();
    int i = 0;

    while(i + len <= n) {
        bool check = true;
        for (int j = 0; j < len; j++) {
            if (str[j] != cp[i + j]) {
                check = false;
                break;
            }
        }

        if (check) {
            res ++;
            i += len;
        }
        else {
            i ++;
        }
    }

    cout << res ;
    return 0;
}