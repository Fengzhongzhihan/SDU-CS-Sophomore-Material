#include "bits/stdc++.h"
using namespace std;

void transposeMatrix(int **matrix) {
    int temp;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    // 开辟每一行的空间
    int **matrix = new int*[3];
    //对于每一行开辟新的空间
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
    }

    //赋值
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = count++;
        }
    }

    // 打印原始矩阵
    cout << "Original Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << std::endl;
    }

    // 转置
    transposeMatrix(matrix);

    // 打印转置后的矩阵
    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << std::endl;
    }

    // 释放内存空间
    for (int i = 0; i < 3; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
