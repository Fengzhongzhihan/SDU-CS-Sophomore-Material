#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, arr[N], x;
bool flag[N];
int main ()
{
    cin >> n >> x;
    for (int i = 0; i < n ;i++) {
        cin >> arr[i];
        if (arr[i] == x) {
            flag[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            cout << arr[i] << " ";
        }
    }
    
    return 0;
}