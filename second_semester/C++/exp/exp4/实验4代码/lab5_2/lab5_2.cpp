#include <iostream>
#include "client.h"
#include "client.cpp"

int main() {
    std::cout << "Initial staticVar value: " << CLIENT::staticVar << std::endl;

    // 修改静态成员变量的值
    CLIENT::staticVar = 5;

    std::cout << "Modified staticVar value: " << CLIENT::staticVar << std::endl;

    return 0;
}
