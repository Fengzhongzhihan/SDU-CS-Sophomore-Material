#include<iostream>
#include"maxHeap.hpp"
using namespace std;

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