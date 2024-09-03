//11题答案
//时间复杂度最好为O(1),最差为O(listSize)
template<class T>
void arrayList<T>::push_back(const T&x)
{
    if(listSize==arrayLength)
    {
        changeLength(element,listSize,listSize*2);
        arrayLength*=2;
    }

    element[listSize++]=x;
}

//12题答案
//时间复杂度为O(1)
template<class T>
void arrayList<T>::pop_back()
{
    if(listSize<=0)
    {
        cout<<"already empty"<<endl;
        return;
    }
    else
     element[--listSize].~T();
}


//14题答案
//时间复杂度为O(1)
template<class T>
void arrayList<T>::reserve(int theCapacity)
{
    if(theCapacity<=0)
    {
        cout<<"theCapacity should be >0";
        return;
    }
    arrayLength=max(arrayLength,theCapacity);
}

//16题答案
//时间复杂度为O(1)
template<class T>
void arrayList<T>::clear()
{
    listSize=0;
    arrayLength=0;
    delete []element;
    element=NULL;
}
#include"array_list.hpp"
int main()
{    //创建一个容量为100的线性表
    arrayList<int>s(1);
    s.push_back(2);
    cout<<s<<endl;//2
    s.push_back(3);
    cout<<s<<endl;//2 3
    s.pop_back();
    cout<<s<<endl;//2
    s.pop_back();
    cout<<s<<endl;//empty 
    cout<<s.capacity()<<endl;
    s.reserve(20);
    cout<<s.capacity()<<endl;
    s.push_back(2);
    s.clear();
    cout<<s<<endl;
    return 0;
}