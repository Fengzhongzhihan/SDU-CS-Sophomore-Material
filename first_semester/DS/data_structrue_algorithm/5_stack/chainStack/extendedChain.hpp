#include"chainNode.h"
#include"linear_list.h"
#include<sstream>
template<class T>
class extendedChain:public LinearList<T>
{
    public:
    //似乎没用
    extendedChain(int initialCapacity);
    extendedChain(const extendedChain<T>&);
    ~extendedChain();

    //ADT
    virtual bool empty()const  {return listSize==0;}
    virtual int size()const {return listSize;}
    virtual T get(int theIndex)const;
    virtual int indexOf(const T& x)const;
    virtual void erase(int theIndex);
    virtual void insert(int theIndex,const T &x);
    virtual void output(ostream& out)const;

    //后加ADT
    virtual void clear();
    virtual void push_back(const T& x);
    //T3
    void set(int theIndex,T x); 
    //T15
    void reverse();
    //T17
    protected:
    void checkIndex(int theIndex)const;
    chainNode<T>* firstNode;
    chainNode<T>* lastNode;
    int listSize;
};
//赋值构造函数
template<class T>
extendedChain<T>::extendedChain(int initialCapacity)
{
    if(initialCapacity<1)return;
    firstNode=lastNode=NULL;
    listSize=0;
}
//拷贝构造函数
template<class T>
extendedChain<T>::extendedChain(const extendedChain<T>&theList)
{   
    listSize=theList.listSize;
    if(listSize==0)
    {
        firstNode=lastNode=NULL;
        return;
    }
    else
    {
        //先把被copy链表第一个结点作为第一个结点
        //sourceNode:指向被copy的结点
        //targetNode:指向copy链表的尾部结点
        chainNode<T>* sourceNode=theList.firstNode;
        firstNode=new chainNode<T>(sourceNode->element);
        sourceNode=sourceNode->next;
        chainNode<T>* targetNode=firstNode;
        while(sourceNode!=NULL)
        {
            targetNode->next=new chainNode<T>(sourceNode->element);
            targetNode=targetNode->next;
            sourceNode=sourceNode->next;
        }
        targetNode->next=NULL;
        lastNode=targetNode;
    }
}

//检查索引
template<class T>
void extendedChain<T>::checkIndex(int theIndex)const
{
    if(theIndex<0||theIndex>=listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }
}
//析构函数
template<class T>
extendedChain<T>::~extendedChain()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* tmp=firstNode->next;
        delete firstNode;
        firstNode=tmp;
    }
}

//得到元素
template<class T>
T extendedChain<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
    {
        currentNode=currentNode->next;
    }
    return currentNode->element;
}

//查询第一次出现的索引
template<class T>
int extendedChain<T>::indexOf(const T& x)const
{
    chainNode<T>* currentNode=firstNode;
    int index=0;
    while(currentNode!=NULL&&currentNode->element!=x)
    {
        currentNode=currentNode->next;
        index++;
    }
    if(currentNode==NULL)
    return -1;
    else return index;
}

//删除结点
template<class T>
void extendedChain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    //先判断是否删除第0结点
    if(theIndex==0)
    {
        deleteNode=firstNode;
        firstNode=firstNode->next;
    }
    //找到第theIndex-1的位置p
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;

        deleteNode=p->next;
        p->next=deleteNode->next;
    }
    delete deleteNode;
    listSize--;
    chainNode<T>* p=firstNode;
    for(int i=0;i<listSize-1;i++)
    p=p->next;
    lastNode=p;
}

//插入结点
template<class T>
void extendedChain<T>::insert(int theIndex,const T&x)
{
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //无需扩容
    if(theIndex==0)
    firstNode=new chainNode<T>(x,firstNode);
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;
        p->next=new chainNode<T>(x,p->next);
    }
    listSize++;
    chainNode<T>* p=firstNode; 
    for(int i=0;i<listSize-1;i++)
    p=p->next;
    lastNode=p;
}

//输出
template<class T>
void extendedChain<T>::output(ostream& out)const
{
    if(listSize==0)
    {
        out<<"empty";return;
    }
    
    for(chainNode<T>*currentNode=firstNode;currentNode!=NULL;currentNode=currentNode->next)
    {
        out<<currentNode->element<<" ";
    }
}
//重载
template<class T>
ostream& operator<<(ostream& out,const extendedChain<T>x)
{
    x.output(out);return out;
}

//后缀元素
template<class T>
void extendedChain<T>::clear()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
    listSize=0;
}

template<class T>
void extendedChain<T>::push_back(const T&x)
{
    chainNode<T>* newNode=new chainNode<T>(x,NULL);
    if(firstNode==NULL)
        firstNode=lastNode=newNode;
    else
    {
        lastNode->next=newNode;
        lastNode=newNode;
    }
    listSize++;
}

template<class T>
void extendedChain<T>::set(int theIndex,T x)
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    currentNode->element=x;
    return ;
}

template<class T>
void extendedChain<T>::reverse()
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
