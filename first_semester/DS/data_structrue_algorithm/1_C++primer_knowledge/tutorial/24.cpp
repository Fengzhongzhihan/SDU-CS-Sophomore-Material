#include<iostream>

using namespace std;
template <class T>
bool is_in(T x,T array[],int pos,int n)
{
    if(pos>=n)return false;
    if(array[pos]==x&&pos<n)
        return true;  
    else 
        return is_in(x,array,pos+1,n);
}


int main()
{
    int array[]={1,4,5,3,4,7,6};
    int x;cin>>x;
    int n=sizeof(array)/sizeof(array[0]);
    if(is_in<int>(x,array,0,n))
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
    //测试: 6 YES 2 NO
}