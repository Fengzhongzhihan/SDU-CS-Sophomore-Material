#include"chainNode.h"
#include"linear_list.h"
#include<sstream>
template<class T>
class Chain:public LinearList<T>
{
    public:
    //似乎没用
    Chain(int initialCapacity);
    Chain(const Chain<T>&);
    ~Chain();

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
Chain<T>::Chain(int initialCapacity)
{
    if(initialCapacity<1)return;
    firstNode=lastNode=NULL;
    listSize=0;
}
//拷贝构造函数
template<class T>
Chain<T>::Chain(const Chain<T>&theList)
{   
    listSize=theList.listSize;
    if(listSize==0)
    {
        firstNode=lastNode=NULL;
        return;
    }
    else
    {
        //复制第一个结点
        chainNode<T>* sourceNode=theList.firstNode;
        firstNode=new chainNode<T>(sourceNode->element);
        //复制剩余结点
        sourceNode=sourceNode->next;
        chainNode<T>* targetNode=firstNode;
        while(sourceNode!=NULL)
        {
            targetNode->next=new chainNode<T>(sourceNode->element);
            targetNode=targetNode->next;
            sourceNode=sourceNode->next;
        }

        //最后一个结点的next指针置为NULL
        targetNode->next=NULL;
        //lastNode指向最后一个结点
        lastNode=targetNode;
    }
}

//检查索引
template<class T>
void Chain<T>::checkIndex(int theIndex)const
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
Chain<T>::~Chain()
{
    while(firstNode!=NULL)
    {
        //删除第一个结点
        chainNode<T>* tmp=firstNode->next;
        delete firstNode;
        //将tmp赋值给firstNode
        firstNode=tmp;
    }
}

//得到元素
template<class T>
T Chain<T>::get(int theIndex)const
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
int Chain<T>::indexOf(const T& x)const
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
void Chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    //先判断是否删除第0结点
    if(theIndex==0)
    {
        deleteNode=firstNode;
        //将firstNode指向第二个结点, 包含了listSize==1的情况
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
    //更新lastNode, 写出代码
    chainNode<T>* p=firstNode;
    for(int i = 0; i<theIndex-1; i++)
        p = p->next;
    
    
    lastNode = p;
}

//插入结点
template<class T>
void Chain<T>::insert(int theIndex,const T&x)
{
    //检查索引
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //插入第0个结点
    if(theIndex==0)
        firstNode=new chainNode<T>(x,firstNode);
    //找到第theIndex-1个结点
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;
        //在p后面插入
        p->next=new chainNode<T>(x,p->next);
    }

    listSize++;

//更新lastNode
    chainNode<T>* p=firstNode; 
    for(int i=0;i<listSize-1;i++)
        p=p->next;

    lastNode=p;
}

//输出
template<class T>
void Chain<T>::output(ostream& out)const
{
    if(listSize==0)
    {
        out<<"empty";return;
    }
    //链表不为空
    for(chainNode<T>*currentNode=firstNode;currentNode!=NULL;currentNode=currentNode->next)
    {
        //输出结点值
        out<<currentNode->element<<" ";
    }
}
//重载
template<class T>
ostream& operator<<(ostream& out,const Chain<T>x)
{
    x.output(out);return out;
}

//后缀元素
template<class T>
void Chain<T>::clear()
{
    //删除所有结点
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
    listSize=0;
}

//后缀元素
template<class T>
void Chain<T>::push_back(const T&x)
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

//T3
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

//T15
template<class T>
//逆置
void Chain<T>::reverse()
{
    chainNode<T>* currentNode=firstNode;
    chainNode<T>* previousNode=NULL;
    chainNode<T>*nextNode=NULL;
    lastNode=firstNode;
    //逆置
    while(currentNode!=NULL)
    {
        nextNode=currentNode->next;
        currentNode->next=previousNode;
        previousNode=currentNode;
        currentNode=nextNode;
    }
    firstNode=previousNode;
}


