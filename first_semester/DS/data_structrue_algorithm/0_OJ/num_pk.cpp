#include<iostream>
using namespace std;
typedef long long LL;
int n;

int main()
{
    cin>>n;
    
    while(n--)
    {
        LL l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;

        //[l1,r1]   [l2,r2]
        if(l1>l2)
        {
            if(r2<=r1)
            {
                cout<<"Nitori Win"<<endl;
            }
            else 
            {
                if(l1+r1>l2+r2)
                    cout<<"Nitori Win"<<endl;
                else if(l1+r1==l2+r2)
                    cout<<"Draw"<<endl;
                else 
                    cout<<"Takane Win"<<endl;
            }
        }

        else if(l1==l2)
        {
            if(r2<r1)
            {
                cout<<"Nitori Win"<<endl;
            }
            else if(r2==r1)
            {
                cout<<"Draw"<<endl;
            }
            else 
                cout<<"Takane Win"<<endl;
        }

        else 
        {
            if(r2>=r1)
            {
                cout<<"Takane Win"<<endl;
            }
            else 
            {
                if(l1+r1>l2+r2)
                    cout<<"Nitori Win"<<endl;
                else if(l1+r1==l2+r2)
                    cout<<"Draw"<<endl;
                else 
                    cout<<"Takane Win"<<endl;
            }
        }
    }
}