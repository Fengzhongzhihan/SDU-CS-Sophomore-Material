#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
template <class T>
struct chainNode {
    T element;
    chainNode<T>* next;
    //构造函数
    chainNode() = default;
    chainNode(const T& element) 
    {
        this->element = element;
        next = NULL;
    }
    chainNode(const T& element, chainNode<T>* next)
     {
        this->element = element;
        this->next = next;
    }
};
template<class T>
class Chain
{   
public:
    //构造函数
    Chain(){};
    Chain(const Chain<T>&x)
    {
        firstNode=x.firstNode;
        lastNode=x.lastNode;
        listSize=x.listSize;
    }
    // 迭代器
    class iterator 
    {
    public:
        typedef forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        // 构造函数
        iterator(chainNode<T>* theNode = NULL)
        {
            node = theNode;
        }
        // 解引用操作符
        T& operator*() const { return node->element; }
        T* operator->() const { return &node->element; }
        // 迭代器加法操作
        iterator& operator++() {// 前置自增
            node = node->next;
            return *this;
        }
        iterator operator++(int) {// 后置自增
            iterator old = *this;
            node = node->next;
            return old;
        }
        // 相等检验
        bool operator!=(const iterator right) const
         {
            return node != right.node;
        }
        bool operator==(const iterator right) const 
        {
            return node == right.node;
        }
    protected:
        chainNode<T>* node;
    }; 
     iterator begin() { return iterator(firstNode); }
    iterator end() { return iterator(NULL); }
    //结束
//函数  
    void output(ostream &out)const ;
    void push_back(const T &x);
    void insert(int theIndex,const T&x);
    int findIndex(const T&x)const;
    bool erase(const T& val);
    void reverse();
    void outputXorSum();
    int  findRightIndex(const T&x,int range)const;
    void chainInsertSort();
    int size(){return listSize;}
    T& get(int theIndex)const;
    void chainBubbleSort() ;
    void chainSelectionSort();
//变量
public:
    chainNode<T>* firstNode=NULL;
    chainNode<T>* lastNode=NULL;
    int listSize=0;
};
template<class T>
void Chain<T>::push_back(const T &x)
{
    chainNode<T>* newNode=new chainNode<T>(x,NULL);
    if(lastNode==NULL)
        lastNode=firstNode=newNode;
    else
    {
        lastNode->next=newNode;
        lastNode=newNode;
    }
    listSize++;
}
template<class T>
void Chain<T>::insert(int theIndex,const T&x)
{
    chainNode<T>* currentNode=firstNode;
    if(theIndex==0)
    {
        firstNode=new chainNode<T>(x,firstNode);
    }
    else
    {
        for(int i=0;i<theIndex-1;i++)
            currentNode=currentNode->next;
        currentNode->next=new chainNode<T>(x,currentNode->next);
    }    
    listSize++;
    // //更新lastNode
    // currentNode=firstNode;
    // for(int i=0;i<listSize-1;i++)
    // {   
    //     currentNode=currentNode->next;
    // }   
    // lastNode=currentNode;
    return;
}
template<class T>
int Chain<T>::findIndex(const T&x)const
{
    chainNode<T>* currentNode=firstNode;
    int index=0;
    while(currentNode!=NULL)
    {
        if(currentNode->element==x)return index;
        currentNode=currentNode->next;
        index++;
    }
    return -1;
}
template<class T>
bool Chain<T>::erase(const T& val)
{
    chainNode<T>* currentNode=firstNode;
    chainNode<T>* deleteNode;
    int index=findIndex(val);
    if(index==-1)return false;
    else if(index==0)
    {
        deleteNode=firstNode;
        firstNode=firstNode->next;
    }
    else
    {
    for(int i=0;i<index-1;i++)
        currentNode=currentNode->next;
    deleteNode=currentNode->next;
    currentNode->next=deleteNode->next;
    }

    delete deleteNode;
    listSize--;
    //更新lastNode
    currentNode=firstNode;
    for(int i=0;i<listSize-1;i++)
    {   
        currentNode=currentNode->next;
    }   
    lastNode=currentNode;
    return true;
}
template<class T>
void Chain<T>::reverse()
{
    chainNode<T>* currentNode=firstNode;
    chainNode<T>* previousNode=NULL;
    chainNode<T>* nextNode=firstNode;
    lastNode=firstNode;
    while(currentNode!=NULL)
    {
        nextNode=currentNode->next;
        currentNode->next=previousNode;
        previousNode=currentNode;
        currentNode=nextNode;
    }
    firstNode=previousNode;
}

template<class T>
void Chain<T>::output(ostream &out)const
{
    chainNode<T>* currentNode=firstNode;
    while(currentNode!=NULL)
    {
        out<<currentNode->element<<" ";
        currentNode=currentNode->next;
    }
}

template<class T>
ostream& operator<<(ostream&out,const Chain<T>x)
{
    x.output(out);return out;
}

template<class T>
void Chain<T>::outputXorSum()
{
    if(Chain<T>::size()==0)
    {
        cout<<0<<endl;
        return;
    }
    int res=0;
    int index=0;
    for(Chain<T>::iterator i=Chain<T>::begin();i!=Chain<T>::end();i++)
        res+=(*i)^(index++);
    cout<<res<<endl;
}

template<class T>
T& Chain<T>::get(int theIndex)const
{
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    return currentNode->element;
}




template<class T>
void Chain<T>::chainBubbleSort() 
{
    // 对链表元素进行冒泡排序，使链表变为有序链表
    if (listSize < 1) return;
    chainNode<T> *p = NULL;
    chainNode<T> *q = NULL;
    for (p = firstNode; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->element > q->element)
            {
                T tmp = q->element;
                q->element = p->element;
                p->element = tmp;
            }
        }
    }
}

template <class T>
void Chain<T>::chainSelectionSort()
{
    bool sort=false;//是否有序,无序为false,有序为true
    for(int i=listSize-1;i>0&&!sort;i--)
    {      
        sort=true;
        int indexofmax=0;
        // 如果一直在交换,则设为true
        for(int j=1;j<i+1;j++)
            if(get(j)>get(indexofmax))
            {
                indexofmax=j;
            }
            else sort=false;
        swap(get(i),get(indexofmax));
    }
}

template<class T>
void Chain<T>::chainInsertSort()
{
    //对某一个链表中的元素进行排序
    Chain<T> tmp;
    for(int i=0;i<listSize;i++)
    {   //判断每个元素应该在的位置
        if(!i)
        {
            tmp.insert(0,get(0));
            continue;
        }
        int index=tmp.findRightIndex(get(i),i);

        tmp.insert(index,get(i));
    }
    firstNode=tmp.firstNode;
}

template<class T>
int  Chain<T>::findRightIndex(const T&x,int range)const
{   
    int index=0;
    for(;index<range;index++)
        if (get(index)>x)break;
    return index;
}

Chain<int> meld(Chain<int>a,Chain<int>b)
{
    Chain<int>c;
    for(Chain<int>::iterator it=a.begin();it!=a.end();it++)
    {
        c.insert(0,(*it));
    }
    for(Chain<int>::iterator it=b.begin();it!=b.end();it++)
    {
        c.insert(0,(*it));
    }
    c.chainBubbleSort();
    return c;
}

int main()
{
    cin>>n>>m;
    Chain<int>a,b,c;
    while(n--)
    {
        int x;cin>>x;
        a.push_back(x);
    }
    while(m--)
    {
        int x;cin>>x;
        b.push_back(x);
    }
    a.chainBubbleSort();
    b.chainBubbleSort();
    //实现c的合并
    c=meld(a,b);
    a.outputXorSum();
    b.outputXorSum();
    c.outputXorSum();
}