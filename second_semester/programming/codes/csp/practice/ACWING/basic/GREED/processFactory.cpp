//
// Created by Lenovo on 2024-06-09.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1010;
struct pdt{
    int minT, idx;
    bool operator < (const pdt &t) const {
        return minT < t.minT;
    }
}pdts[N];
int a[N], b[N], n;
int ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n ; i++) {
        pdts[i].idx = i;
        cin >> a[i] ;
    }
    for (int i = 1; i <= n ; i++) {
        cin >> b[i] ;
        pdts[i].minT = min (a[i], b[i]);
    }
    sort(pdts + 1, pdts + n + 1);
    int x =1 , y = n;
    for (int i = 1; i <= n; i++) {
        if (pdts[i].minT == a[pdts[i].idx]) ans[x++] = pdts[i].idx; //如果A时间更短, 往前塞
            else ans[y--] = pdts[i].idx;//如果B时间更短, 往后塞
    }
    //此时ans得到了加工的顺序
    int fa = a[ans[1]];//在车间a加工完所需要的时间
    int fb = fa + b[ans[1]];//在车间b加工完所需要的时间
    for (int i = 2; i <= n; i++) {
        //i在B加工需要满足i在A加工完成(fa + a[ans[i]]) 且 i-1在B加工完成(fb)
        //i在A加工需要满足i -1 在A加工完成
        fb = max(fb, fa + a[ans[i]]) + b[ans[i]];
        fa += a[ans[i]];
    }

    cout << fb << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}