#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string line;
int main ()
{
    while (getline(cin, line)) {
        int res = 0;
        int num = 0;
        stringstream buffer(line);
        while (buffer >> num) {
            res += num;
        }
        cout << res <<endl;
    }
    return 0;
}