#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
    T element;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;
    BinaryTreeNode()
    {
        leftChild=rightChild=NULL;
    }
    BinaryTreeNode(const T& theElement)
    {
        element=theElement;
        leftChild=rightChild=NULL;
    }
    BinaryTreeNode(const T& theElement,BinaryTreeNode * theLeftChild,BinaryTreeNode* theRightChild)
    {
        element=theElement;
        leftChild=theLeftChild;
        rightChild=theRightChild;
    }
};