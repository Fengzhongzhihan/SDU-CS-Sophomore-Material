#pragma once
#include<iostream>
using namespace std;
template<class T>
class BinaryTree
{
    public:
        virtual ~BinaryTree(){}
        virtual bool empty()const =0;
        virtual int size()const =0;
        virtual void preOrder(void (*) (T*))=0;
        virtual void inOrder(void(*)(T*))=0;
        virtual void postOrder(void(*)(T*))=0;
        virtual void leverOrder(void(*)(T*))=0;
};