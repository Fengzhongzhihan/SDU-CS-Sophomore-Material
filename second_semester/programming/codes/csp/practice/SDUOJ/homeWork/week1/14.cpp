#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, arr[N];
int main ()
{
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0 ; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        cout << sum << endl;
    }
}