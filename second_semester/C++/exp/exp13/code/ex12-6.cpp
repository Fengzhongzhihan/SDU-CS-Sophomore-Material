#include <stdexcept> // for std::out_of_range
#include"bits/stdc++.h"
template <class T>
class Array {
private:
    T* list;
    int size;
public:
    // Constructor, destructor, and other member functions would go here
    Array(int sz) : size(sz) {
        list = new T[size];
    }

    // Non-const version of the operator[]
    T& operator[](int n) {
        if (n >= 0 && n < size) // 检查下标是否越界
            return list[n];     // 返回下标为 n 的数组元素
        else
            throw std::out_of_range("invalid position");
    }

    // Const version of the operator[]
    const T& operator[](int n) const {
        if (n >= 0 && n < size) // 检查下标是否越界
            return list[n];     // 返回下标为 n 的数组元素
        else
            throw std::out_of_range("invalid position");
    }
};

int main() {
    Array<int> intArray(12);
    //use try catch
    try {
        intArray[20] = 7;
    } catch (std::out_of_range& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
