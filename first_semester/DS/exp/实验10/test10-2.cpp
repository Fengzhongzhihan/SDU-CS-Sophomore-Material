#pragma once
#include<iostream>
using namespace std;
#pragma once
#include<iostream>
#include<map>
using namespace std;
template<class T>
struct BinaryTreeNode
{
    T element;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;
    BinaryTreeNode()
    {
        leftChild=rightChild=NULL;
    }
    BinaryTreeNode(const T& theElement)
    {
        element=theElement;
        leftChild=rightChild=NULL;
    }
    BinaryTreeNode(const T& theElement,BinaryTreeNode * theLeftChild,BinaryTreeNode* theRightChild)
    {
        element=theElement;
        leftChild=theLeftChild;
        rightChild=theRightChild;
    }
};
#pragma once
#include<iostream>
using namespace std;

template<class T>
class BinaryTree
{
    public:
        virtual ~BinaryTree(){}
        virtual bool empty()const =0;
        virtual int size()const =0;
        virtual void preOrder(void (*) (T*))=0;
        virtual void inOrder(void(*)(T*))=0;
        virtual void postOrder(void(*)(T*))=0;
        virtual void leverOrder(void(*)(T*))=0;
};
#include"queue"

template<class E>
class LinkedBinaryTree:public BinaryTree<BinaryTreeNode<E>>
{
    public:
        LinkedBinaryTree()
        {
            root=NULL;
            treeSize=0;
            visit=output;
        }
        void makeTree(const E& theElement,LinkedBinaryTree<E>&a,LinkedBinaryTree<E>&b);
        ~LinkedBinaryTree()
        {
            erase();
        }
        void createTreeByLevel();
        bool empty() const
        {
            return treeSize==0;
        }
        int size()const
        {
            return treeSize;
        }
        //遍历函数,传入visit函数指针
        void preOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;preOrder(root);
        }
        void inOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;inOrder(root);
        }
        void postOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;postOrder(root);
        }
        void leverOrder(void (*theVisit) (BinaryTreeNode<E>*))
        {
            visit=theVisit;leverOrder(root);
        }
        void preOrderOutput()
        {
            preOrder(output);
            cout<<endl;
        }
        void inOrderOutput()
        {
            inOrder(output);
            cout<<endl;
        }
        void postOrderOutput()
        {
            postOrder(output);
            cout<<endl;
        }
        void leverOrderOutput()
        {
            leverOrder(output);
            cout<<endl;
        }
        void erase()
        {
            postOrder(dispose);
            root=NULL;
            treeSize=0;
        }
        int height() const
        {
            return height(root);
        }
        int height(BinaryTreeNode<E>*t)
        {
            if(t==NULL)
                return 0;
            int hl=height(t->leftChild);
            int hr=height(t->rightChild);
            if(hl>hr)
                return ++hl;
            else 
                return ++hr;
        }    

    public:
        BinaryTreeNode<E>* root;
        int treeSize;
        int index=1;
        int ans=0;
        //定义函数指针,规定如何访问元素
        static void (*visit)(BinaryTreeNode<E>*);
        static void preOrder(BinaryTreeNode<E>*t);
        static void inOrder(BinaryTreeNode<E>*t);
        static void postOrder(BinaryTreeNode<E>*t);
        static void leverOrder(BinaryTreeNode<E>*t);
        static void output(BinaryTreeNode<E>*t)
        {
            cout<<t->element<<" ";
        }
        static void dispose(BinaryTreeNode<E>*t)
        {
            delete t;
        }

 
};


template<class E>
void (*LinkedBinaryTree<E>::visit)(BinaryTreeNode<E>*);

template <class E>
inline void LinkedBinaryTree<E>::createTreeByLevel()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    queue<BinaryTreeNode<E>*>q;
    
    int index=0;
    root=new BinaryTreeNode<E> (a[index++]);
    q.push(root);
    BinaryTreeNode<E>* p=NULL;
    while(!q.empty()&&index<n)
    {
        p=q.front();
        q.pop();
        //如果不空就创建一个节点
        BinaryTreeNode<E>* leftNode=new BinaryTreeNode<E>(a[index++]);
        p->leftChild=leftNode;
        q.push(leftNode);
        treeSize++;

        if(index<n)
        {
            BinaryTreeNode<E>* rightNode=new BinaryTreeNode<E>(a[index++]);
            p->rightChild=rightNode;
            q.push(rightNode);
            treeSize++;
        }
    }
}

template <class E>
inline void LinkedBinaryTree<E>::preOrder(BinaryTreeNode<E> *t)
{   
    if(t!=NULL)
    {
        LinkedBinaryTree::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template <class E>
inline void LinkedBinaryTree<E>::inOrder(BinaryTreeNode<E>*t)
{   
    if(t!=NULL)
    {
        inOrder(t->leftChild);
        LinkedBinaryTree<E>::visit(t);
        inOrder(t->rightChild);
    }
}

template <class E>
inline void LinkedBinaryTree<E>::postOrder(BinaryTreeNode<E>*t)
{   
    if(t!=NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        LinkedBinaryTree<E>::visit(t);
    }
}

template <class E>
inline void LinkedBinaryTree<E>::leverOrder(BinaryTreeNode<E>*t)
{   
    queue<BinaryTreeNode<E>*> q;
    while(t!=NULL)
    {
        visit(t);

        if(t->leftChild!=NULL)
            q.push(t->leftChild);
        if(t->rightChild!=NULL)
            q.push(t->rightChild);
        
        if(!q.empty())
        {
            t=q.front();
            q.pop();
        }
        else
            return;
    }
}

template <class E>
inline void LinkedBinaryTree<E>::makeTree(const E &theElement, LinkedBinaryTree<E> &a, LinkedBinaryTree<E> &b)
{
    root=new BinaryTreeNode<E> (theElement,a.root,b.root);
    treeSize=a.treeSize+b.treeSize+1;

    a.root=b.root=NULL;
    a.treeSize=b.treeSize=0;
}


#pragma once
#pragma once
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
        arrayLength=arraySize;
        heap=new T[arrayLength];
        heapSize=0;
    }
    ~MinHeap()
    {
        if(heap!=NULL)
        delete[] heap;
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
        if(heap!=NULL)
            delete []heap;
        heap=NULL;
        arrayLength=heapSize=0;
    }

private:
    T *heap;
    int arrayLength;
    int heapSize;
};

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
    T* tmp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, tmp);
    delete[] a;
    a = tmp;
}

//时间复杂度,高度log2n
template <class T>
inline void MinHeap<T>::push(const T &theElement)
{
    //数组满,扩大数组
    if(heapSize==arrayLength-1)
    {
        changeLength1D(heap,arrayLength,arrayLength*2);
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
    heapSize=theHeapSize;//5
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
class HuffmanNode
{
    public:
    LinkedBinaryTree<int>* tree;
    T weight;

    operator T()const {return weight;}
};


//构造huffmantree

template <class T>
LinkedBinaryTree<int>* createHuffmanTree(T weight[],int n)
{
    MinHeap<HuffmanNode<int>>heap(1);
    HuffmanNode<T>* hnode=new HuffmanNode<T>[n+1];
    LinkedBinaryTree<int> emptyTree;
    for(int i=1;i<=n;i++)
    {
        hnode[i].weight=weight[i];
        hnode[i].tree=new LinkedBinaryTree<int>;
        hnode[i].tree->makeTree(i,emptyTree,emptyTree);
    }
    heap.initialize(hnode,n);

    HuffmanNode<T> newNode,x,y;
    LinkedBinaryTree<T>* z;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        x=heap.top();heap.pop();
        y=heap.top();heap.pop();

        int w=x.weight+y.weight;
        z=new LinkedBinaryTree<int>;
        z->makeTree(0,*x.tree,*y.tree);
        newNode.weight=w;
        newNode.tree=z;
        ans+=w;
        heap.push(newNode);
        
        delete x.tree;
        delete y.tree;
    }

    cout<<ans<<endl;
    return heap.top().tree;
}

#include<cstring>
const int N=1e6+10;
bool st[N]={false};
int sl[N]={0};
int ans=0;

// template<class E>
// static void addLength(BinaryTreeNode<E>*t,int h=0)
// {
//     if(t!=NULL)
//     {   
//         if(t->leftChild==NULL&&t->rightChild==NULL)
//         {
//             ans+=weight[t->element]*(h++);
//         }
//         addLength(t->leftChild,h+1);
//         addLength(t->rightChild,h+1);
//     }
// }
#include<map>
int main()
{
    char s[N];
    scanf("%s",s);

    int count=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(st[s[i]]==false)
            count++;
        st[s[i]]=true;
        sl[s[i]]++;
    }
    int *weight=new int [count+1];
    memset(st,false,sizeof(st));
    int index=1;
    for(int i=0;i<len;i++)
    {
        if(st[s[i]]==false)
            weight[index++]=sl[s[i]];
        st[s[i]]=true;
    }
    // int len=s.length();
    // for(int i=0;i<len;i++)
    // {
    //     if(mp.find(s[i])==mp.end())
    //     {
    //         mp[s[i]]=1;
    //     }
    //     else
    //     {
    //         mp[s[i]]++;
    //     }
    // }

    // int index=1;
    // for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
    // {
    //     weight[index++]=it->second;
    // }
    createHuffmanTree(weight,count);
}