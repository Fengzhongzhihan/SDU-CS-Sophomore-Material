#pragma once
#include<iostream>
using namespace std;
template<class K,class E>
class hashTable
{
public:
    hashTable(int theDivisor);
    ~hashTable(){delete[]table;}
    bool empty()const {return dSize==0;}
    int size()const {return dSize;}
    int searchIndex(const K&theKey)const;
    void findPair(const K&theKey)const;
    void insert(const pair<K,E>& thePair);
    void erase(const K&theKey);
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
// 搜索对应的桶的编号
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
inline void hashTable<K, E>::findPair(const K &theKey) const
{
    int b=searchIndex(theKey);
    //找不到
    if(table[b]==NULL||table[b]->first!=theKey)
        cout<<"-1"<<endl;
    else 
        cout<<b<<endl; 
}

template <class K, class E>
inline void hashTable<K, E>::insert(const pair<K, E> &thePair)
{
    int b=searchIndex(thePair.first);
    //有相关位置
    if(table[b]==NULL)
    {
        table[b]=new pair<K,E> (thePair);
        cout<<b<<endl;
        dSize++;
    }
    else
    {
        //检查是有相同的关键字,还是表满了
        if(table[b]->first==thePair.first)
        {
            cout <<"Existed"<<endl;
        }
        else
        {
            return ;
        }
    }
}

template <class K, class E>
inline void hashTable<K, E>::erase(const K &theKey)
{
    int b=searchIndex(theKey);
    int a,origin;
    a=origin=b;
    int ct=0;
    //没找到
    if(table[b]==NULL||table[b]->first!=theKey)
    {
        cout<<"Not Found"<<endl;
    }
    else
	{	
		table[b] = NULL;
		b=(b+1)%divisor ;
		while(table[b] != NULL && b!= origin)
		{
            //应该在的位置
			int m=(table[b]->first)%divisor;
            //需要交换位置的三种情况
			if ((b!=m)&&(((m<=a)&&(b>a))||((m>b)&&((m<=a)||(b>a)))))
			{
				table[a]=table[b];
				table[b] = NULL;
				a=b;
				ct++;
			}
		   b=(b+1) % divisor; 		 
		}		
        cout<<ct<<endl;
	}
}


