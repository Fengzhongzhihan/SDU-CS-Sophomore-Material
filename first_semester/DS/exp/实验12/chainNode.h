#pragma once
template<class T>
class chainNode
{
    public:
    T element;
    chainNode<T>* next;

    chainNode(){};

    //两个构造函数
    chainNode(const T& element){this->element=element;}
    chainNode(const T& element,chainNode<T>*next)
    {
        this->element=element;
        this->next=next;
    }
};