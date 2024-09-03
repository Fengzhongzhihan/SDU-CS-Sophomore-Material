#include"stack.h"
#include"chainNode.h"
#include"myExceptions.h"
template<class T>
class linkedStack:public stack<T>
{
public:
    linkedStack(int theCapacity=10)
    {
        stackTop=NULL;
        stackSize=0;
    }
    ~linkedStack();
    bool empty()const
    {
        return stackSize==0;
    }
    int size()const 
    {
        return stackSize;
    }
    T top()
    {
        if(stackSize==0)
            throw stackEmpty();
        return stackTop->element;
    }
    void pop();
    void push(const T& theElement)
    {
        stackTop=new chainNode<T>(theElement,stackTop);
        stackSize++;
    }

    void pushNode(chainNode<T>* theNode);
    T popNode();

private:
    int stackSize;
    chainNode<T>* stackTop;
};

template <class T>
inline linkedStack<T>::~linkedStack()
{
   while(stackTop!=NULL)
    {
        chainNode<T>* nextNode=stackTop->next;
        delete stackTop;
        stackTop=nextNode;
    }
}

 
template<class T>
inline void linkedStack<T>::pop()
{
    if(stackSize==0)
        throw stackEmpty();
    
    chainNode<T>* nextNode=stackTop->next;
    delete stackTop;
    stackTop=nextNode;
    stackSize--;
}

template <class T>
inline void linkedStack<T>::pushNode(chainNode<T> *theNode)
{
    theNode->next=stackTop;
    stackTop=theNode;
    stackSize++;
}

template <class T>
inline T linkedStack<T>::popNode()
{
    if(empty())
        throw stackEmpty();
    chainNode<T>* deleteNode=stackTop;
    T value=deleteNode->element;
    stackTop=stackTop->next;
    stackSize--;
    delete deleteNode;
    return value;
}
