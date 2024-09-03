#include<iostream>
using namespace std;
char str[3];
int main() {
    cin >> str;
    char letter = str[0];
    int i;
    for (i = 0; i < 3; i++) {
        if (str[i] != letter) {
            break;
        }
    }

    if(i == 3) {
        cout << "Won" << endl;
    }
    else {
        cout << "Lost" << endl;
    }
}