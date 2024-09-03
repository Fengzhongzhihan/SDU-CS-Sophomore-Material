#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;
typedef long long LL;
int n;
int price[N];

LL endEarning=0;
int endPrice=N;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&price[i]);
    }

    sort(price,price+n);

    for(int i=0;i<n;i++)
    {
        LL earning=(n-i)*price[i];

        if(earning>endEarning)
        {
            endPrice=price[i];
            endEarning=earning;
        }
    }

    cout<<endEarning<<" "<<endPrice;  
}