//
// Created by Lenovo on 2024-03-24.
//
#include "skipList.h"
#include "math.h"
template < class K>
// 用maxSize代替公式中的N
skipList<K> ::skipList(K largeKey, int maxSize, float p) {
    cutOff = p * RAND_MAX;
    // Lever = log1/p N (向上取整) - 1
    maxLevel = (int) ceil((logf(float(maxSize)) / logf(1 / p))) - 1;
    levers = 0;
    dSize = 0;
    tailKey = largeKey;
    // 头结点和尾结点关键字都初始化为最大值
    headerNode = new skipNode<K> (tailKey, maxLevel + 1);
    tailNode = new skipNode<K> (tailKey, 0);
    last = new skipNode<K> * [maxLevel + 1];
    // header points to tail at all levels as lists are empty

    for (int i = 0; i <= maxLevel; i++)
        headerNode->next[i] = tailNode;
}

template<class K>
bool skipList<K>::find(const K &theKey) const {
    if (theKey >= tailKey) {
        return false;
    }
    // 关键字 < key的最大的位置
    skipNode<K> * beforeNode = headerNode;
    // 从最高层开始搜索
    for (int i = levers; i >= 0; i--) {
        while (beforeNode->next[i]->element < theKey) {
            beforeNode = beforeNode->next[i];
        }
    }

    //如果第一层有
    if (beforeNode->next[0]->element == theKey) {
        return true;
    }
    return false;
}

template<class K>
int skipList<K>::level() const {
    int lev = 0 ;
    while (rand() <= cutOff) {
        lev++;
    }
    return (lev <= maxLevel) ? lev : maxLevel;
}

template<class K>
skipNode<K>* skipList<K>::search(const K &theKey) const {
    skipNode<K> * beforeNode = headerNode;
    // last[i]更新为关键字的前一个结点
    for (int i = levers; i >= 0; i--) {
        while (beforeNode->next[i]->element < theKey) {
            beforeNode = beforeNode->next[i];
        }
        last[i] = beforeNode;
    }

    return beforeNode->next[0];
}

template<class K>
void skipList<K>::insert(const K &theKey) {
    if (theKey >= tailKey) {
        return;
    }

    //此时存储了每一级需要插入的后一个结点
    skipNode<K> * theNode = search(theKey);
    if (theNode->element == theKey) {
        return;
    }

    //确定新节点的链表级数
    int theLevel = level();
    if (theLevel > levers) {
        //比如说现有3级 , 加到了5级, 则设为4级
        theLevel = ++levers;
        last[theLevel] = headerNode;
    }

    // 比如说属于3级链表, 则创建4个next即可
    skipNode<K> * newNode = new skipNode<K> (theKey, theLevel + 1);
    for (int i = 0 ;i <= theLevel; i++) {
        newNode->next[i] = last[i] ->next[i];
        last[i]->next[i] = newNode;
    }

    //插入后更新
    dSize++;
    return ;
}

template<class K>
void skipList<K>::erase(const K &theKey) {
    if (theKey >= tailKey) {
        return;
    }

    skipNode<K>* theNode = search(theKey);
    if (theNode->element != theKey) {
        return;
    }

    //删除结点, 此时不知道该结点对应的级数?
    for (int i = 0 ; i <= levers && last[i]->next[i] == theNode; i++) {
        last[i] -> next[i] = theNode->next[i];
    }

    //更新链表级
    while (levers > 0 && headerNode->next[levers] == tailNode) {
        levers--;
    }

    //释放结点空间
    delete theNode;
    dSize--;
}

template<class K>
int skipList<K>::size() {
    return dSize;
}

template<class K>
bool skipList<K>::empty() {
    return size() == 0;
}

template<class K>
void skipList<K>::output(ostream & out) const{
    for (auto t = headerNode->next[0]; t != tailNode; t = t->next[0]) {
        out << t->element << " ";
    }
}

template<class K>
int skipList<K>::xorNum() {
    int ans = 0;
    for (auto t = headerNode->next[0]; t != tailNode; t = t->next[0]) {
        ans ^= t->element;
    }
    return ans;
}

template<class K>
int skipList<K>::eraseMinElement() {
    int ele = headerNode->next[0]->element;
    erase(ele);
    return ele;
}

template<class K>
int skipList<K>::eraseMaxElement() {
    if (empty()) {
        return -1;
    }
    auto t = headerNode[0].next[0];
    while(t -> next[0] != tailNode) {
        t = t ->next[0];
    }

    int ele = t->element ;
    erase(ele);
    return ele;
}

// 重构跳表
template<class K>
void skipList<K>::reBuild()
{
//    if (dSize == 0) {
//        return;
//    }
//    int val = 3;
//    // 找到第一个节点
//    skipNode<K>* nowNode = headerNode->next[0];
//    //初始化last数组为头结点
//    for (int i = 0; i <= maxLevel; i++) {
//        last[i] = headerNode;
//    }
//    // 从第二个节点开始遍历
//    for (int index = 1; index <= dSize; index++)
//    {
//        int cur = index;
//        int cur_level = 0;//记录当前节点应该有的最高级数
//        while (cur % val ==0) {
//            cur_level++;
//            cur /= val;
//        }
//        skipNode<K> *nextNode = nowNode->next[0];// 保存下一个节点
//        //将级数置为cur_level + 1
//        nowNode->next = new skipNode<K> * [cur_level + 1];
//        //最高级数之下的进行重构, 使用尾插法
//        for (int i = 0; i <= cur_level; i++) {
//            last[i]->next[i] = nowNode;
//            last[i] = nowNode;
//        }
//        nowNode = nextNode;// 移到下一个节点
//    }
//
//    // 连接尾结点
//    for (int i = 0; i <= maxLevel; i++)
//    {
//        last[i]->next[i] = tailNode;
//    }
}
