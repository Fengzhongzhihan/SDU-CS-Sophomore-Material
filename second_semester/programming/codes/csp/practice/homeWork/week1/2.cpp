#include<iostream>
using namespace std;

int main() {
    double a,b;
    cin >> a >> b;
    printf ("%.3f", (a - b) / a * 100);
    return 0;
}