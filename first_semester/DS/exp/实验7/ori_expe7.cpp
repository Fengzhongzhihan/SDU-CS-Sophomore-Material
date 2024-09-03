#include<iostream>
#ifndef myExceptions_
#define myExceptions_
#include <string>
#include<iostream>

using namespace std;

// illegal parameter value
class illegalParameterValue 
{
   public:
      illegalParameterValue(string theMessage = "Illegal parameter value")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// illegal input data
class illegalInputData 
{
   public:
      illegalInputData(string theMessage = "Illegal data input")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// illegal index
class illegalIndex 
{
   public:
      illegalIndex(string theMessage = "Illegal index")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// matrix index out of bounds
class matrixIndexOutOfBounds 
{
   public:
      matrixIndexOutOfBounds
            (string theMessage = "Matrix index out of bounds")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// matrix size mismatch
class matrixSizeMismatch 
{
   public:
      matrixSizeMismatch(string theMessage = 
                   "The size of the two matrics doesn't match")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// stack is empty
class stackEmpty
{
   public:
      stackEmpty(string theMessage = 
                   "Invalid operation on empty stack")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// queue is empty
class queueEmpty
{
   public:
      queueEmpty(string theMessage = 
                   "Invalid operation on empty queue")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// hash table is full
class hashTableFull
{
   public:
      hashTableFull(string theMessage = 
                   "The hash table is full")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// edge weight undefined
class undefinedEdgeWeight
{
   public:
      undefinedEdgeWeight(string theMessage = 
                   "No edge weights defined")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// method undefined
class undefinedMethod
{
   public:
      undefinedMethod(string theMessage = 
                   "This method is undefined")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};
#endif

using namespace std;

template<class T>
class Queue
{
public:
    virtual ~Queue(){}
    virtual bool empty()const =0;
    virtual int size()const =0;
    virtual T front()=0;
    virtual T back()=0;
    virtual void pop()=0;
    virtual void push(const T& theElement)=0;
};

template<class T>
class ArrayQueue :public Queue<T>
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

int n;
int main()
{
    cin>>n;
    ArrayQueue<int>cards(n+1);
    for(int i=1;i<=n;i++)
    {
        cards.push(i);
    }
    while(cards.size()>=2)
    {
        cards.pop();
        int t=cards.front();
        cards.pop();
        cards.push(t);
    }
    cout<<cards.front()<<endl;
    return 0;
}