#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N], b[N];
int main ()
{
    cin >> n;
    for (int i = 0; i < n ; i++ ) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    if (sum == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" <<endl;
    }
}