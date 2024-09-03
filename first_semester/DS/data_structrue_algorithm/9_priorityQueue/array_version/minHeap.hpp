#pragma once
#include"maxPriorityQueue.h"
template<class T>
class MinHeap:public MaxPriorityQueue<T>
{
public:
    MinHeap(int arraySize)
    {
        arrayLength=arraySize;
        heap=new T[arrayLength];
        heapSize=0;
    }
    void push(const T& theElement);
    void pop();
    const T& top()
    {
        return heap[1];
    }
    int size()const
    {
        return heapSize;
    }
    bool empty()const
    {
        return heapSize==0;
    }
    void initialize(T* theHeap,int heapSize);
    void output(ostream& out)const
    {
        for(int i=1;i<=heapSize;i++)
            out<<heap[i]<<" ";
    }
    void deactiveArray()
    {
        heap=NULL;arrayLength=heapSize=0;
    }

private:
    T *heap;
    int arrayLength;
    int heapSize;
};

template<class T>
void doubleArraySize(T*& heap,int arrayLength)
{
    T* newArray=new T[arrayLength*2];
    copy(heap,heap+arrayLength,newArray);
    delete []heap;
    heap=newArray;
}

//时间复杂度,高度log2n
template <class T>
inline void MinHeap<T>::push(const T &theElement)
{
    //数组满,扩大数组
    if(heapSize==arrayLength-1)
    {
        doubleArraySize(heap,arrayLength);
        arrayLength*=2;
    }
    
    //父节点下沉
    int currentNode=++heapSize;
    while(currentNode!=1&&heap[currentNode/2]>theElement)
    {
        heap[currentNode]=heap[currentNode/2];
        currentNode/=2;
    }

    heap[currentNode]=theElement;
}

//时间复杂度log2n,为高度h
template <class T>
inline void MinHeap<T>::pop()
{
    if(heapSize==0)
    {
        cout<<"heap empty"<<endl;
        return;
    }
    
    heap[1].~T();
    T lastElement=heap[heapSize--];

    int currentNode=1,child=2;

    while(child<=heapSize)
    {
        if(child<heapSize&&heap[child+1]<heap[child])
            child++;
        
        if(lastElement<=heap[child])
            break;


        heap[currentNode]=heap[child];
        currentNode=child;
        child*=2;
    }
    heap[currentNode]=lastElement;
}

//大根堆的初始化,从有孩子的结点开始依此操作
template<class T>
inline void MinHeap<T>::initialize(T* theHeap,int theHeapSize) 
{
    heap=theHeap;
    heapSize=theHeapSize;//5
    for(int root=heapSize/2;root>=1;root--)
    {
        T element=heap[root];
        int cur=root;
        int child=cur*2;

        while(child<=heapSize)
        {
            if(child<heapSize&&heap[child+1]<heap[child])
                child++;
            
            if(element<=heap[child])
                break;
            
            //孩子上移
            heap[cur]=heap[child];
            cur=child;
            child*=2;
        }

        heap[cur]=element;
    }
}

template<class T>
ostream & operator<<(ostream& out,const MinHeap<T> &x)
{
    x.output(out);return out;
}

