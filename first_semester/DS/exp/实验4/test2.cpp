#include"ori_expe4-2.hpp"
int n,m;
int main()
{
    cin>>n>>m;
    Chain<int>a,b,c;
    while(n--)
    {
        int x;cin>>x;
        a.push_back(x);
    }
    while(m--)
    {
        int x;cin>>x;
        b.push_back(x);
    }
    a.chainInsertSort();
    cout<<a<<endl;
    b.chainInsertSort();
    cout<<b<<endl;
    //实现c的合并
    c=meld(a,b);
    cout<<c<<endl;
    // cout<<c<<endl;
    a.outputXorSum();
    b.outputXorSum();
    c.outputXorSum();
}