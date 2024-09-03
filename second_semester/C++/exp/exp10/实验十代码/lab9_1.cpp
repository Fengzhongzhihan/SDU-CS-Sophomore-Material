#include <iostream>
#include "Node.h"

int main() {
    // 创建一些节点
    Node<int> node1(1); // 第一个节点，数据为1
    Node<int> node2(2); // 第二个节点，数据为2
    Node<int> node3(3); // 第三个节点，数据为3

    // 将节点插入到链表中
    node1.insertAfter(&node2); // 在node1之后插入node2
    node2.insertAfter(&node3); // 在node2之后插入node3

    // 遍历链表并打印每个节点的数据
    Node<int> *current = &node1;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->nextNode();
    }
    std::cout << std::endl;

    // 删除node1之后的节点（即删除node2）
    Node<int> *deletedNode = node1.deleteAfter();
    std::cout << "Deleted node's data: " << deletedNode->data << std::endl;
    // 再次遍历链表并打印每个节点的数据
    current = &node1;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->nextNode();
    }
    std::cout << std::endl;

    return 0;
}
