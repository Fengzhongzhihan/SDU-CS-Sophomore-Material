#pragma once
#include"linkedBinaryTree.hpp"
#include"maxPriorityQueue.h"
template<class T>
class MaxHblt:public LinkedBinaryTree<pair<int,T>>
{
    public:
        using LinkedBinaryTree<pair<int,T>>::treeSize;
        using LinkedBinaryTree<pair<int,T>>::root;
        using LinkedBinaryTree<pair<int,T>>::postOrder;
        using LinkedBinaryTree<pair<int,T>>::inOrder;
        using LinkedBinaryTree<pair<int,T>>::visit;


        bool empty()
        {
            return treeSize ==0;
        }
        int size()
        {
            return treeSize;
        }
        const T& top()
        {
            if(treeSize==0)
                return 0;
            return root->element.second;
        }
        void pop()
        {
            if(treeSize==0)
                return;
            BinaryTreeNode<pair<int,T>> * left=root->leftChild;
            BinaryTreeNode<pair<int,T>> * right=root->rightChild;
            delete root;
            meld(left,right);
            root=left;
            treeSize--;
        }
        void push(const T& theElement)
        {
            BinaryTreeNode<pair<int,T>> * newNode=new BinaryTreeNode<pair<int,T>>(pair<int,T>(1,theElement));
            meld(root,newNode);
            treeSize++;
        }
        void meld(MaxHblt<T>& theHblt)
        {
            meld(root,theHblt.root);
            treeSize+=theHblt.treeSize;
            theHblt.root=NULL;
            theHblt.treeSize=0;
        }
        void initilize(T* theHeap,int theSize);
        void postOrderOutput()
        {
            postOrder(hbltOutput);
            cout<<endl;
        }
        void inOrderOutput()
        {
            inOrder(hbltOutput);
            cout<<endl;
        }
    private:
        void meld(BinaryTreeNode<pair<int,T>>*&x,BinaryTreeNode<pair<int,T>>*&y);
        static void hbltOutput(BinaryTreeNode<pair<int,T>>* t)
        {
             cout<<"s:"<<t->element.first<<" "<<"value:"<<t->element.second<<" "<<endl;
        }
};

template <class T>
inline void MaxHblt<T>::meld(BinaryTreeNode<pair<int, T>> *&x, BinaryTreeNode<pair<int, T>> *&y)
{
    if(y==NULL)
        return;
    if(x==NULL)
    {
        x=y;
        return;
    }

    if(x->element.second<y->element.second)
        swap(x,y);
    
    meld(x->rightChild,y);

    //左子树为空或者右子树值比较大的时候需要更换
    if(x->leftChild==NULL)
    {
        x->leftChild=x->rightChild;
        x->rightChild=NULL;
        x->element.first=1;
    }
    else
    {
        if(x->leftChild->element.first<x->rightChild->element.first)
            swap(x->leftChild,x->rightChild);
        x->element.first=x->rightChild->element.first+1;
    }
}

template <class T>
inline void MaxHblt<T>::initilize(T *theHeap, int theSize)
{
    queue<BinaryTreeNode< pair<int,T> >*>q;
    //依此放入待排列的元素
    for(int i=0;i<theSize;i++)
    {
        q.push(new BinaryTreeNode<pair<int,T>>(pair<int,T>(1,theHeap[i])));
    }

    //进行排列,共需要theSize-1次,因为每次都相当于少了一个元素,最后还要剩下一个元素
    for(int i=0;i<theSize-1;i++)
    {
        BinaryTreeNode<pair<int,T>>* a=q.front();
        q.pop();
        BinaryTreeNode<pair<int,T>>* b=q.front();
        q.pop();
        meld(a,b);
        q.push(a);
    }

    if(theSize>0)
        root=q.front();
    treeSize=theSize;
}
