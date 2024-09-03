#include<bits/stdc++.h>
using namespace std;
int n, m;
typedef pair<int, int> PII;
vector <PII> v;

//自定义排序
bool cmp (PII p1, PII p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main () {
    //处理输入
    cin >> n >> m;
    //O(m)
    for (int i = 0; i < m; i++) {
        int x, t;
        cin >> x >> t;
        v.push_back({t, x});
    }
    //进行排序 O(mlogm)
    sort(v.begin(), v.end(), cmp);

    //按桶顺序进行输出, O(m)
    for (int i = 0; i < m - 1; i++ ) {
        auto p1 = v[i], p2 = v[i + 1];
        cout << p1.second << " ";
        //如果下一个将要输出的属于不同的桶, 则换行
        if (p1.first != p2.first) {
            cout << endl;
        }
        //处理最后一个数字的输出
        if (i == m - 2) {
            cout << p2.second << " ";
        }
    }
    return 0;
}