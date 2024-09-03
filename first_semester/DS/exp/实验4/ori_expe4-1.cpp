#include<iostream>
int n,q;
using namespace std;
//结点和链表类
template <class T>
struct chainNode 
{
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
    int  findBiggerIndex(const T&x,int range)const;
    void chainInsertSort();
    int size(){return listSize;}
    T get(int theIndex)const;
//变量
protected:
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
    //更新lastNode
    currentNode=firstNode;
    for(int i=0;i<listSize-1;i++)
    {   
        currentNode=currentNode->next;
    }   
    lastNode=currentNode;
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
    if(index==-1)
        return false;
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
    int res=0;
    int index=0;
    for(Chain<T>::iterator i=Chain<T>::begin();i!=Chain<T>::end();i++)
        res+=(*i)^(index++);
    cout<<res<<endl;
}

template<class T>
T Chain<T>::get(int theIndex)const
{
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    return currentNode->element;
}

int main()
{
    cin>>n>>q;
    Chain<int>s;
    for(int i=0;i<n;i++)
        {
            int x;cin>>x;s.push_back(x);
        }
    while(q--)
    {
        int op;cin>>op;
        switch (op)
        {
            case 1:
            {
                int idx,val;cin>>idx>>val;
                s.insert(idx,val);
                break;
            }    
            case 2:
            {
                int val;cin>>val;
                if(!s.erase(val))cout<<-1<<endl;
                break;
            }
            case 3:
            {
                s.reverse();
                break;
            }
            case 4:
            {
                int val;cin>>val;
                int index=s.findIndex(val);
                if(index==-1)
                    cout<<-1<<endl;
                else cout<<index<<endl;
                break;
            }
            case 5:
            {
                s.outputXorSum();
                break; 
            }
            default:
                break;
        }
    }
    return 0;
}