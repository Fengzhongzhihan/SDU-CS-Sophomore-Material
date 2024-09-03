#pragma once
#pragma once
#include<iostream>
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
#pragma once
#include<iostream>
using namespace std;

template<class T>
class Queue
{
public:
    virtual ~Queue(){}
    virtual bool empty()const =0;
    virtual int size()const =0;
    virtual T front()=0;
    virtual T back()=0;
    virtual void pop()=0;
    virtual void push(const T& theElement)=0;
};



template<class T>
class ArrayQueue :public Queue<T>
{
public:
    ArrayQueue(int theCapacity=10);
    ~ArrayQueue(){delete[] queue;}
    bool empty() const{return queueBack==queueFront;}
    bool full() const {return (queueBack+1)%arrayLength==queueFront;}
    int size()const {return (queueBack-queueFront+arrayLength)%arrayLength;}
    T front()
    {
        if(empty())
        {
            cout<<"empty"<<endl;
            return 0;
        }
        return queue[(queueFront+1)%arrayLength];
    }
    T back()
    {
        if(empty())
        {
            cout<<"empty"<<endl;
            return 0;
        }
        return queue[queueBack];
    }
    void pop()
    {
        if(empty())
        {
            cout<<"empty"<<endl;
            return;
        }
        queueFront=(queueFront+1)%arrayLength;
        queue[queueFront].~T();
    }
    void push(const T& theElement);
    void changeQueueLength();
    
private:
    int queueFront;
    int queueBack;
    int arrayLength;
    T *queue;
};

template <class T>
inline ArrayQueue<T>::ArrayQueue(int theCapacity)
{
    if(theCapacity<1)
    {
            cout<<"capacity must >0"<<endl;
            return;
    }   
    arrayLength=theCapacity;
    queue=new T[theCapacity];
    queueFront=queueBack=0;
}

template <class T>
inline void ArrayQueue<T>::push(const T &theElement)
{
    //扩容
    if(size()==arrayLength-1)
    {
        changeQueueLength();
    }
    queueBack=(queueBack+1)%arrayLength;
    queue[queueBack]=theElement;
}

template <class T>
inline void ArrayQueue<T>::changeQueueLength()
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
    arrayLength=arrayLength*2;
    delete[]queue;
    queue=newQueue;
}

#include<stack>

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

        void makeTree(const E& theElement,LinkedBinaryTree<E>&a,LinkedBinaryTree<E>&b);

    private:
        BinaryTreeNode<E>* root;
        int treeSize;
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
        static int height(BinaryTreeNode<E>*t)
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
        
};


template<class E>
void (*LinkedBinaryTree<E>::visit)(BinaryTreeNode<E>*);

template<class E>
BinaryTreeNode<E>* root;

template <class E>
inline void LinkedBinaryTree<E>::createTreeByLevel()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    ArrayQueue<BinaryTreeNode<E>*>q;
    
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
//根左右
template <class E>
inline void LinkedBinaryTree<E>::preOrder(BinaryTreeNode<E> *t)
{   //非递归写法
    // stack<BinaryTreeNode<E>*>stk;
    // if(t==NULL)
    //     return;

    // //只有当栈为空且t为空的时候才停止
    // while(!stk.empty()||t)
    // {   //遍历左子树
    //     while(t)
    //     {
    //         stk.push(t);
    //         LinkedBinaryTree::visit(t);
    //         t=t->leftChild;
    //     }
    //     t=stk.top();
    //     stk.pop();
    //     t=t->rightChild;
    // }
    //递归写法
    if(t!=NULL)
    {
        LinkedBinaryTree::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}
//左根右
template <class E>
inline void LinkedBinaryTree<E>::inOrder(BinaryTreeNode<E>*t)
{   
    stack<BinaryTreeNode<E>*>stk;
    if(t==NULL)
        return;

    //只有当栈为空且t为空的时候才停止
    while(!stk.empty()||t)
    {   //遍历左子树
        while(t)
        {
            stk.push(t);
            t=t->leftChild;
        }
        t=stk.top();
        stk.pop();
        //出栈就访问节点
        LinkedBinaryTree::visit(t);
        t=t->rightChild;
    }
}

template <class E>
inline void LinkedBinaryTree<E>::postOrder(BinaryTreeNode<E>*t)
{   
    stack<BinaryTreeNode<E>*>stk;
    if(t==NULL)
        return;

    BinaryTreeNode<E>* pre=NULL;
    BinaryTreeNode<E>* cur=t;
    while(cur)
    {
        stk.push(cur);
        cur=cur->leftChild;
    }
    //对于根结点的每个左孩子而言
    while(!stk.empty())
    {
        cur=stk.top();
        //如果右孩子为空,或者刚才被访问过
        if(cur->rightChild==NULL||cur->rightChild==pre)
        {
            LinkedBinaryTree::visit(cur);
            pre=cur;
            stk.pop();
        }
        else
        {
            cur=cur->rightChild;
            while(cur)
            {
                stk.push(cur);
                cur=cur->leftChild;
            }
        }
    }
}

template <class E>
inline void LinkedBinaryTree<E>::leverOrder(BinaryTreeNode<E>*t)
{   
    ArrayQueue<BinaryTreeNode<E>*> q;
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
    BinaryTreeNode<E>* tmp=b.root;
    root=new BinaryTreeNode<E> (theElement,a.root,tmp);
    treeSize=a.treeSize+b.treeSize+1;

    a.root=b.root=NULL;
    a.treeSize=b.treeSize=0;
}

struct lr
{
    int left,right;
};

int n;
int main()
{
    cin>>n;
    LinkedBinaryTree<int>tree[n+1];
    LinkedBinaryTree<int> a;
    int height[n+1];
    int size[n+1];
    struct lr st[n+1];

    //先存下left和right
    for(int i=1;i<=n;i++)
    {
        int left,right;
        cin>>left>>right;
        st[i].left=left;
        st[i].right=right;
    }
    //对于每一颗树,进行合并
    for(int i=n;i>=1;i--)
    {
        if(st[i].left!=-1&&st[i].right!=-1)
        {
            tree[i].makeTree(i,tree[st[i].left],tree[st[i].right]);
        }
        else if(st[i].left==-1&&st[i].right!=-1)
        {
            tree[i].makeTree(i,a,tree[st[i].right]);
        }
        else if(st[i].left!=-1&&st[i].right==-1)
        {
            tree[i].makeTree(i,tree[st[i].left],a);
        }
        else
        {
            tree[i].makeTree(i,a,a);
        }
        height[i]=tree[i].height();
        size[i]=tree[i].size();
    }

    //输出结果
    tree[1].preOrderOutput();
    tree[1].inOrderOutput();
    tree[1].postOrderOutput();
    tree[1].leverOrderOutput();
    for(int i=1;i<=n;i++)
    {
        cout<<size[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<height[i]<<" ";
    }
}