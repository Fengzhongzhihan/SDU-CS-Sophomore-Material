#include<iostream>
#include<math.h>
using namespace std;
int n,value_index;
const int N=20;
//举例 0 00 000 0000 0001 0010
//index表示数组的第一个下标
int work_subSet(int arr[],int sup[],int sub_value[],int index)
{   
    for(int i=0;i<=1;i++)
    {   //表示将sup的位置依此赋为0/1
        sup[index]=i;
        // 如果递归已到头
        if(index==n-1)
        {   int tmpsum=0;
            int tmp[n];
            int sub_index=0;

            //将标号为1的元素放入tmp数组中
            for(int j=0;j<n;j++)
            {
                if(sup[j]==1)
                {
                    tmp[sub_index++]=arr[j];
                }
            }

            //求出tmp数组的价值
            for(int j=0;j<sub_index;j++)
            {
                tmpsum+=(tmp[j]*(j+1));
            }

            //将这个价值存入subvalue中
            sub_value[value_index++]=tmpsum;
        }
        //如果递归还没有到头
        else
        {
            work_subSet(arr,sup,sub_value,index+1);
        }
    }
}

int main()
{    cin>>n;
    int arr[n],sub_value[int(pow(2,n))],sup[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    // 求出各个子集和子集价值
    work_subSet(arr,sup,sub_value,0);
    // 处理最终结果
    int ans=sub_value[0];
    for(int i=1;i<int(pow(2,n));i++)
    {
        ans^=sub_value[i];
    }
    cout<<ans;
    return 0;
}