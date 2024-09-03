//
// Created by Lenovo on 2024-03-24.
//

#ifndef SKIPLIST_SKIPNODE_H
#define SKIPLIST_SKIPNODE_H
#include <iostream>
using namespace  std;

template <class K>
struct skipNode{

    K element;
    // 指针数组, 存放不同级别链表的指针
    skipNode<K>** next;
    // 初始化, size为链表的级数 + 1 (纵轴)
    skipNode(const K & theKey, int size) : element(theKey) {
        next = new skipNode<K> * [size];
    }

};
#endif //SKIPLIST_SKIPNODE_H
