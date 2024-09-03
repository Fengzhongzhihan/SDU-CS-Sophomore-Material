#include<iostream>
#include<numeric>
#include<iterator>
#include<algorithm>
using namespace std;

//accumulate 
//累加和
int sum(int a[],int n)
{
    int theSum=0;
    return accumulate(a,a+n,theSum);
}

// copy和next_permutation
void permutations(int list[],int k,int m)
{
    do
    {
        copy(list,list+m+1,ostream_iterator<int>(cout,""));
        cout<<endl;
    }while(next_permutation(list,list+m+1));
}


int main()
{
    int a[]={1,2,3};
    permutations(a,0,2);
}