#pragma once
#include"dictionary.h"
#include"pairNode.h"
template<class K,class E>
class SortedChain:public Dictionary<K,E>
{
    public:
        bool empty()const
        {
            return chainSize==0;
        }
        int size()const
        {
            return chainSize;
        }
        pair<K,E>* find(const K& )const;
        void insert(const pair<K,E>&);
        void erase(const K&);
        void output(ostream& out)const;
    private:
        PairNode<K,E>* firstNode=NULL;
        int chainSize=0;
};

template <class K, class E>
inline pair<K,E>* SortedChain<K, E>::find(const K &theKey) const
{
    PairNode<K,E>* currentNode=firstNode;
    while(currentNode!=NULL&&currentNode->element.first<theKey)
    {
        currentNode=currentNode->next;
    }
    //匹配上了
    if(currentNode!=NULL&& currentNode->element.first==theKey)
    {
        cout<<chainSize<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
}

template <class K, class E>
inline void SortedChain<K, E>::insert(const pair<K, E> &thePair)
{
    int theKey=thePair.first;
    PairNode<K,E>*tp=NULL;
    PairNode<K,E>*p=firstNode;
    while(p!=NULL&&p->element.first<theKey)
    {
        tp=p;
        p=p->next;
    }

    //找到了相同关键字
    if(p!=NULL&&p->element.first==theKey)
    {
       cout<<"Existed"<<endl;
    }
    //没找到
    else 
    {
        PairNode<K,E> *newNode=new PairNode<K,E>(thePair,p);
        if(tp==NULL)
            firstNode=newNode;
        else 
        {
            tp->next=newNode;
        }
        chainSize++;
    }
    return ;
}

template <class K, class E>
inline void SortedChain<K, E>::erase(const K &theKey) 
{
    PairNode<K,E>*tp=NULL;
    PairNode<K,E>*p=firstNode;
    while(p!=NULL&&p->element.first<theKey)
    {
        tp=p;
        p=p->next;
    }
    //找到了
    if(p!=NULL&&p->element.first==theKey)
    {
        //找到了第一个结点
        if(tp==NULL)
            firstNode=p->next;
        else 
        {
            tp->next=p->next;
        }
        delete p;
        chainSize--;
        cout<<chainSize<<endl;
    }
    //没找到
    else 
    {
        cout<<"Delete Failed"<<endl;
        return ;
    }
}

template<class K,class E>
void SortedChain<K,E>::output(ostream& out)const
{
    for(PairNode<K,E>* curruntNode=firstNode;curruntNode!=NULL;
    curruntNode=curruntNode->next)
    {
        auto k=curruntNode->element;
        out<<k.first<<" "<<k.second<<" ";
    }
}

template<class K,class E>
ostream & operator<<(ostream& out,const SortedChain<K,E>& x)
{
    x.output(out);return out;
}
