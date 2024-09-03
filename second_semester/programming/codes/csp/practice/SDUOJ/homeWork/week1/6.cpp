#include<iostream>
using namespace std;
int n;
int pos[110];//记录人的位置
int res = 0x3f3f3f3f;
int main ()
{
    cin >> n;
    int mxpos = 0 ; //找出最大的位置
    int minpos = 120; //找出最小的位置
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        minpos = min (minpos, pos[i]);
        mxpos = max(mxpos, pos[i]);
    }
    //从最小的位置到最大的位置开始枚举
    for (int x = minpos; x <= mxpos; x++) {
        int sum = 0; //计算代价
        for (int i = 1; i <= n; i++) {
            sum += (pos[i] - x) * (pos[i] - x);
        }
        res = min(sum, res);
    }

    cout << res << endl;//输出结果
    return 0; 
}