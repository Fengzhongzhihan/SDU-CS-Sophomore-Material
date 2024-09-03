#include<iostream>
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
using namespace std;
const int N=100010;
int preOrder[N];
int inOrder[N];
int pos[N];

BinaryTreeNode<int>* buildTree(int pl,int pr,int il,int ir)
{
    if(pl>pr||il>ir)
        return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preOrder[pl]);
    //找出划分的区域
    int k=pos[preOrder[pl]]-il;
    root->leftChild=buildTree(pl+1,pl+k,il,il+k-1);
    root->rightChild=buildTree(pl+k+1,pr,il+k+1,ir);
    return root;
}

void postOrderOutput(BinaryTreeNode<int>*t)
{
    if(t!=NULL)
    {
        postOrderOutput(t->leftChild);
        postOrderOutput(t->rightChild);
        cout<<t->element<<" ";
    }
}

int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>preOrder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inOrder[i];
    }
    for(int i=0;i<n;i++)
    {
        pos[inOrder[i]]=i;
    }

    BinaryTreeNode<int>* root=buildTree(0,n-1,0,n-1);

    postOrderOutput(root);
}
