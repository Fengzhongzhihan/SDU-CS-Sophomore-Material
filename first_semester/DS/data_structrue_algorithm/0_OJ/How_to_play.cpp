#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
const int N=610;
int n,t,k;
int transt[N];
int playt[N];
LL sumHappy=0;
int happy[N];
bool st[N];


int main()
{
    cin>>n>>t>>k;

    for(int i=1;i<=n;i++)
        cin>>transt[i];

    for(int i=1;i<=n;i++)
        cin>>playt[i];

    for(int i=1;i<=n;i++)
        cin>>happy[i];

    //从第k个位置出发,进行游玩,最后要回来   
    queue <int>q;
    q.push(k);
    while(q.size())
    {
        auto cur=q.front();
        q.pop();
        st[cur]=true;

        if(cur+1<=n)
            q.push(cur+1);
        else if(cur-1>=1)
            q.push(cur-1);

        
    } 
}