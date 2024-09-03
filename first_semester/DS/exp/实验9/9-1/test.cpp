#include"linkedBinaryTree.hpp"
int main()
{
    LinkedBinaryTree<int>tree,a,b,c,d;
    b.makeTree(1,a,a);
    c.makeTree(2,a,a);
    a.makeTree(3,b,c);
    d.makeTree(3,b,c);
    tree.makeTree(4,a,d);
    tree.preOrderOutput();
    tree.inOrderOutput();
    tree.postOrderOutput();
    tree.leverOrderOutput();
    return 0;
}