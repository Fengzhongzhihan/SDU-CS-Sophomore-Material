#include"HuffmanCode.hpp"
int main()
{
    int weight[7]={0,6,2,3,3,4,9};
    LinkedBinaryTree<int>* tree=createHuffmanTree(weight,6);
    tree->inOrderOutput();
    return 0;
}