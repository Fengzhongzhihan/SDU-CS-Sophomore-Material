#include<iostream>
#include<string.h>
using namespace std;
const int N = 1e6 + 10;
char str[N];

int main () {
    cin >> str;
    int len = strlen(str);
    //处理偶数
    for (int i = 1; i < len; i += 2) {
         if (str[i] > 'Z' || str[i] < 'A') {
            cout << "No" <<endl;
            return 0;
         }
    }
    //处理奇数
    for (int i = 0; i < len; i += 2) {
         if (str[i] > 'z' || str[i] < 'a') {
            cout << "No" <<endl;
            return 0;
         }
    }
    //若没问题
    cout << "Yes" <<endl;
    return 0;
}