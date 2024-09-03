//
// Created by Lenovo on 2024-03-24.
//
#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H
#include "skipNode.h"
#include "iostream"
using namespace std;
template <class K>
class skipList{
public :
    skipList(K largeKey, int maxSize, float p); // 构造函数
    bool find (const K & theKey) const ; //查找对应的元素
    int level() const ;
    skipNode<K> * search(const K & theKey) const;
    void insert(const K & theKey);
    void erase (const K & theKey);
    int size();
    bool empty();
    void output(ostream & out) const;
    int xorNum();
    int eraseMinElement();
    int eraseMaxElement();
    void reBuild();
private:
    float cutOff; // 确定层数
    int levers; //当前层数
    int dSize;//元素个数
    int maxLevel; // 最大层数
    K tailKey; //最大关键字
    skipNode<K> * headerNode; // 头节点
    skipNode<K> * tailNode; // 尾节点
    skipNode<K> ** last; // last[i]表示i层链表最后的节点
};




template<class K>
ostream & operator<<(ostream &out, const skipList<K> & x) {
    x.output(out);
    return out;
}



#endif //SKIPLIST_SKIPLIST_H
