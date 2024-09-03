#pragma once
#include<iostream>
using namespace std;
#include<utility>

template<class K ,class E>
class Dictionary
{
    public:
        virtual ~Dictionary(){}
        virtual bool empty()const=0;
        virtual int size()const=0;
        virtual int find(const K&)const=0;
        virtual int erase(const K&)=0;
        virtual int insert(const pair<K,E>&)=0;
};
template <class K,class E>
class indexedBSTree:public Dictionary<K,E>
{
    public:
        virtual int get(int )const=0;
        virtual int eraseWithIndex (int) =0;
};
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
#include<queue>

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
    protected:
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
            cout<<t->element.index<<" "<<t->element.value.first<<" "<<t->element.value.second<<endl;
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
    queue<BinaryTreeNode<E>*>q;
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


template<class K,class E>
struct IdxNode
{
    int index;
    pair <K,E> value;
};



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
            sum^=p->element.value.first;
            p=p->leftChild;
        }
        else if(theIndex>p->element.index)
        {
            sum^=p->element.value.first;
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return 0;
    else 
    {
        sum^=p->element.value.first;
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
            sum^=p->element.value.first;
            p->element.index--;
            p=p->leftChild;
        }
        else if(theIndex>p->element.index)
        {
            sum^=p->element.value.first;
            theIndex=theIndex-p->element.index-1;
            p=p->rightChild;
        }
    }
    if(p==NULL)
        return 0;
    else
        sum^=p->element.value.first;
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
        IdxNode<K,E>tmp={p->element.index,s->element.value};
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
        if(theKey<p->element.value.first)
        {
            sum^=p->element.value.first;
            p=p->leftChild;
        }
        else if(theKey>p->element.value.first)
        {
            sum^=p->element.value.first;
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
    while(p!=NULL&&p->element.value.first!=theKey)
    {
        pp=p;
        if(theKey<p->element.value.first)
        {
            sum^=p->element.value.first;
            p=p->leftChild;
        }
        else 
        {
            sum^=p->element.value.first;
            p=p->rightChild;
        }
    }

    if(p==NULL)
        return 0;
    else
        sum^=theKey;

    p=root;
    while(p!=NULL&&p->element.value.first!=theKey)
    {
        if(theKey<p->element.value.first)
        {
            p->element.index--;
            p=p->leftChild;
        }
        else if(theKey>p->element.value.first)
        {
            p=p->rightChild;
        }
    }

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
        IdxNode<K,E>tmp={p->element.index,s->element.value};
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
        if(theKey<p->element.value.first)
        {
            sum^=p->element.value.first;
            p=p->leftChild;
        }
        else if(theKey>p->element.value.first)
        {
            sum^=p->element.value.first;
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
        if(theKey<pp->element.value.first)
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

    p=root;
    while(p!=NULL&&p->element.value.first!=theKey)
    {
        if(theKey<p->element.value.first)
        {
            p->element.index++;
            p=p->leftChild;
        }
        else if(theKey>p->element.value.first)
        {
            p=p->rightChild;
        }
    }

    return sum;
}

IndexedBinarySearchTree<int,int> idxTree;
int main()
{
    int m;
    scanf("%d",&m);
    int a,b;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        switch (a)
        {
            case 0:
            {
                cout<<idxTree.insert(pair<int,int>(b,b))<<endl;
                break;
            }
            case 1:
            {
                cout<<idxTree.find(b)<<endl;
                break;
            }
            case 2:
            {
                cout<<idxTree.erase(b)<<endl;
                break;
            }
            case 3:
            {
                cout<<idxTree.get(b-1)<<endl;
                break;
            }
            case 4:
            {   
                cout<<idxTree.eraseWithIndex(b-1)<<endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}