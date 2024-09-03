#include"queue.h"
#include"myExceptions.h"

template<class T>
class ArrayQueue :public queue<T>
{
public:
    ArrayQueue(int theCapacity=10);
    ~ArrayQueue(){delete[] queue;}
    bool empty() const{return queueBack==queueFront;}
    bool full() const {return (queueBack+1)%arrayLength==queueFront;}
    int size()const {return (queueBack-queueFront+arrayLength)%arrayLength;}
    T front()
    {
        if(empty())
            throw queueEmpty();
        return queue[(queueFront+1)%arrayLength];
    }
    T back()
    {
        if(empty())
            throw queueEmpty();
        return queue[queueBack];
    }
    void pop()
    {
        if(empty())
            throw queueEmpty();
        queueFront=(queueFront+1)%arrayLength;
        queue[queueFront].~T();
    }
    void push(const T& theElement);
    void changeQueueLength();
    void inputQueue();
    
private:
    int queueFront;
    int queueBack;
    int arrayLength;
    T *queue;
};

template <class T>
inline ArrayQueue<T>::ArrayQueue(int theCapacity)
{
    if(theCapacity<1)
        throw illegalParameterValue("Capacity must >0");
    arrayLength=theCapacity;
    queue=new T[theCapacity];
    queueFront=queueBack=0;
}

template <class T>
inline void ArrayQueue<T>::push(const T &theElement)
{
    //扩容
    if(size()==arrayLength-1)
    {
        changeQueueLength();
    }
    queueBack=(queueBack+1)%arrayLength;
    queue[queueBack]=theElement;
}

template <class T>
inline void ArrayQueue<T>::changeQueueLength()
{
    T* newQueue=new T[2*arrayLength];

    int start=(queueFront+1)%arrayLength;
    //未形成环形
    if(start<2)
        copy(queue+start,queue+start+arrayLength-1,newQueue);
    //形成环形
    else
    {
        copy(queue+start,queue+arrayLength,newQueue);
        copy(queue,queue+queueBack+1,newQueue+arrayLength-start);
    }

    queueFront=2*arrayLength-1;
    queueBack=arrayLength-2;
    arrayLength=arrayLength*2;
    delete[]queue;
    queue=newQueue;
}
