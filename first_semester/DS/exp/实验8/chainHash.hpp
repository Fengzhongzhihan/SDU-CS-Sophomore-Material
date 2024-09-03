#pragma once
#include"sortedChain.hpp"

template<class K,class E>
class HashChains
{
public:
    HashChains(int theDivisor)
    {
        divisor=theDivisor;
        dSize=0;
        table=new SortedChain<K,E>[divisor];
    }
    ~HashChains()
    {
        delete[] table;
    }
    bool empty()const
    {
        return dSize==0;
    }
    int size()const
    {
        return dSize;
    }
    pair<K,E>* findPair(const K&theKey)const
    {
        return table[hash(theKey)%divisor].find(theKey);
    }
    void insert(const pair<K,E>& thePair)
    {
        int homeBucket=(int)hash(thePair.first)%divisor;
        int homeSize=table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if(table[homeBucket].size()>homeSize)
            dSize++;
    }
    void erase(const K& theKey)
    {
        table[hash(theKey)%divisor].erase(theKey);
    }
    void output(ostream& mout)const
    {
        for(int i=0;i<divisor;i++)
            if(table[i].size()==0)
                mout<<"NULL"<<endl;
            else
                mout<<table[i]<<endl;
    }

private:
    int divisor;
    SortedChain<K,E>* table;
    int dSize;
    hash<K>hash;
};

template<class K,class E>
ostream& operator<<(ostream &mout,const HashChains<K,E>&x)
{
    x.output(mout);return mout;
}
