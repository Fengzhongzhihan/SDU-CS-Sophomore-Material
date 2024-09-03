#include"maxHeap.hpp"
int main()
{
    MaxHeap<int>s(2);
    // s.push(3);  
    // s.push(2);
    // s.push(5);
    // s.push(5);
    // s.push(1);
    // cout<<s<<endl;
    // s.pop();
    // cout<<s<<endl;
    // s.push(4);
    // cout<<s<<endl;
    // s.pop();
    // cout<<s<<endl;
    int a[]={0,3,5,2,1,6};
    int len=sizeof(a)/sizeof(a[0]);
    s.initialize(a,len-1);
    cout<<s<<endl;
    return 0;
}