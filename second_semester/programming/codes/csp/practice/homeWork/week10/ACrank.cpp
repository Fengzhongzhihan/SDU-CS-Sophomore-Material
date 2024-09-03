//
// Created by Lenovo on 2024-05-10.
//
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
typedef pair<int, int> PII;
int n;
PII a[N];
int s[N], st[N];
//比较函数
bool compare(PII a, PII b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
//返回x的最后一位1
int lowbit(int x) {
    return x & (-x);
}

//返回区间1~p的和
int ask(int p) {
    int res = 0;
    for (int i = p; i >= 1; i -= lowbit(i)) {
        res += s[i];
    }
    return res;
}
//更新操作
void upd(int p, int x) {
    for (int i = p; i <= N; i += lowbit(i)) {
        s[i] += x;
    }
}

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int l , r;
        scanf("%d%d", &l, &r); // 输入
        a[i] = {l, r};
    }
    sort (a + 1, a + 1 + n, compare);
    for (int i = 1 ; i <= n ; i++) {
        int cnt = 0;
        auto t = a[i];
        int r = t.second;
        cnt = ask(r + 1); // 找出1~r + 1中数字出现的次数
        upd(r + 1, 1);//更新r + 1出现的次数
        st[cnt]++;//根据比不大于r + 1的数字出现次数将对应的位置+1
    }
    for (int i = 0 ; i < n ; i++) {
       printf("%d\n", st[i]);
    }
    return 0;
}