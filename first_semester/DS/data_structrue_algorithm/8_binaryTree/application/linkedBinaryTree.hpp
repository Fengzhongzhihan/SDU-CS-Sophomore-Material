#pragma once
#include"binaryTreeNode.h"
#include"binaryTree.h"
#include"arrayQueue.hpp"
#include"booster.h"

template<class E>
class LinkedBinaryTree:public BinaryTree<BinaryTreeNode<E>>
{
    public:
        LinkedBinaryTree()
        {
            root=NULL;
            treeSize=0;
            visit=output;
            tolerance=0;
        }
        ~LinkedBinaryTree()
        {
            erase();
        }
        void createTreeByLevel();
        void createTreeBoosterByLevel();
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
        void postOrderPlaceBoosters()
        {
            postOrder(placeBoosters);
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
        static void setTolerance()
        {
            cin>>tolerance;
        }
    private:
        static int tolerance;
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
        static void placeBoosters(BinaryTreeNode<E>*x);    
};


template<class E>
void (*LinkedBinaryTree<E>::visit)(BinaryTreeNode<E>*);

template<class E>

int LinkedBinaryTree<E>::tolerance;

template <class E>
inline void LinkedBinaryTree<E>::createTreeByLevel()
{
    int n;cin>>n;
    E a[n];
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
inline void LinkedBinaryTree<E>::createTreeBoosterByLevel()
{
    int n;cin>>n;
    E a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].degradeFromParent;
    }
    
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

template <class E>
inline void LinkedBinaryTree<E>::placeBoosters(BinaryTreeNode<E> *x)
{
    x->element.degradeToLeaf=0;
    BinaryTreeNode<booster>* y=x->leftChild;
    //左子树找
    if(y!=NULL)
    {
        int degradation=y->element.degradeToLeaf+y->element.degradeFromParent;
        if(degradation>tolerance) //超过容忍值, 放置对应的放大器
        {
            y->element.boosterHere=true;
            x->element.degradeToLeaf=y->element.degradeFromParent;
        }
        else //没有超过容忍值, 不放置放大器
        {
            x->element.degradeToLeaf=degradation;
        }
    }

    y=x->rightChild;
    if(y!=NULL)
    {
        int degradation=y->element.degradeToLeaf+y->element.degradeFromParent;
        if(degradation>tolerance)
        {
            y->element.boosterHere=true;
            degradation=y->element.degradeFromParent;
        }
        x->element.degradeToLeaf=max(x->element.degradeToLeaf,degradation);
    }
}
