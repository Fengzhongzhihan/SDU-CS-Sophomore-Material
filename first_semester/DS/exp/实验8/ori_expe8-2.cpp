#pragma once
#pragma once
#pragma once
#include<iostream>
using namespace std;

template <class K> 
class Hash {
public:
    size_t operator()(const int theKey) const {
        return size_t(theKey);
    }
};

template<class K ,class E>
class Dictionary
{
    public:
        virtual ~Dictionary(){}
        virtual bool empty()const=0;
        virtual int size()const=0;
        virtual pair<K,E>* find(const K&)const=0;
        virtual void erase(const K&)=0;
        virtual void insert(const pair<K,E>&)=0;
};
#pragma once
#include<iostream>
using namespace std;
template<class K,class E>
struct PairNode
{
    pair<K,E> element;
    PairNode<K,E>*next;
    PairNode(const pair<K,E>thePair,PairNode<K,E>*nextNode)
    {
        element=thePair;
        next=nextNode;
    }
    PairNode(){}
};
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
    Hash<K>hash;
};

template<class K,class E>
ostream& operator<<(ostream &mout,const HashChains<K,E>&x)
{
    x.output(mout);return mout;
}

int d,m;
int main()
{
    cin>>d>>m;
    HashChains<int,int>s(d);
    while(m--)
    {
        int opt,x;
        cin>>opt>>x;
        switch (opt)
        {
            case 0:
            {
                s.insert(pair<int,int>(x,x));
                break;
            }
            case 1:
            {
                s.findPair(x);
                break;
            }
            case 2:
            {
                s.erase(x);
                break;
            }
            default:
                break;
        }
    }
}