#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,c,dl,dw;
    scanf("%lld%lld%lld%lld",&n,&c,&dl,&dw);

    set<pair<long long,long long>> row;//记录行和列上有靶子的位置。为什么用set呢？因为其有序的特性，靶子也是按序击中的
 //所以不要盲目地选择数据结构，而要知道为什么
    set<pair<long long,long long>> col;

    for(int i=0;i<n;i++)
    {
        long long x,y;
        scanf("%lld%lld",&x,&y);
        col.emplace(x,y);
        row.emplace(y,x);
    }

    long long l=1;
    long long w=1;
    int sl=0;
    int sw=0;
    while(!row.empty())
    {
    //解释一下begin，这一步是我实在想不到的，由于set有序性，set的第一个数对应是当前有靶子的最小数，也是打靶人应该站的位置
    //以下是优化，处理两人都离下一个可打靶处非常远的情况
        long long tol=row.begin()->first-l;
        long long tow=col.begin()->first-w;
        if(tol>=dl&&tow>=dw)
        {
            long long step=min(tol/dl,tow/dw);
            l+=step*dl;
            w+=step*dw;
        }

               if(row.begin()->first!=l)
               {
                   l=min(l+dl,row.begin()->first);
               }
               else
               {
                int i=c;
                while(i--&&!row.empty()&&row.begin()->first==l)  
                {
                    col.erase({row.begin()->second,row.begin()->first});
                    row.erase(row.begin());
                    sl++;
                }       
               }
        
            if(col.begin()->first!=w)
            w=min(w+dw,col.begin()->first);
            else
            {
                row.erase({col.begin()->second,col.begin()->first});
                col.erase(col.begin());
                sw++;
            }
    }
    printf("%d %d",sl,sw);
}
