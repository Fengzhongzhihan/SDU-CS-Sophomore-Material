#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

template<class K>
struct BSTNode {
    BSTNode *leftChild;
    BSTNode *rightChild;
    K key;
    int index;

    BSTNode() {};

    BSTNode(K theKey) {
        key = theKey;
        leftChild = NULL;
        rightChild = NULL;
        index = 0;
    }

    BSTNode(BSTNode *bst) {
        bst->rightChild = this->rightChild;
        bst->leftChild = this->leftChild;
        bst->key = this->key;
        bst->index = this->index;
    }

    BSTNode(const K &theElement, BSTNode<K> *theLeft, BSTNode<K> *theRight, int LeftTreeSize) {
        key = theElement;
        leftChild = theLeft;
        rightChild = theRight;
        index = LeftTreeSize;
    }

};

template<class K>
class BSTWithIndex {
public:
    BSTWithIndex() {
        root =NULL;
        Treesize=0;
    };

    //插入、删除、按名次删除、查找、按名次查找、升序输出所有元素。
    int insert(K theKey);

    int erase(K theKey);

    int eraseWithIndex(int theIndex);

    int find(K theKey);

    int findWithIndex(int theIndex);

    void out();

private:
    int Treesize;
    BSTNode<K> *root;

};

template<class K>
int BSTWithIndex<K>::insert(K theKey) {
    BSTNode<K> *currentNode = root;
    BSTNode<K>  *parent = NULL;
    int sum = 0;

    while (currentNode != NULL) {
        if (theKey < currentNode->key) {
            sum ^= currentNode->key;
            parent = currentNode;
            currentNode = currentNode->leftChild;
        } else if (theKey > currentNode->key) {
            sum ^= currentNode->key;
            parent = currentNode;
            currentNode = currentNode->rightChild;
        } else if (theKey == currentNode->key){
            return 0;
        }
    }
    BSTNode<K> *newNode = new BSTNode<K>(theKey);
    if (parent != NULL) {
        if (parent->key > theKey)
            parent->leftChild = newNode;
        else
            parent->rightChild = newNode;
    } else {
        root = newNode;
    }
    Treesize++;
    currentNode = root;
    while (currentNode->key != theKey) {
        if (currentNode->key < theKey) {
            currentNode = currentNode->rightChild;
        } else if (currentNode->key > theKey) {
            currentNode->index++;
            currentNode = currentNode->leftChild;
        }
    }
    return sum;
}

template<class K>
int BSTWithIndex<K>::erase(K theKey) {
    BSTNode<K> *currentNode = root;
    BSTNode<K> *parent = NULL;
    int sum = 0;
    while (currentNode != NULL && currentNode->key != theKey) {
        sum ^= currentNode->key;
        parent = currentNode;
        if (currentNode->key < theKey) {
            currentNode = currentNode->rightChild;
        } else if (currentNode->key > theKey) {
            currentNode = currentNode->leftChild;
        }
    }
    if (currentNode == NULL) {
        return 0;
    }
    sum ^= currentNode->key;
    currentNode = root;
    while (currentNode != NULL && currentNode->key != theKey) {
        if (currentNode->key < theKey) {
            currentNode = currentNode->rightChild;
        } else if (currentNode->key > theKey) {
            currentNode->index--;
            currentNode = currentNode->leftChild;
        }
    }

    if (currentNode->leftChild != NULL && currentNode->rightChild != NULL) {
        BSTNode<K> *ps = currentNode->rightChild;
        BSTNode<K> *s = currentNode;
        while (ps->leftChild != NULL) {
            ps->index--;
            s = ps;
            ps = ps->leftChild;
        }

        BSTNode<K> *newNode = new BSTNode<K>(ps->key, currentNode->leftChild, currentNode->rightChild,
                                             currentNode->index);
        if (parent == NULL)
            root = newNode;
        else if (currentNode == parent->leftChild)
            parent->leftChild = newNode;
        else
            parent->rightChild = newNode;

        if (s == currentNode)
            parent = newNode;
        else
            parent = s;

        delete currentNode;
        currentNode = ps;
    }

    BSTNode<K> *c;
    if (currentNode->leftChild != NULL)
        c = currentNode->leftChild;
    else
        c = currentNode->rightChild;
    if (currentNode == root)
        root = c;
    else {
        if (currentNode == parent->leftChild)
            parent->leftChild = c;
        else
            parent->rightChild = c;
    }
    Treesize--;
    return sum;

}

template<class K>
int BSTWithIndex<K>::eraseWithIndex(int theIndex) {
    BSTNode<K> *currentNode = root;
    BSTNode<K> *parent = NULL;
    int sum = 0;
    while (currentNode != NULL && currentNode->index != theIndex) {
        sum ^= currentNode->key;
        parent = currentNode;
        if (currentNode->index > theIndex) {
            currentNode = currentNode->leftChild;
        } else if (currentNode->index < theIndex) {
            theIndex = theIndex - currentNode->index - 1;
            currentNode = currentNode->rightChild;
        }
    }
    if (currentNode == NULL)
        return 0;
    sum ^= currentNode->key;
    int theElement = currentNode->key;
    currentNode = root;
    while (currentNode != NULL && currentNode->key != theElement) {
        if (currentNode->key < theElement) {
            currentNode = currentNode->rightChild;
        } else if (currentNode->key > theElement) {
            currentNode->index--;
            currentNode = currentNode->leftChild;
        }
    }

    if (currentNode->leftChild != NULL && currentNode->rightChild != NULL) {
        BSTNode<K> *ps = currentNode->rightChild;
        BSTNode<K> *s = currentNode;
        while (ps->leftChild != NULL) {
            ps->index--;
            s = ps;
            ps = ps->leftChild;
        }

        BSTNode<K> *newNode = new BSTNode<K>(ps->key, currentNode->leftChild, currentNode->rightChild, currentNode->index);
        if (parent == NULL)
            root = newNode;
        else if (currentNode == parent->leftChild)
            parent->leftChild = newNode;
        else
            parent->rightChild = newNode;

        if (s == currentNode)
            parent = newNode;
        else
            parent = s;

        delete currentNode;
        currentNode = ps;
    }

    BSTNode<K> *c;
    if (currentNode->leftChild != NULL)
        c = currentNode->leftChild;
    else
        c = currentNode->rightChild;

    if (currentNode == root)
        root = c;
    else {
        if (currentNode == parent->leftChild)
            parent->leftChild = c;
        else
            parent->rightChild = c;
    }
    Treesize--;
    delete currentNode;
    return sum;


}

template <class K>
int BSTWithIndex<K>::find(K theKey)
{
   BSTNode<K>* currentNode = root;
    int sum = 0;
    while (currentNode != NULL && currentNode->key != theKey)
    {
        sum ^= currentNode->key;
        if (currentNode->key > theKey)
        {
            currentNode = currentNode->leftChild;
        }
        else if (currentNode->key < theKey)

        {
            currentNode = currentNode->rightChild;
        }
    }
    if (currentNode == NULL)
        return 0;
    else
    {
        sum ^= currentNode->key;
        return sum;
    }
}


template<class K>
int BSTWithIndex<K>::findWithIndex(int theIndex) {
    BSTNode<K> *p = root;
    int sum = 0;
    while (p != NULL && p->index != theIndex) {
        sum ^= p->key;
        if (p->index > theIndex) {
            p = p->leftChild;
        } else if (p->index < theIndex) {
            theIndex = theIndex - p->index - 1;
            p = p->rightChild;
        }
    }
    if (p == NULL)
        return 0;
    else {
        sum ^= p->key;
        return sum;
    }

}

void inorderHelper(BSTNode<int> *root) {
    if (root == NULL)return;
    inorderHelper(root->leftChild);
    cout << root->key << " ";
    inorderHelper(root->rightChild);
}


int main() {
    int m;
    scanf("%d", &m);
    BSTWithIndex<int> B;
    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        switch (a) {
            case 0:
                cout << B.insert(b) << endl;
                break;
            case 1:
                cout << B.find(b) << endl;
                break;
            case 2:
                cout << B.erase(b) << endl;
                break;
            case 3:
                b--;
                cout << B.findWithIndex(b) << endl;
                break;
            case 4:
                b--;
                cout << B.eraseWithIndex(b) << endl;
                break;


        }
    }


    return 0;
}
