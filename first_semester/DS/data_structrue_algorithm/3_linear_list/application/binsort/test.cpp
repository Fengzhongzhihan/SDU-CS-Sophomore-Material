#include"binSort.hpp"
int main()
{
    // Chain<StudentRecord>x;
    // x.push_back(StudentRecord{10,"limei"});
    // x.push_back(StudentRecord{20,"hanshuang"});
    // x.push_back(StudentRecord{35,"wangshi"});
    // x.push_back(StudentRecord{15,"fwf"});
    // x.push_back(StudentRecord{15,"dqew"});
    // cout<<x;
    // cout<<"------------------"<<endl;
    // binSort(x,35);
    // cout<<x;
    Chain<int>s;
    int n;cin>>n;
    while(n--)
    {
        int x;cin>>x;
        s.push_back(x);
    }
    int r,c=0;
    cin>>r;
    int x=s.max();
    while(x)
    {
        x/=r;c++;
    }
    cout<<"r="<<r<<endl;
    cout<<"c="<<c<<endl;
    cout<<s<<endl;
    //基数排序
    for(int i=1;i<=c;i++)
    {
        radixSort<int>(s,r,i);
         cout<<s<<endl;
    }
}