#include"chain.hpp"
#include<math.h>
//基数排序
template<class T>
void radixSort(Chain<T>& theChain,int r,int k)
{
    //先初始化箱子,为一个数组,数组里面存的是链表
    Chain<T>* bin=new Chain<T>[r+1];
    
    //取出链表中所有数字信息
    int numberOfIndex=theChain.size();
    for(int i=0;i<numberOfIndex;i++)
    {
       int  x=theChain.get(0);
       theChain.erase(0);
       //取出第k位数字
       int num=(x%(int)(pow(r,k)))/(pow(r,k-1));
       bin[num].insert(0,x);
    }
    //从最后一个链表开始,取出信息在链表进行头插
    for(int j=r;j>=0;j--)
    {
        while(!bin[j].empty())
        {
            T x=bin[j].get(0);
            theChain.insert(0,x);
            bin[j].erase(0);
        }
    }
    delete []bin;
}