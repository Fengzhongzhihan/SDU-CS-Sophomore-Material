#include"linear_list.h"
#include<algorithm>
#include<sstream>
#include<iterator>

template<class T>
class arrayList:public LinearList<T>
{
    public:
    arrayList(int initialCapacity);
    arrayList(const arrayList<T>&);
    arrayList(){};
    ~arrayList(){delete [] element;}

    //重写父类虚构函数
     virtual bool empty()const  {return listSize==0;}
     virtual int size()const {return listSize;}
     virtual T get(int theIndex)const;
     virtual int indexOf(const T&x)const;
     virtual void erase(int theIndex);
     virtual void insert(int theIndex,const T &x);
     virtual void output(ostream& out)const;
    //其他函数
    int capacity()const{return arrayLength;}
    void push_back(const T&x);
    void pop_back();
    void reserve(int theCapacity);
    void clear();

    //迭代器
    class iterator
    {
    public:
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        //构造函数
        iterator(T* thePosition=0){position=thePosition;}

        T& operator*()const {return *position;}
        T* operator->()const {return &*position;}

        iterator& operator++(){++position;return *this;}
        iterator operator++(int){iterator old=*this;++position;return old;}
        iterator& operator--(){--position;return *this;}
        iterator operator--(int){iterator old=*this;--position;return old;}
        bool operator!=(const iterator right)const {return position!=right.position;}
        bool operator==(const iterator right)const {return position==right.position;}
    protected :
        T* position;
    };
    //迭代器函数
    iterator begin(){return iterator(element);}
    iterator end(){return iterator(element+listSize);}
    protected:
    void checkIndex(int theIndex)const;
    T* element;
    int arrayLength=0;
    int listSize=0;
};


template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)return;
    T *temp=new T[newLength];
    int size=min(oldLength,newLength);
    copy(a,a+size,temp);
    delete[]a;
    a=temp;
}

//直接构造函数
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity<1)return;
    arrayLength=initialCapacity;
    element=new T[arrayLength];
}

//拷贝函数
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
   arrayLength= theList.arrayLength;
   element=new T[arrayLength];
   listSize=theList.listSize;;
   copy(theList.element,theList.element+listSize,element);
}
//检查是否合法
template<class T>
void arrayList<T>::checkIndex(int theIndex)const
{
    if(theIndex<0||theIndex>=listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }
}
//返回元素
template<class T>
T arrayList<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    return element[theIndex];
}

//找索引
template<class T>
int arrayList<T>::indexOf(const T&x)const
{
    int theIndex=(int)(find(element,element+listSize,x)-element);
    if(theIndex==listSize)
    return -1;
    else return theIndex;
}

//根据索引删除一个元素
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element+theIndex+1,element+listSize,element+theIndex);
    //释放最后一个元素的内存
    element[--listSize].~T();
}

//插入函数
template<class T>
void arrayList<T>::insert(int theIndex,const T&x)
{
    //检查是否为有效索引,可以写到末尾即listSize
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //满了则扩容
    if(listSize==arrayLength)
    {
        changeLength(element,listSize,listSize*2);
        arrayLength*=2;
    }
    //插入,往后移动
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex]=x;
    listSize++;
}

//输出
template<class T>
void arrayList<T>::output(ostream&out)const
{
    if(listSize==0)
    {
        cout<<"empty";return;
    }
    //在元素之间插入空格
    copy(element,element+listSize,ostream_iterator<T>(out," "));
}

//重载
template<class T>
ostream& operator<<(ostream & out,const arrayList<T>&arr)
{
    arr.output(out);return out;
}

//尾部插入一个元素
template<class T>
void arrayList<T>::push_back(const T&x)
{
    if(listSize==arrayLength)
    {
        changeLength(element,arrayLength,arrayLength*2);
        arrayLength*=2;
    }

    element[listSize++]=x;
}

//尾部删除一个元素
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


//保留长度
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

//清空线性表
template<class T>
void arrayList<T>::clear()
{
    listSize=0;
    arrayLength=0;
    delete []element;
    element=NULL;
}

