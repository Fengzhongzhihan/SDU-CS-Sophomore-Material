#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];
int n, m;
int res;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            bool flag = true;
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (x >= 0 && x <= n - 1 && y >=0 && y <= m - 1 && g[x][y] >= g[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res++;
            }
        }
    }

    cout << res ;
}