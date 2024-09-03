#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
int main ()
{
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            res += a[i];
        }

        cout << res << endl;
    }

    return 0;
}