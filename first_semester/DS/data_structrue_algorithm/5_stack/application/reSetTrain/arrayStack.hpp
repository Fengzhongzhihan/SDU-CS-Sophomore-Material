#include"stack.h"
#include"myExceptions.h"

template<class T>
class ArrayStack :public stack<T>
{
public:
    ArrayStack(int theCapacity=10);
    ~ArrayStack(){delete[] stack;}
    bool empty() const{return stackTop==-1;}
    int size()const {return stackTop+1;}
    T top()
    {
        if(stackTop==-1)
            throw stackEmpty();
        return stack[stackTop];
    }
    void pop()
    {
        if(stackTop==-1)
            throw stackEmpty();
        stack[stackTop--].~T();
    }
    void push(const T& theElement);
private:
    int stackTop;
    int arrayLength;
    T* stack;
};
template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
        throw illegalParameterValue("the newlength must >0");
    T *temp=new T[newLength];
    int size=min(oldLength,newLength);
    copy(a,a+size,temp);
    delete[]a;
    a=temp;
}

template <class T>
inline ArrayStack<T>::ArrayStack(int theCapacity)
{
    if(theCapacity<1)
        throw illegalParameterValue("Capacity must >0");
    arrayLength=theCapacity;
    stack=new T(theCapacity);
    stackTop=-1;
}

template <class T>
inline void ArrayStack<T>::push(const T &theElement)
{
    if(stackTop+1==arrayLength)
    {
        changeLength(stack,arrayLength,arrayLength*2);
        arrayLength*=2;
    }
    stack[++stackTop]=theElement;
}



