#include"linkedBinaryTree.hpp"
#include"bsTree.h"

template<class K,class E>
class BinarySearchTree:public LinkedBinaryTree<pair<K,E>>,
                        public BSTree<K,E>
{
    public:
        using LinkedBinaryTree<pair<K,E>>::inOrderOutput;
        using LinkedBinaryTree<pair<K,E>>::treeSize;
        using LinkedBinaryTree<pair<K,E>>::root;
        void ascend()
        {
            inOrderOutput();
        }
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
        void BSSort(BinaryTreeNode<pair<K,E>> *t);
};

template <class K, class E>
inline pair<K, E> *BinarySearchTree<K, E>::find(const K &theKey) const
{
    
    BinaryTreeNode<pair<K,E>>*p=root;
    while(p!=NULL)
    {
        if(theKey<p->element.first)
            p=p->leftChild;
        else if(theKey>p->element.first)
            p=p->rightChild;
        else 
            return &p->element;
    }
    return NULL;
    
}

template <class K, class E>
inline void BinarySearchTree<K, E>::insert(const pair<K, E> &thePair)
{
    BinaryTreeNode<pair<K,E>>* p=root,*pp=NULL;
    int theKey=thePair.first;
    while(p!=NULL)
    {
        pp=p;
        if(theKey<p->element.first)
        {
            p=p->leftChild;
        }
        else if(theKey>p->element.first)
        {
            p=p->rightChild;
        }
        else 
        {
            p->element.second=thePair.second;
            return;
        }
    }

    BinaryTreeNode<pair<K,E>>* newNode=new BinaryTreeNode<pair<K,E>>(thePair);
    if(root!=NULL)
    {
        if(theKey<pp->element.first)
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
}

template <class K, class E>
inline void BinarySearchTree<K, E>::erase(const K &theKey)
{
    BinaryTreeNode<pair<K,E>>* p=root,*pp=NULL;
    while(p!=NULL&&theKey!=p->element.first)
    {
        pp=p;
        if(theKey<p->element.first)
        {
            p=p->leftChild;
        }
        else if(theKey>p->element.first)
        {
            p=p->rightChild;
        }
    }
    if(p==NULL)
    {
        return ;
    }
    
    //两个孩子都不为空
    if(p->leftChild!=NULL&&p->rightChild!=NULL)
    {
        //找到左孩子的最大值
        BinaryTreeNode<pair<K,E>>* s=p->leftChild,*ps=p;
        //沿着右孩子搜
        while (s->rightChild!=NULL)
        {
            ps=s;
            s=s->rightChild;
        }
        
        //先建立q结点
        BinaryTreeNode<pair<K,E>>* q=new BinaryTreeNode<pair<K,E>>
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
    BinaryTreeNode<pair<K,E>>*c=NULL;
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