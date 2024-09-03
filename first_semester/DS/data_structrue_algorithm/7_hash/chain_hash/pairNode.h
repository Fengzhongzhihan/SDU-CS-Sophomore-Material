#pragma once
#include<iostream>
using namespace std;
template<class K,class E>
struct PairNode
{
    pair<K,E> element;
    PairNode<K,E>*next;
    PairNode(const pair<K,E>thePair,PairNode<K,E>*nextNode)
    {
        element=thePair;
        next=nextNode;
    }
    PairNode(){}
};