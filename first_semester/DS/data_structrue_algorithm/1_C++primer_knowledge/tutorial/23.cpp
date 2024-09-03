#include<iostream>
using namespace std;

// (1)
// gcd(20,30)=gcd(30,20)=gcd(20,10)=gcd(10,0)=10
// gcd(112,42)=gcd(42,28)=gcd(28,14)=gcd(14,0)=14

// (2)
// 基础部分:y=0,g(x,y)=x
// 递归部分:y!=0 gcd(x,y)=gcd(y,x mod y)

// 证明
// 如果d是a和b的公约数，那么d也是r1和b的公约数，
// 因为a和b之间的关系可以表示为a = b * q1 + r1，其中q1是整数。
// 因此，d也必须是r2和r1的公约数，以此类推，直到余数为0。所以，d是a和b的最大公约数。

int gcd(int x,int y)
{
    if(y==0)return x;
    return (gcd(y,x%y));
}

int main()
{
    cout<<gcd(0,10)<<endl;
    cout<<gcd(20,30)<<endl;
    cout<<gcd(112,42)<<endl;
    //输出结果 10 10 14
}