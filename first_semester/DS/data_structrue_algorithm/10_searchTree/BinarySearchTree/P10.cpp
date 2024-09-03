#include"binarySearchTree.hpp"
const int N=100010;
int n;
int a[N];
int index=0;

template <class K, class E>
inline void BinarySearchTree<K, E>::BSSort(BinaryTreeNode<pair<K,E>> *t)
{
    if(t!=NULL)
    {
        BSSort(t->leftChild);
        a[index++]=t->element.first;
        BSSort(t->rightChild);
    }
}

int main()
{
    BinarySearchTree<int,int>bsTree;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        bsTree.insert(pair<int,int>(a[i],a[i]));    
    }
    bsTree.BSSort(bsTree.root);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}