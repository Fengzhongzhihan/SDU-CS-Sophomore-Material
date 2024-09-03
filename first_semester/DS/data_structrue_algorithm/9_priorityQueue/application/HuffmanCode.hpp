#include"HuffmanNode.h"
#include"minHeap.hpp"
//构造huffmantree

template <class T>
LinkedBinaryTree<int>* createHuffmanTree(T weight[],int n)
{
    //初始化huffmanNode
    HuffmanNode<T>* hnode=new HuffmanNode<T>[n+1];
    LinkedBinaryTree<int> emptyTree;
    for(int i=1;i<=n;i++)
    {
        int tmp=weight[i];
        hnode[i].weight=tmp;
        hnode[i].tree=new LinkedBinaryTree<int>;
        hnode[i].tree->makeTree(i,emptyTree,emptyTree);
    }

    MinHeap<HuffmanNode<T>>heap(1);
    heap.initialize(hnode,n);

    HuffmanNode<T>w,x,y;
    LinkedBinaryTree<int>* z;
    for(int i=1;i<n;i++)
    {
        x=heap.top();heap.pop();
        y=heap.top();heap.pop();

        z=new LinkedBinaryTree<int>;
        z->makeTree(0,*x.tree,*y.tree);
        w.weight=x.weight+y.weight;
        w.tree=z;
        heap.push(w);

        delete x.tree;
        delete y.tree;
    }

    return heap.top().tree;
}
