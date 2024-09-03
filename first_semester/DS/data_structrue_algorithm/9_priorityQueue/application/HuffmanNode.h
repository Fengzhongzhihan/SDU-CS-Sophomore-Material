#pragma once
#include<iostream>
using namespace std;
#include"linkedBinaryTree.hpp"

template<class T>
class HuffmanNode
{
    public:
    LinkedBinaryTree<int>* tree;
    T weight;

    operator T()const {return weight;}
};
