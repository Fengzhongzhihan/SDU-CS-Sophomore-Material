#include<iostream>
#include"binaryTreeNode.h"
using namespace std;
const int N=100010;
int preOrder[N];
int inOrder[N];
int pos[N];

//根据前序和中序建立二叉树
// 举例 : 前序 1 2 4 5 3 6 7 中序 4 2 5 1 6 3 7 
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
    //保存每个结点在中序中的位置  4 2 1 3 5 则pos[1]=2
    for(int i=0;i<n;i++)
    {
        pos[inOrder[i]]=i;
    }

    BinaryTreeNode<int>* root=buildTree(0,n-1,0,n-1);

    postOrderOutput(root);
}
