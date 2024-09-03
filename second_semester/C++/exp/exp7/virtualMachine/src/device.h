//
// Created by Lenovo on 2024-05-02.
//

#ifndef VIRTUALMACHINE_DEVICE_H
#define VIRTUALMACHINE_DEVICE_H
#include "bits/stdc++.h"
using namespace std;
enum OpCodes
{
    READ = 10,
    WRITE = 11,
    LOAD = 20,
    STORE = 21,
    ADD = 30,
    SUB = 31,
    MUL = 32,
    DIV = 33,
    BR = 40,
    HALT = 43
};

// 运算器ALU
class QD_ALU
{
public:
    QD_ALU(string theName) : name(theName){}
    int getACC() const {return ACC;}
    void load(int num) {
        ACC = num;
    }
    void add(int num) {
        ACC += num;
    }
    void sub(int num) {
        ACC -= num;
    }
    void mul(int num) {
        ACC *= num;
    }
    void div(int num) {
        ACC /= num;
    }
private:
    int ACC;
    string name;
};

// 存储器Memory
class QD_Memory
{
public:
    QD_Memory(int theCapacity) : capacity(theCapacity) {
        element.clear();
        element.resize(theCapacity);
    }
    vector<int> element;
private:
    int capacity;
};

// 输入设备In
class QD_In
{
public:
    QD_In(string theName) : name(theName){}
    int inputInt() {
        int x; cin >> x;
        return x;
    }
private:
    string name;
};

// 输出设备Out
class QD_Out
{
public:
    QD_Out(string theName) : name(theName){}
    void outPutInt(int num) {
        cout << num << endl;
    }
private:
    string name;
};

// 控制器CU
class QD_CU
{
public:
    QD_CU(string theName) : name(theName) {}
    void addPC() {
        PC ++;
    }
    void setPC(int num) {
        PC = num;
    }
    int getPC()const {
        return PC;
    }
private:
    int PC;
    string name;
};

#endif //VIRTUALMACHINE_DEVICE_H
