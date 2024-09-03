#include"chain.hpp"
#include"extendedChain.hpp"
//T3 时间复杂度O(listSize)
template<class T>
void Chain<T>::set(int theIndex,T x)
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    currentNode->element=x;
    return ;
}
//T15 时间复杂度O(listSize)
template<class T>
void Chain<T>::reverse()
{
    chainNode<T>* currentNode=firstNode;
    chainNode<T>* previousNode=NULL;
    chainNode<T>*nextNode=firstNode;
    lastNode=firstNode;
    while(currentNode!=NULL)
    {
        nextNode=currentNode->next;
        currentNode->next=previousNode;
        previousNode=currentNode;
        currentNode=nextNode;
    }
    firstNode=previousNode;
}
//T17 时间复杂度O(listsizeA+listSizeB)
template<class T>
extendedChain<T>* meld(extendedChain<T> a,extendedChain<T>b)
{
    extendedChain<T>c;
    int i=0,j=0;
    while(i<a.size()&&j<b.size())
    {
        T val_a=a.get(i++);
        T val_b=b.get(j++);
        c.push_back(val_a);
        c.push_back(val_b);
    }
    //如果a到头了,就遍历b
    if(i==a.size())
    {
        while(j<b.size())
        {
            T val_b=b.get(j++);
            c.push_back(val_b);
        }
    }
    //如果b到头了,就遍历a
    else
    {
        while(i<a.size())
        {
            T val_a=a.get(i++);
            c.push_back(val_a);
        }
    }
    return c;
}
