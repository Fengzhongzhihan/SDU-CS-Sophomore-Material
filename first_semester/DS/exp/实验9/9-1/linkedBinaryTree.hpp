#pragma once
#include"binaryTreeNode.h"
#include"binaryTree.h"
#include"arrayQueue.hpp"
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
            //弹出元素
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
