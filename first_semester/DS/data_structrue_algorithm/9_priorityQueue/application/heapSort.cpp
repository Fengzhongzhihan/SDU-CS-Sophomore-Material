#include"heapSort.hpp"

int main()
{
    int a[6]={0,3,6,4,2,9};
    heapSort(a,5);
    for(int i=1;i<=5;i++)
    {
        cout<<a[i]<<" ";
    }

    heapSort.deactiveArray();
}