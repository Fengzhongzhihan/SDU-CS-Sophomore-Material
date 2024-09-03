#include<iostream>
#include<cmath>
using namespace std;
int hit=1;

int main()
{
    int n,m;
    cin>>n>>m;
    if(pow(2,n-1)>=m)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
}