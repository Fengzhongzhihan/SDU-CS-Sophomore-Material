// main.cpp
#include <iostream>
#include "dnode.h"

template <class T>
class DoublyLinkedList
{
public:
    DNode<T> *head;
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void insertRight(const T& item);
    void insertLeft(const T& item);
    void deleteNode(DNode<T> *node);
    void display() const;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = new DNode<T>();
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head->nextNodeRight() != head)
    {
        deleteNode(head->nextNodeRight());
    }
    delete head;
}

template <class T>
void DoublyLinkedList<T>::insertRight(const T& item)
{
    DNode<T> *newNode = new DNode<T>(item);
    head->insertRight(newNode);
}

template <class T>
void DoublyLinkedList<T>::insertLeft(const T& item)
{
    DNode<T> *newNode = new DNode<T>(item);
    head->insertLeft(newNode);
}

template <class T>
void DoublyLinkedList<T>::deleteNode(DNode<T> *node)
{
    if (node != head)
    {
        node->deleteNode();
        delete node;
    }
}

template <class T>
void DoublyLinkedList<T>::display() const
{
    DNode<T> *current = head->nextNodeRight();
    while (current != head)
    {
        std::cout << current->data << " ";
        current = current->nextNodeRight();
    }
    std::cout << std::endl;
}

int main()
{
    DoublyLinkedList<int> list;

    std::cout << "Inserting 10, 20, 30 to the right:" << std::endl;
    list.insertRight(10);
    list.insertRight(20);
    list.insertRight(30);
    list.display();

    std::cout << "Inserting 5 to the left:" << std::endl;
    list.insertLeft(5);
    list.display();

    std::cout << "Deleting the first node:" << std::endl;
    DNode<int> *firstNode = list.head->nextNodeRight();
    list.deleteNode(firstNode);
    list.display();

    std::cout << "Deleting the last node:" << std::endl;
    DNode<int> *lastNode = list.head->nextNodeLeft();
    list.deleteNode(lastNode);
    list.display();

    return 0;
}
