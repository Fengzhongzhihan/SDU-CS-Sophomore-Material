#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N];
int main ()
{
    cin >> n;
    while (n--) {
        cin >> m;
        int res = 0;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            res += a[i];
        }

        cout << res << endl;
    }

    return 0;
}