#pragma once
#include<iostream>
using namespace std;
#include"myExceptions.h"

template<class K,class E>
class hashTable
{
public:
    hashTable(int theDivisor);
    ~hashTable(){delete[]table;}
    bool empty()const {return dSize==0;}
    int size()const {return dSize;}
    
    int searchIndex(const K&theKey)const;
    pair<K,E>* findPair(const K&theKey)const;
    void insert(const pair<K,E>& thePair);
private:
    hash<K> hash;
    pair<K,E>** table;
    int dSize;
    int divisor;
};

template <class K, class E>
inline hashTable<K, E>::hashTable(int theDivisor)
{
    divisor=theDivisor;
    dSize=0;

    table =new pair<K,E>* [divisor];
    for(int i=0;i<divisor;i++)
        table[i]=NULL;
}

//搜索对应的桶的编号
template <class K, class E>
inline int hashTable<K, E>::searchIndex(const K &theKey) const
{
    int i=(int)hash(theKey) %divisor;
    int j=i;
    do
    {
        if(table[j]==NULL||table[j]->first==theKey)
            return j;
        j=(j+1)%divisor;
    } while (j!=i);
    //如果表已经满了,回到了原来的位置
    return j;
}

//找到对应的pair
template <class K, class E>
inline pair<K, E> *hashTable<K, E>::findPair(const K &theKey) const
{
    int b=searchIndex(theKey);
    //没有找到
    if(table[b]!=NULL&&table[b]->first==theKey)
        return table[b];
    else 
        return NULL;
}

template <class K, class E>
inline void hashTable<K, E>::insert(const pair<K, E> &thePair)
{
    int b=searchIndex(thePair.first);
    //有相关位置
    if(table[b]==NULL)
    {
        table[b]=new pair<K,E> (thePair);
        dSize++;
    }
    else
    {
        //检查是有相同的关键字,还是表满了
        if(table[b]->first==thePair.first)
        {
            table[b]->second=thePair.second;
        }
        else
        {
            throw hashTableFull();
        }
    }
}


