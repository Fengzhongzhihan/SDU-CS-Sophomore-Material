
template <class T>
class ExtendedArrayQueue :public Queue<T>,public ExtendedQueue<T>
{
    public:
    ExtendedArrayQueue(int theCapacity=10);
    ExtendedArrayQueue(){delete[] queue;}
    bool empty() const{return queueBack==queueFront;}
    bool full() const {return queueFront==(queueBack+1)%arrayLength;}
    int size()const {return (queueBack-queueFront+arrayLength)%arrayLength;}
    int capacity()const {return arrayLength;}
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
    void doubleQueueLength();
    //新增ADT
    void inputQueue();
    void outputQueue();
    void devideQueue();
    void mergeQueue();
    void clear();
private:
    int queueFront;
    int queueBack;
    int arrayLength;
    T *queue;
};

template <class T>
inline ExtendedArrayQueue<T>::ExtendedArrayQueue(int theCapacity)
{
    if(theCapacity<1)
        throw illegalParameterValue("Capacity must >0");
    arrayLength=theCapacity;
    queue=new T[theCapacity];
    queueFront=queueBack=0;
}

template <class T>
inline void ExtendedArrayQueue<T>::push(const T &theElement)
{
    //扩容
    if(full())
    {
        doubleQueueLength();
    }
    queueBack=(queueBack+1)%arrayLength;
    queue[queueBack]=theElement;
}

template <class T>
inline void ExtendedArrayQueue<T>::doubleQueueLength()
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
    arrayLength*=2;
    delete[]queue;
    queue=newQueue;
}

template <class T>
inline void ExtendedArrayQueue<T>::inputQueue()
{
    T element;
    cin>>element;
    push(element);
}

template <class T>
inline void ExtendedArrayQueue<T>::outputQueue()
{
    for(int queueCurrent=(queueFront+1)%arrayLength;queueCurrent!=(queueBack+1)%arrayLength;queueCurrent=(queueCurrent+1)%arrayLength)
    {
        cout<<queue[queueCurrent]<<" ";
    }
    cout<<endl;
}

template <class T>
inline void ExtendedArrayQueue<T>::devideQueue()
{
    ExtendedArrayQueue<T>p1(10),p2(10);
    bool flag=true;
    for(int queueCurrent=(queueFront+1)%arrayLength;queueCurrent!=(queueBack+1)%arrayLength;queueCurrent=(queueCurrent+1)%arrayLength)
    {
        int t=queue[queueCurrent];
        if (flag)
        {
            p1.push(t);
            flag=false;
        }
        else 
        {
            p2.push(t);
            flag=true;
        }
    }
    cout<<"divide result"<<endl;
    cout<<"p1: "<<endl;
    p1.outputQueue();
    cout<<"p2: "<<endl;
    p2.outputQueue();
}

template <class T>
inline void ExtendedArrayQueue<T>::mergeQueue()
{
    clear();

    ExtendedArrayQueue<T>p1(10),p2(10);
    cout<<"enter numbers of values of p1 and p2"<<endl;
    int n,m;cin>>n>>m;
    cout<<"enter values of p1 and p2"<<endl;
    while(n--)p1.inputQueue();
    while(m--)p2.inputQueue();
    
    bool flag=true;
    while(!p1.empty()&&!p2.empty())
    {
        T value1=p1.front();
        T value2=p2.front();
        if(flag)
        {
            push(value1);
            p1.pop();
            flag=false;
        }
        else 
        {
            push(value2);
            p2.pop();
            flag=true;
        }
    }
    while(!p1.empty())
    {
        push(p1.front());
        p1.pop();
    }
    while (!p2.empty())
    {
        push(p2.front());
        p2.pop();
    }
    cout<<"merge result"<<endl;
    outputQueue();
}

template <class T>
inline void ExtendedArrayQueue<T>::clear()
{
    queueFront=queueBack=0;
}