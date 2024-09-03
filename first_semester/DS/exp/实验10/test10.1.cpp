#include<iostream>
using namespace std;

template<class T>
class MaxPriorityQueue
{
    public:
        virtual ~MaxPriorityQueue(){}
        virtual bool empty()const =0;
        virtual int size()const=0;
        virtual const T& top()=0;
        virtual void pop()=0;
        virtual void push(const T& theElement)=0;
};


template<class T>
class MinHeap:public MaxPriorityQueue<T>
{
public:
    MinHeap(int arraySize)
    {
        arrayLength=arraySize+1;
        heap=new T[arrayLength];
        heapSize=0;
    }
    ~MinHeap()
    {
        if(heap!=NULL)
            delete[]heap;
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
    delete[]heap;
    heap=theHeap;
    heapSize=theHeapSize;
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

template<class T>
class MaxHeap:public MaxPriorityQueue<T>
{
public:
    MaxHeap(int arraySize)
    {
        arrayLength=arraySize+1;
        heap=new T[arrayLength];
        heapSize=0;
    }

    ~MaxHeap()
    {
        if(heap!=NULL)
            delete[]heap;
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


//时间复杂度,高度log2n
template <class T>
inline void MaxHeap<T>::push(const T &theElement)
{
    //数组满,扩大数组
    if(heapSize==arrayLength-1)
    {
        doubleArraySize(heap,arrayLength);
        arrayLength*=2;
    }
    
    //父节点下沉
    int currentNode=++heapSize;
    while(currentNode!=1&&heap[currentNode/2]<theElement)
    {
        heap[currentNode]=heap[currentNode/2];
        currentNode/=2;
    }

    heap[currentNode]=theElement;
}

//时间复杂度log2n,为高度h
template <class T>
inline void MaxHeap<T>::pop()
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
        if(child<heapSize&&heap[child+1]>heap[child])
            child++;
        
        if(lastElement>=heap[child])
            break;


        heap[currentNode]=heap[child];
        currentNode=child;
        child*=2;
    }
    heap[currentNode]=lastElement;
}

//大根堆的初始化,从有孩子的结点开始依此操作
template<class T>
inline void MaxHeap<T>::initialize(T* theHeap,int theHeapSize) 
{
    delete[]heap;
    heap=theHeap;
    heapSize=theHeapSize;
    for(int root=heapSize/2;root>=1;root--)
    {
        T element=heap[root];
        int cur=root;
        int child=cur*2;

        while(child<=heapSize)
        {
            if(child<heapSize&&heap[child+1]>heap[child])
                child++;
            
            if(element>=heap[child])
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
ostream & operator<<(ostream& out,const MaxHeap<T> &x)
{
    x.output(out);return out;
}



template<class T>
void heapSort(T* a,int n)
{
    MaxHeap<T>heap(1);
    heap.initialize(a,n);
    for(int i=n;i>=1;i--)
    {
        T x=heap.top();
        heap.pop();
        a[i]=x;
    }

    heap.deactiveArray();
}

int main()
{
    int n,m;
    cin>>n;
    MinHeap<int>heap(1); 
    int *arr=new int [n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    heap.initialize(arr,n);
    // for(int i=0;i<n;i++)
    // {
    //     int num;cin>>num;
    //     heap.push(num);
    // }
    cout<<heap.top()<<endl;
    cin>>m;
    while(m--)
    {
        int op;
        cin>>op;
        switch (op)
        {
            case 1:
            {
                int num;
                cin>>num;
                heap.push(num);
                cout<<heap.top()<<endl;
                break;
            }
            case 2:
            {   
                heap.pop();
                cout<<heap.top()<<endl;
                break;
            }
            case 3:
            {
                int count;
                cin>>count;
                int arr[count+1];
                for(int i=1;i<=count;i++)
                    cin>>arr[i];
                heapSort(arr,count);
                for(int i=1;i<=count;i++)
                    cout<<arr[i]<<" ";
                cout<<endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}