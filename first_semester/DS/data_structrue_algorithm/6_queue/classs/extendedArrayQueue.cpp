#include"extendedArrayQueue.hpp"
int main()
{
    ExtendedArrayQueue<int>s(2);
    int n;cin>>n;
    while(n--)
        s.inputQueue();
    cout<<"size: "<<s.size()<<" capacity "<<s.capacity()<<endl;
    s.outputQueue();
    s.devideQueue();
    s.mergeQueue();
    return 0;
}