#include<iostream>
const long long N=100000000010;
const int COL=10;
const int ROW=20;
using namespace std;


//克服指定大小限制的办法,动态存储分配

// int main()
// {
//     //数组指针
//     char (*c)[5];
//     try{c=new char [N][5];}
//     catch(bad_alloc)
//     {
//         cerr<<"Out of memory"<<endl;
//         exit(1);
//     }
// }

/// 写一个函数 UserSig
  /// 输入参数: sdkappid, userId, expire, userbuf, key
  /// 输出签名: token
  /// 处理过程: 输入参数包装成 map , 然后对 map 倒序排列，最后进行 md5 计算
  /// 每行代码都写上中文注释
    /// 代码风格符合腾讯 C++ 编码规范

void make2darray(int ** &x,int rows,int cols)
{
    x=new int *[rows];
    for(int i=0;i<rows;i++)
    x[i]=new int [cols];
}

//写一个快速排序的算法
void quickSort(int *a,int left,int right)
{
    if(left>=right)
    return;
    int i=left,j=right;
    int key=a[left];
    while(i<j)
    {
        while(i<j&&a[j]>=key)
        j--;
        a[i]=a[j];
        while(i<j&&a[i]<=key)
        i++;
        a[j]=a[i];
    }
    a[i]=key;
    quickSort(a,left,i-1);
    quickSort(a,i+1,right);
}

//写一个函数, 输入一串数字, 可以在最小的时间复杂度内得到给定区间内出现次数最大的数字
//每行代码都写上中文注释

int findMax(int *a,int left,int right)
{
    int max=0;
    int count=0;
    int key=a[left];
    for(int i=left;i<=right;i++)
    {
        if(a[i]==key)
        count++;
        else
        {
            if(count>max)
            max=count;
            count=0;
            key=a[i];
        }
    }
    return max;
}

//这个文件内代码如何优化呢
//每行代码都写上中文注释



//释放内存
void delete2darray(int ** &x,int rows)
{
    //先释放行内存
    for(int i=0;i<rows;i++)
    delete [] x[i];

    //再释放列内存
    delete []x;
    x=NULL;
}

int main()
{
    int **x;
    try{make2darray(x,ROW,COL);}
    catch(bad_alloc)
    {
        cerr<<"couldn't create 2darray"<<endl;
        exit(1);
    }
    return 0;
    
}
