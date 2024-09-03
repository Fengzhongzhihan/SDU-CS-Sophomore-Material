#include"bits/stdc++.h"
using namespace std;
const int N = 420;
int n;
int f1[N][N], f2[N][N];
int a[N], s[N];
int b[N];
int main() {
    memset(f1, 0x3f3f3f3f, sizeof(f1));
    memset(f2, -0x3f3f3f3f, sizeof(f2));
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i]; a[i + n] = a[i];
    }
    //1~n
    // 1 2 3 4 1 2 3 4
    for (int i = 1; i <= n << 1; i++) {
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i < n << 1 ;i++) {
        f1[i][i] = f2[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 < n << 1; i++) {
            int j = i + len - 1; //枚举到f[1][2n - 1]
            for (int k = i ; k < j ; k++) {
                f1[i][j] = min(f1[i][j], f1[i][k] + f1[k + 1][j] + s[j] - s[i - 1]);
                f2[i][j] = max(f2[i][j], f2[i][k] + f2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    int maxV = -0x3f, minV = 0x3f3f3f3f;
    //从n种方案中选择一种
    for (int i = 1; i <= n ; i++) {
        minV = min(minV, f1[i][i + n - 1]);
        maxV = max(maxV, f2[i][i + n - 1]);
    }
    cout << minV << endl << maxV << endl;
    return 0;
}