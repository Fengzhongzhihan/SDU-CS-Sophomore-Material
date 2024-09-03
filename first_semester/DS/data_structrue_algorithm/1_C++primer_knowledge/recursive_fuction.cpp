#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

// 计算n的阶乘
int factorial(int n)
{
    if(n==1)return 1;
    else return (factorial(n-1)*n);
}

// 计算n个元素的和的非递归实现
int sum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    return sum;
}

//递归实现
int rec_sum(int a[],int n)
{
    if(n>0)
    return (sum(a,n-1)+a[n-1]);
    return 0;
}
//全排列,前缀为list[0:k-1],后缀为list[k:m]
void permutations(int list[],int k,int m)
{
    if(k==m)
    {
        copy(list,list+m+1,ostream_iterator<int>(cout, ""));
        cout<<endl;
    }
    else
    for(int i=k;i<=m;i++)
    {
        swap(list[k],list[i]);
        permutations(list,k+1,m);
        swap(list[k],list[i]);
    }
}

这段代码是一个 C++ 函数，用于生成一个数组的所有排列。函数的参数包括一个整数数组 list，以及两个整数 k 和 m，其中 k 是我们要开始排列的数组的起始索引，m 是结束索引。

如果 k 等于 m，说明我们已经到达了数组的末尾，此时我们就可以输出当前的排列。这是通过 copy 函数和 ostream_iterator 实现的，它们将数组的元素复制到 cout，也就是标准输出。

如果 k 不等于 m，我们就需要生成从 k 到 m 的所有排列。这是通过一个循环和递归调用 permutations 函数实现的。在循环中，我们首先交换 k 和 i 的位置，然后递归地生成剩余元素的所有排列，最后再将 k 和 i 的位置交换回来。这种方法被称为回溯法，它是一种常用的生成排列、组合等的方法。

总的来说，这个函数是一个典型的使用回溯法生成排列的例子。

int main()
{
    // cout<<factorial(3)<<endl;
    // int a[]={1,2,3,5,6};
    // int n=sizeof(a)/sizeof(a[0]);
    // cout<<sum(a,n)<<endl;
    // cout<<rec_sum(a,n)<<endl;
    int list[]={1,2,3};
    int n=sizeof(list)/sizeof(list[0]);

    permutations(list,0,n-1);
}