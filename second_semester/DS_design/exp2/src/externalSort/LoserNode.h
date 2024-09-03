//
// Created by Lenovo on 2024-04-08.
//
#ifndef LoserNode_
#define LoserNode_

class LoserNode {
public:
    friend int winner(LoserNode [], int, int);
    friend int main();
    LoserNode(int theID, int theKey) : ID(theID), key(theKey){}
    LoserNode() {}
    int ID, key;
};

#endif
