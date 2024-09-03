#include"binarySearchTree.hpp"
int main()
{
    BinarySearchTree<int,char>bsTree;
    bsTree.insert(pair<int,char>(2,'w'));
    bsTree.insert(pair<int,char>(1,'y'));
    bsTree.insert(pair<int,char>(3,'h'));
    bsTree.insert(pair<int,char>(4,'I'));
    bsTree.insert(pair<int,char>(0,'L'));
    bsTree.ascend();
    // auto k=bsTree.find(4);
    // cout<<k->first<<" "<<k->second<<endl;
    bsTree.erase(2);
    bsTree.erase(1);
    bsTree.ascend();
    return 0;
}