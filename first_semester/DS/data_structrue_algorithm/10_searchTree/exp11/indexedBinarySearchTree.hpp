#include"indexedBSTree.h"
#include"linkedBinaryTree.hpp"
#include "IdxNode.h"



template<class K,class E>
class IndexedBinarySearchTree:public indexedBSTree<K,E>,public LinkedBinaryTree<IdxNode<K,E>> 
{   
    public:
        using LinkedBinaryTree<IdxNode<K,E>>::inOrderOutput;
        using LinkedBinaryTree<IdxNode<K,E>>::treeSize;
        using LinkedBinaryTree<IdxNode<K,E>>::root;
        int get(int theIndex)const;
        int eraseWithIndex (int theIndex);
        bool empty()const
        {
            return treeSize==0;
        }
        int size()const
        {
            return treeSize;
        }
        int find(const K& theKey)const;
        int erase(const K& theKey);
        int insert(const pair<K,E>& thePair);
};

template <class K, class E>
inline int IndexedBinarySearchTree<K, E>::get(int theIndex)const
{
    BinaryTreeNode<IdxNode<K,E>>*p=root;
    int sum=0;
    while(p!=NULL&&p->element.index!=theIndex)
    {
        if(theIndex<p->element.index)
        {
            sum^=p->element.pair.first;
            p=p->leftChild;
        }
        else if(theIndex>p->element.index)
        {
            sum^=p->element.pair.first;
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return 0;
    else 
    {
        sum^=p->element.pair.first;
        return sum;
    }
}

template <class K, class E>
inline int  IndexedBinarySearchTree<K, E>::eraseWithIndex(int theIndex)
{
    int sum=0;
    BinaryTreeNode<IdxNode<K,E>>*p=root,*pp=NULL;
    while(p!=NULL&&p->element.index!=theIndex)
    {
        pp=p;
        if(theIndex<p->element.index)
        {
            sum^=p->element.pair.first;
            p->element.index--;
            p=p->leftChild;
        }
        else if(theIndex>p->element.index)
        {
            sum^=p->element.pair.first;
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return 0;
    else
        sum^=p->element.pair.first;
    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到右孩子最小值
        BinaryTreeNode<IdxNode<K,E>>* s=p->rightChild,*ps=p;
        //沿着左孩子搜
        while (s->leftChild!=NULL)
        {
            ps=s;
            s->element.index--;
            s=s->leftChild;
        }
        
        //先建立q结点
        IdxNode<K,E>tmp={p->element.index,s->element.pair};
        BinaryTreeNode<IdxNode<K,E>>* q=new BinaryTreeNode<IdxNode<K,E>>
        (tmp,p->leftChild,p->rightChild);
        //给q找到位置
        if(pp==NULL)
            root=q;
        else if(p==pp->leftChild)
            pp->leftChild=q;
        else 
            pp->rightChild=q;

        //因为马上要删除p,所以不能将ps直接赋给pp,而是将q赋给pp.因为q->leftchild==s
        if(p==ps)
            pp=q;
        else 
            pp=ps;
        
        delete p;
        p=s;
    }
    //此时p最多只有一个孩子
    BinaryTreeNode<IdxNode<K,E>>*c=NULL;
    if(p->leftChild!=NULL)
        c=p->leftChild;
    else   
        c=p->rightChild;
    
    if(p==root)
        root=c;
    else if(p==pp->leftChild)
        pp->leftChild=c;
    else 
        pp->rightChild=c;
    treeSize--;
    delete p;

    return sum;
}

template <class K, class E>
inline int IndexedBinarySearchTree<K, E>::find(const K &theKey) const
{
    int sum=0;
    BinaryTreeNode<IdxNode<K,E>>*p=root;
    while(p!=NULL)
    {
        if(theKey<p->element.pair.first)
        {
            sum^=p->element.pair.first;
            p=p->leftChild;
        }
        else if(theKey>p->element.pair.first)
        {
            sum^=p->element.pair.first;
            p=p->rightChild;
        }
        else 
        {
            sum^=theKey;
            return sum;
        }
    }
    return 0;
}

template <class K, class E>
inline int IndexedBinarySearchTree<K, E>::erase(const K &theKey)
{
    int sum=0;
    BinaryTreeNode<IdxNode<K,E>> * p=root,*pp=NULL;
    while(p!=NULL&&p->element.pair.first!=theKey)
    {
        pp=p;
        if(theKey<p->element.pair.first)
        {
            sum^=p->element.pair.first;
            p->element.index--;
            p=p->leftChild;
        }
        else 
        {
            sum^=p->element.pair.first;
            p=p->rightChild;
        }
    }

    if(p==NULL)
        return 0;
    else
        sum^=theKey;

    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到右孩子最小值
        BinaryTreeNode<IdxNode<K,E>>* s=p->rightChild,*ps=p;
        //沿着左孩子搜
        while (s->leftChild!=NULL)
        {
            ps=s;
            s->element.index--;
            s=s->leftChild;
        }
        
        //先建立q结点
        IdxNode<K,E>tmp={p->element.index,s->element.pair};
        BinaryTreeNode<IdxNode<K,E>>* q=new BinaryTreeNode<IdxNode<K,E>>
        (tmp,p->leftChild,p->rightChild);
        //给q找到位置
        if(pp==NULL)
            root=q;
        else if(p==pp->leftChild)
            pp->leftChild=q;
        else 
            pp->rightChild=q;

        //因为马上要删除p,所以不能将ps直接赋给pp,而是将q赋给pp.因为q->leftchild==s
        if(p==ps)
            pp=q;
        else 
            pp=ps;
        
        delete p;
        p=s;
    }
    //此时p最多只有一个孩子
    BinaryTreeNode<IdxNode<K,E>>*c=NULL;
    if(p->leftChild!=NULL)
        c=p->leftChild;
    else   
        c=p->rightChild;
    
    if(p==root)
        root=c;
    else if(p==pp->leftChild)
        pp->leftChild=c;
    else 
        pp->rightChild=c;
    treeSize--;
    delete p;

    return sum;
}

template <class K, class E>
inline int  IndexedBinarySearchTree<K, E>::insert(const pair<K, E> &thePair)
{
    int sum=0;
    BinaryTreeNode<IdxNode<K,E>>* p=root,*pp=NULL;
    int theKey=thePair.first;

    while(p!=NULL)
    {
        pp=p;
        if(theKey<p->element.pair.first)
        {
            sum^=p->element.pair.first;
            p->element.index++;
            p=p->leftChild;
        }
        else if(theKey>p->element.pair.first)
        {
            sum^=p->element.pair.first;
            p=p->rightChild;
        }
        else
        {
            return 0;
        }
    }

    IdxNode<K,E> tmp={0,pair<K,E>(thePair)};
    BinaryTreeNode<IdxNode<K,E>>* newNode=new BinaryTreeNode<IdxNode<K,E>> (tmp);

   if(root!=NULL)
    {
        if(theKey<pp->element.pair.first)
        {
            pp->leftChild=newNode;
        }
        else 
        {
            pp->rightChild=newNode;
        }
    }
    else 
    {
        root=newNode;
    }
    treeSize++;

    return sum;
}
