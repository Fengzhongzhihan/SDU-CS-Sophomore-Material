#include<iostream>
#include<cstring>
using namespace std;
string s,res="";
int main()
{
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        char c=s[i];
        if(c!='Z')
            res+=c;
    }
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i];
    }
    return 0;
}