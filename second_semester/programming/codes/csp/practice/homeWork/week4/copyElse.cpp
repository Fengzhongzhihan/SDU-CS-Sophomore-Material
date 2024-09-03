#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int sum = min(x, y);
    int d1 = (n - 1) * min(x, y);
    int d2 = (n - 1) / (x + y);
    while (1)
    {
        int s = (d1 + d2) / 2;
        if (s == d2)
        {
            break;
        }
        int f = s / x + s / y;
        if (f < n - 1)
        {
            d2 = s;
        }
        else if (f >= n - 1)
        {
            d1 = s;
        }
    }
    cout << d1 + sum << endl;
    return 0;
}