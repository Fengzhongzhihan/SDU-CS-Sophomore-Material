//
// Created by Lenovo on 2024-05-02.
//
#ifndef VIRTUALMACHINE_VMACHINE_H
#define VIRTUALMACHINE_VMACHINE_H

#pragma once
#include "device.h"
#include<bits/stdc++.h>
using namespace std;

class vMachine
{
public:
    vMachine(string theCUName, string theALUName, int theMemoryCapacity, string theInName, string theOutName):
    CU(theCUName), ALU(theALUName), Memory(theMemoryCapacity), In(theInName), Out(theOutName) {}
    void run(string file_name);
    void executeIns();
    QD_CU CU;
    QD_ALU ALU;
    QD_Memory Memory;
    QD_In In;
    QD_Out Out;
};

void vMachine::run(const string file_name)
{
    // 从文件中读取指令,并存到存储器中
    ifstream fin(file_name, ios::in);
    int insCode;// 指令
    int i = 0;
    do
    {
        fin >> insCode;
        Memory.element[i++] = insCode;
    } while (insCode != 4300 && !fin.eof());
    fin.close();
    // 执行指令
    executeIns();
}

void vMachine::executeIns()
{

    int insCode;
    //PC置为0
    CU.setPC(0);
    do
    {
        insCode = Memory.element[CU.getPC()];
        CU.addPC();
        int insOP = insCode / 100;
        int insNum = insCode % 100;
        switch (insOP)
        {
            case READ:
                Memory.element[insNum] = In.inputInt();
                break;
            case WRITE:
                Out.outPutInt(Memory.element[insNum]);
                break;
            case LOAD:
                ALU.load(Memory.element[insNum]);
                break;
            case STORE:
                Memory.element[insNum] = ALU.getACC();
                break;
            case ADD:
                ALU.add(Memory.element[insNum]);
                break;
            case SUB:
                ALU.sub(Memory.element[insNum]);
                break;
            case MUL:
                ALU.mul(Memory.element[insNum]);
                break;
            case DIV:
                ALU.div(Memory.element[insNum]);
                break;
            case BR:
                CU.setPC(insNum);
                break;
            case HALT:
                break;
            default:
                break;
        }
    } while (insCode != 4300);
}
#endif //VIRTUALMACHINE_VMACHINE_H
