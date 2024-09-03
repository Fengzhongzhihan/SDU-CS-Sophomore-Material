#include <iostream>
#include "ArrayQueue.h"

void runTests()
{
    ArrayQueue<int> q(1);
    q.push(1);
    std::cout << "front:" << q.front() << " back:" << q.back() << std::endl;
    std::cout << "size:" << q.size() << std::endl;
    q.push(2);
    std::cout << "front:" << q.front() << " back:" << q.back() << std::endl;
    std::cout << "size:" << q.size() << std::endl;
    q.push(3);
    std::cout << "front:" << q.front() << " back:" << q.back() << std::endl;
    std::cout << "size:" << q.size() << std::endl;
    q.pop();
    std::cout << "front:" << q.front() << " back:" << q.back() << std::endl;
    std::cout << "size:" << q.size() << std::endl;
    q.push(4);
    std::cout << "front:" << q.front() << " back:" << q.back() << std::endl;
    std::cout << "size:" << q.size() << std::endl;
    q.push(5);
    std::cout << "front:" << q.front() << " back:" << q.back() << std::endl;
    std::cout << "size:" << q.size() << std::endl;
}

int main()
{
    runTests();
    return 0;
}