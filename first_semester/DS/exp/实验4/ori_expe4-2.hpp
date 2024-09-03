#include"ori_expe4-1.hpp"
template<class T>
void Chain<T>::chainInsertSort()
{
    //对某一个链表中的元素进行排序
    Chain<T> tmp;
    for(int i=0;i<listSize;i++)
    {   //判断每个元素应该在的位置
        if(!i)
        {
            tmp.insert(0,get(0));
            continue;
        }
        int index=tmp.findBiggerIndex(get(i),i);
        tmp.insert(index,get(i));
    }
    firstNode=tmp.firstNode;
    lastNode=tmp.lastNode;
}

template<class T>
int  Chain<T>::findBiggerIndex(const T&x,int range)const
{   
    int index=0;
    for(;index<range;index++)
        if (get(index)>x)break;
    return index;
}

Chain<int> meld(Chain<int>a,Chain<int>b)
{
    Chain<int>c(a);
    Chain<int>::iterator i;
    for(i=b.begin();i!=b.end();i++)
    {
        //在c中找到插入的地方
        int index=c.findBiggerIndex((*i),c.size());
        c.insert(index,(*i));
    }
    return c;
}

// Chain<int> meld(Chain<int>a, Chain<int>b) 
// {
//     chainNode<int>* newFirstNode=new chainNode<int>;
//     chainNode<int>* currentNode=newFirstNode;
//     chainNode<int>*nodeA=a.firstNode;
//     chainNode<int>*nodeB=b.firstNode;
//     while(nodeA!=NULL&&nodeB!=NULL)
//     {
//         if(nodeA->element<=nodeB->element)
//         {
//             currentNode->next=nodeA;
//             nodeA=nodeA->next;
//             cout<<"nodeA="<<nodeA->element<<endl;
//         }
//         else
//         {
//             currentNode->next=nodeB;
//             nodeB=nodeB->next;
//             if(nodeB!=NULL)cout<<"nodeB="<<nodeB->element<<endl;
//         }
//         currentNode=currentNode->next;
//     }
//     currentNode->next=(nodeA==NULL?nodeB:nodeA);
//     Chain<int>c;
//     c.firstNode=newFirstNode->next;
//     c.listSize=a.size()+b.size();
//     return c;
// }    

