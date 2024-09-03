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
        pair<K,E>* get(int theIndex)const;
        void eraseWithIndex (int theIndex);
        bool empty()const
        {
            return treeSize==0;
        }
        int size()const
        {
            return treeSize;
        }
        pair<K,E>* find(const K& theKey)const;
        void erase(const K& theKey);
        void insert(const pair<K,E>& thePair);
};

template <class K, class E>
inline pair<K, E>  *IndexedBinarySearchTree<K, E>::get(int theIndex)const
{
    BinaryTreeNode<IdxNode<K,E>>*p=root;
    while(p!=NULL&&p->element.index!=theIndex)
    {
        if(theIndex<p->element.index)
            p=p->leftChild;
        else if(theIndex>p->element.index)
        {
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return NULL;
    else 
        return &(p->element.pair);
}

template <class K, class E>
inline void IndexedBinarySearchTree<K, E>::eraseWithIndex(int theIndex)
{
    BinaryTreeNode<IdxNode<K,E>>*p=root,*pp=NULL;
    while(p!=NULL&&p->element.index!=theIndex)
    {
        pp=p;
        if(theIndex<p->element.index)
        {
            p->element.index--;
            p=p->leftChild;
        }
        else if(theIndex>p->element.index)
        {
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return ;

    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到左孩子的最大值
        BinaryTreeNode<IdxNode<K,E>>* s=p->leftChild,*ps=p;
        //沿着右孩子搜
        while (s->rightChild!=NULL)
        {
            ps=s;
            s=s->rightChild;
        }
        
        //先建立q结点
        BinaryTreeNode<IdxNode<K,E>>* q=new BinaryTreeNode<IdxNode<K,E>>
        (s->element,p->leftChild,p->rightChild);
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
}

template <class K, class E>
inline pair<K, E> *IndexedBinarySearchTree<K, E>::find(const K &theKey) const
{
    BinaryTreeNode<IdxNode<K,E>>*p=root;
    while(p!=NULL)
    {
        if(theKey<p->element.pair.first)
            p=p->leftChild;
        else if(theKey>p->element.pair.first)
            p=p->rightChild;
        else 
            return &p->element.pair;
    }
    return NULL;
}

template <class K, class E>
inline void IndexedBinarySearchTree<K, E>::erase(const K &theKey)
{
    BinaryTreeNode<IdxNode<K,E>> * p=root,*pp=NULL;
    while(p!=NULL&&p->element.pair.first!=theKey)
    {
        pp=p;
        if(theKey<p->element.pair.first)
        {
            p->element.index--;
            p=p->leftChild;
        }
        else 
            p=p->rightChild;
    }

    if(p==NULL)
        return;
    
    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到左孩子的最大值
        BinaryTreeNode<IdxNode<K,E>>* s=p->leftChild,*ps=p;
        //沿着右孩子搜
        while (s->rightChild!=NULL)
        {
            ps=s;
            s=s->rightChild;
        }
        
        //先建立q结点
        BinaryTreeNode<IdxNode<K,E>>* q=new BinaryTreeNode<IdxNode<K,E>>
        (s->element,p->leftChild,p->rightChild);
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
}

template <class K, class E>
inline void IndexedBinarySearchTree<K, E>::insert(const pair<K, E> &thePair)
{
    BinaryTreeNode<IdxNode<K,E>>* p=root,*pp=NULL;
    int theKey=thePair.first;

    while(p!=NULL)
    {
        pp=p;
        if(theKey<p->element.pair.first)
        {
            p->element.index++;
            p=p->leftChild;
        }
        else if(theKey>p->element.pair.first)
        {
            p=p->rightChild;
        }
        else
        {
            p->element.pair.second=thePair.second;
            return;
        }
    }

    IdxNode<K,E> tmp={0,pair<K,E>(thePair)};
    BinaryTreeNode<IdxNode<K,E>>* newNode=new BinaryTreeNode<IdxNode<K,E>> (tmp);

    if(pp!=NULL)
    {
        if(pp->leftChild==p)
            pp->leftChild=newNode;
        else if(pp->rightChild==p)
            pp->rightChild=newNode;
    }
    else
        root=newNode;

    treeSize++;
}
