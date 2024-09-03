#include "bits/stdc++.h"
using namespace std;

const int N = 15;
char a[N][N];
int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 0, 1, -1};

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == '0') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    int cnt = 0;
                    while (x >= 0 && x < N && y >= 0 && y < N && a[x][y] == '1') {
                        cnt++;
                        x += dx[k];
                        y += dy[k];
                    }
                    x = i - dx[k], y = j - dy[k];
                    while (x >= 0 && x < N && y >= 0 && y < N && a[x][y] == '1') {
                        cnt++;
                        x -= dx[k];
                        y -= dy[k];
                    }
                    if (cnt >= 4) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            for (int j = 0; j < N; j++) {
                a[i][j] = s[j];
            }
        }
        if (check()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
