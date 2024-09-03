#include"chain.hpp"
template<class T>
// 3 4 8 1 2  //3-5
//先找到起始的节点
chainNode<T>* getCommonNode(Chain<T>a,Chain<T>b)
{
    chainNode<T>* p1=a.firstNode;
    chainNode<T>* p2=b.firstNode;
    int len1=0,len2=0;
    while(p1!=NULL)
    {
        p1=p1->next;
        len1++;
    }
    while(p2!=NULL)
    {
        p2=p2->next;
        len2++;
    }
    if(len1>len2)
    for(int i=0;i<len1-len2;i++)
    {
        p1=p1->next;
    }
    else
    for(int i=0;i<len2-len1;i++)
    {
        p2=p2->next;
    }
    while(p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
}