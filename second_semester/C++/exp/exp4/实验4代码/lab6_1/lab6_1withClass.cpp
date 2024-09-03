#include <iostream>

class Matrix {
private:
    int data[3][3];
public:
    // 构造函数
    Matrix(int initData[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = initData[i][j];
            }
        }
    }

    // 矩阵转置函数
    void transpose() {
        int temp;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                // 交换元素
                temp = data[i][j];
                data[i][j] = data[j][i];
                data[j][i] = temp;
            }
        }
    }

    // 打印矩阵函数
    void print() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int input[3][3];

    // 从标准输入获取矩阵数据
    std::cout << "Enter the elements of the 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> input[i][j];
        }
    }

    // 创建矩阵对象
    Matrix matrix(input);

    // 转置矩阵
    matrix.transpose();

    // 打印转置后的矩阵
    std::cout << "Transposed Matrix:" << std::endl;
    matrix.print();

    return 0;
}
