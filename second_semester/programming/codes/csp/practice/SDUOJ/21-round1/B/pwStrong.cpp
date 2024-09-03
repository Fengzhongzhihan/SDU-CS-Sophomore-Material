//
// Created by Lenovo on 2024-03-12.
//
#include "bits/stdc++.h"
using namespace std;
string str;
int strong;

int charType(char c) {
    if (c >= 'a' && c <= 'z' ) {
        return 1;
    }
    else if (c >= 'A' && c <= 'Z') {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    cin >> str;
    int len = str.size();
    if (len < 6) {
        cout << "0" << endl;
        return 0;
    }

    int i = 0;
    strong = 1;
    while (i + 1 < len) {
        if (charType(str[i]) != charType(str[i + 1])) {
            strong ++;
        }
        i++;
    }

    cout << strong;
    return 0;
}