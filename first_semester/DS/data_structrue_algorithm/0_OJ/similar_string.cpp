#include<iostream>
const int N=100010;
using namespace std;
string mstr[N];
int n,m,k;
int res;

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        mstr[i]=str;
    }
    string tstr;
    cin>>tstr;

    for(int i=0;i<n;i++)
    {
        int dif=0;
        string str=mstr[i];
        
        int len=str.size();
        for(int j=0;j<len;j++)
        {
            if(str[j]!=tstr[j])
                dif++;
        }
        if(dif<=k)
            res++;
    }

    cout<<res;
    return 0;
}