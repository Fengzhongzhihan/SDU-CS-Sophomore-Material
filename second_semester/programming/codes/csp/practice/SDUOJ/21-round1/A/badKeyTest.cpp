#include<bits/stdc++.h>
using namespace std;
int n;

void findKey (string str) {
    bool click[26] = {false};
    bool typeFlag = false;
    //如果都包含了字母, 以及有大写和小写字母, 则没坏
    for (int i = 0; i < str.size(); i++) {
        //是小写字母
        if (str[i] >= 'a' && str[i] <= 'z') {
            click[str[i] - 'a'] = true;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            click[str[i] - 'A'] = true;
            typeFlag = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (click[i] == false || typeFlag == false) {
            cout << "yes" << endl;
            return;
        }
    }

    cout << "no" << endl;
}

int main ( ) {
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        findKey(str);
    }

    return 0;
}