#include"chainNode.h"
#include"linear_list.h"
#include<sstream>
template<class T>
class GraphChain:public LinearList<T>
{
public:
    //似乎没用
    GraphChain()
    {
        firstNode=lastNode=NULL;
        listSize=0;
    }
    GraphChain(int initialCapacity);
    GraphChain(const GraphChain<T>&);
    ~GraphChain();

    //ADT
    bool empty()const  {return listSize==0;}
    int size()const {return listSize;}
    T get(int theIndex)const;
    int indexOf(const T& x)const;
    void erase(int theIndex);
    void insert(int theIndex,const T &x);
    void output(ostream& out)const;
    void checkIndex(int theIndex)const;
    void clear();
    void push_back(const T& x);
    void set(int theIndex,T x); 
    void reverse();
    //新增ADT
    T*  eraseElement(int theVertex);
public:
    chainNode<T>* firstNode;
    chainNode<T>* lastNode;
    int listSize;

};
//赋值构造函数
template<class T>
GraphChain<T>::GraphChain(int initialCapacity)
{
    if(initialCapacity<1)return;
    firstNode=lastNode=NULL;
    listSize=0;
}
//拷贝构造函数
template<class T>
GraphChain<T>::GraphChain(const GraphChain<T>&theList)
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
void GraphChain<T>::checkIndex(int theIndex)const
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
GraphChain<T>::~GraphChain()
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
T GraphChain<T>::get(int theIndex)const
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
int GraphChain<T>::indexOf(const T& x)const
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
void GraphChain<T>::erase(int theIndex)
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
void GraphChain<T>::insert(int theIndex,const T&x)
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
void GraphChain<T>::output(ostream& out)const
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
ostream& operator<<(ostream& out,const GraphChain<T>x)
{
    x.output(out);return out;
}

//后缀元素
template<class T>
void GraphChain<T>::clear()
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
void GraphChain<T>::push_back(const T&x)
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
void GraphChain<T>::set(int theIndex,T x)
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    currentNode->element=x;
    return ;
}

template<class T>
void GraphChain<T>::reverse()
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

template <class T>
inline T*  GraphChain<T>::eraseElement(int theVertex)
{
    chainNode<T> * p= firstNode;
    chainNode<T> *pp=NULL;
    chainNode<T> *returnNode=NULL;
    while(p!=NULL&&p->element!=theVertex)
    {
        pp=p;
        p=p->next;
    }


    if(p==NULL)
        return 0;

    else if(p==firstNode)
    {
        returnNode=p;
        p=p->next;
    }
    else 
    {
        returnNode=p;
        pp->next=p->next;
    }

    listSize--;
    return &returnNode->element;
}
