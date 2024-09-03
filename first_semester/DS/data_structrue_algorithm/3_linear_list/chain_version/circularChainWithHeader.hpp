#include"linear_list.h"
#include"chainNode.h"
template<class T>
//改变了构造函数而已
class ChainCircleWithHeader:public LinearList<T>
{
    public:
    //似乎没用
    ChainCircleWithHeader();
    ChainCircleWithHeader(int initialCapacity);
    ChainCircleWithHeader(const ChainCircleWithHeader<T>&);
    ~ChainCircleWithHeader();

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

    protected:
    void checkIndex(int theIndex)const;
    chainNode<T>* headerNode;
    int listSize;
};

template<class T>
ChainCircleWithHeader<T>::ChainCircleWithHeader()
{
    //构造一个空链表
    headerNode=new chainNode<T>();  
    headerNode->next=headerNode;
    listSize=0;
}

template<class T>
int ChainCircleWithHeader<T>::indexOf(const T& x)const
{
    //先把元素x放入头节点
    headerNode->element=x;

    chainNode<T>* currentNode=headerNode->next;
    int index=0;
    while(currentNode!=x)
    {
        currentNode=currentNode->next;
        index++;
    }
    if(currentNode==headerNode)return -1;
    else return index;
}

