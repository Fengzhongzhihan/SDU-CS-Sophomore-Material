#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int M = 1e5 + 10; 
int N, K;
int arr[M];
int tmp[M];

bool cmp (int a ,int b) {
    return a > b;
}

int g1(int x) {
    //提取x的位数字, 从低位到高位依此放入tmp数组中,时间复杂度为O(logn)
    int k = 0;
    while (x) {
        tmp[k++] = x % 10;
        x /= 10;
    }
    //从高到低排序, 时间复杂度为O(logn)
    sort(tmp, tmp + k, cmp);
    int res = 0;
    //将离散的单个数字折算为最终数字, 时间复杂度为O(logn)
    for (int i = 0;i < k; i++) {
        res += pow(10, k - i - 1) * tmp[i];
    }
    return res;
}

int g2(int x) {
    //提取x的位数字, 从低位到高位依此放入tmp数组中, 时间复杂度为O(logn)
    int k = 0;
    while (x) {
        if (x % 10 != 0) {
        tmp[k++] = x % 10;
        }
        x /= 10;
    }
    //从低到高排序, 时间复杂度为O(logn)
    sort(tmp, tmp + k); 
    int res = 0;
    //将离散的单个数字折算为最终数字, 时间复杂度为O(logn)
    for (int i = 0;i < k; i++) {
        res += pow(10, k - i - 1) * tmp[i];
    }
    return res;
}

int f (int x) {
    return g1(x) - g2(x);
}

int main ()
{
    //处理输入输出
    cin >> N >> K;
    arr [0] = N;
    //通过前一项算出后一项, 迭代K次
    for (int i = 1; i <= K ; i++) {
        arr [i] = f(arr[i-1]);
    }
    cout << arr[K] <<endl;
    return 0;
}