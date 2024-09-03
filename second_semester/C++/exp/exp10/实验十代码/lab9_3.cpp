#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue<int> q;

    // 插入5个整数
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // 依次取出并显示
    cout << "Elements dequeued from the queue: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
