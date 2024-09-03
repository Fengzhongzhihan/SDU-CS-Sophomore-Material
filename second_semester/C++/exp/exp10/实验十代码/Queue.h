#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
    LinkedList<T> list; // 使用链表来实现队列

public:
    // 构造函数
    Queue() {}

    // 检查队列是否为空
    bool isEmpty() const {
        return list.isEmpty();
    }

    // 返回队列中的元素个数
    int getSize() const {
        return list.getSize();
    }

    // 入队
    void enqueue(const T &item) {
        list.insertRear(item);
    }

    // 出队
    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty, cannot dequeue!" << endl;
            exit(1);
        }
        return list.deleteFront();
    }

    // 获取队头元素
    T& front() {
        if (isEmpty()) {
            cerr << "Queue is empty, cannot access front!" << endl;
            exit(1);
        }
        list.reset(0);
        return list.data();
    }

    // 清空队列
    void clear() {
        list.clear();
    }
};

#endif // QUEUE_H
