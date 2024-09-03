#include"queue.h"

template <class T>
class ExtendedQueue:public Queue<T>
{
public:
    virtual void inputQueue() =0;
    virtual void outputQueue()=0;
    virtual void devideQueue()=0;
    virtual void mergeQueue()=0;
};

