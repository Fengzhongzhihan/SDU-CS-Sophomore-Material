//
// Created by Lenovo on 2024-05-25.
//
#include "bits/stdc++.h"
using namespace std;
template <class T>
class Node {
private:
    T data;
public:
    Node<T>* next;
    Node();
    Node(const T& data, Node<T>* nt = 0);
//	Node(T data, Node<T>* n = NULL);
    T& getData();
};

template <class T>
Node<T>::Node() {
    data = 0;
    next = NULL;
}

template <class T>
Node<T>::Node(const T& d, Node<T>* nt) {
    data = d;
    next = nt;
}

template <class T>
T& Node<T>::getData() {
    return data;
}


/*
* ��LinkedList������У������˸���ָ��front��rear��������ĽṹΪfront->a1->a2->...->rear
* ֻ�������������в�ɾ��������ָ�룬�����ʱ��������ָ�붼�Ǵ��ڵģ����е�����ʼ��Ϊ0�����洢�û�����
*/
template <class T>
class LinkedList {
private:
    Node<T> *front, *rear; //��ͷ�ͱ�βָ��
    Node<T> *prevPtr, *currPtr; //��ǰ�ڵ��ǰָ��͵�ǰָ�롣��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
    int size; //����Ԫ�ظ���
    int position; //��ǰԪ��(*currPtr)�ڱ��е�λ����š��ɺ���resetʹ��
    //�ڲ�����
    Node<T>* newNode(const T& item, Node<T> *ptrNext = NULL); //�����½ڵ㣬������Ϊitem��ָ����ΪprtNext
    void freeNode(Node<T> *p); //�ͷŽڵ�

    void copy(const LinkedList<T>& L); //������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ��������ƹ��캯����operator=����

public:  //�ⲿ�ӿ�
    LinkedList(); //���캯��
    LinkedList(const LinkedList<T>& L); //���ƹ��캯��
    ~LinkedList(); //��������
    LinkedList<T>& operator = (const LinkedList<T>& L); //���ظ�ֵ�����

    int getSize() const; //����������Ԫ�ظ���
    bool isEmpty() const; //�����Ƿ�Ϊ��

    void reset(int pos = 0); //��ʼ���α��λ��
    void next(); //ʹ�α��ƶ�����һ���ڵ�
    bool endOfList() const; //�α��Ƿ��ƶ�����β
    int currentPosition() const; //�����α굱ǰ��λ��

    void insertFront(const T& item); //�ڱ�ͷ�ڵ�front֮ǰ����ڵ�
    void insertRear(const T& item); //������β�ڵ�rear֮ǰ����ڵ�
    void insertAt(const T& item); //�ڵ�ǰ�ڵ�֮ǰ����ڵ�
    void insertAfter(const T& item); //�ڵ�ǰ�ڵ�֮�����ڵ�

    T deleteFront(); //ɾ��ͷ�ڵ�
    void deleteCurrent(); //ɾ����ǰ�ڵ�

    T& data(); //���ضԵ�ǰ�ڵ��Ա���ݵ�����
    const T& data() const; //���ضԵ�ǰ�ڵ��Ա���ݵĳ�����

    void clear(); //��������ͷ����нڵ���ڴ�ռ䣬������������operator=ʹ��
    void show(){
        cout<<"*front:" << front<<endl;
        cout<<" *rear:" << rear <<endl;  //��ͷ�ͱ�βָ��
        cout<<"*prevPtr:"<<prevPtr<<" *currPtr:"<<currPtr<<endl;   //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
        cout<<"size:"<<size <<"  position:"<<position<<endl;
    }
};

//�����½ڵ㣬������Ϊitem��ָ����ΪprtNext���ڲ�����
template <class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T> *ptrNext) {
    Node<T> *n = new Node<T>(item, ptrNext);
    return n;
}

//�ͷŽڵ㣬�ڲ�����
template <class T>
void LinkedList<T>::freeNode(Node<T> *p) {
    Node<T>* temp = front;
    while (temp->next != p) {  //��ͷ�ڵ����Ľڵ㿪ʼ��������ָ��p�Ľڵ�
        temp = temp->next;
        if (temp == currPtr)   //
            position ++;      //currPtrҪ����
    }
    temp->next = p->next;   //ɾ���ڵ���� ����û�ҵ���

    if (currPtr == p)      //��ɾ�����ǵ�ǰָ����ָ���
        currPtr = currPtr->next;

    if (prevPtr == p) {    //��ɾ�����ǵ�ǰָ���ǰһ�����
        prevPtr = prevPtr->next;
        currPtr = currPtr->next;
    }
    delete p;
    size --;
    position --;
}

//������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ��������ƹ��캯����operator=���� ���ڲ�����
template <class T>
void LinkedList<T>::copy(const LinkedList<T>& L) {
    Node<T> *temp = L.front, *ptr = front;
    while (temp != L.rear) {
        ptr->next = new Node<T>(temp->getData, NULL); // temp->getData()
        ptr = ptr->next;
        temp = temp->next;
    }
    ptr->next = rear;
    size = L.getSize();
    position = L.currentPosition();
}

//���캯��
template <class T>
LinkedList<T>::LinkedList() {
    front = new Node<T>();  //ָ���½��ڵ㣬ʵ�ʽ���һ���յ�ͷnode����β�ڵ�
    rear = new Node<T>();
    front->next = rear;
    currPtr = rear;   //��ǰָ��ָ��β�ڵ�
    prevPtr = front;  //֮ǰָ��ָ��ͷ�ڵ�
    size = 0; //������front��rear�ڵ�
    position = 0; //��front��һ��Ԫ����Ϊ0
}

//���ƹ��캯��
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L) {
    clear();  //����ͷŵ�ǰ����
    copy(L);  //��������
}

//��������
template <class T>
LinkedList<T>::~LinkedList() {
    LinkedList::clear();  //����ͷŵ�ǰ����
    delete front;  //�ͷ�ͷָ����ָ�ڵ�
    delete rear;   //�ͷ�βָ����ָ�ڵ�
}

//���ظ�ֵ�����
template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& L) {
    clear();   //����ͷŵ�ǰ����
    copy(L);   //��������
}

//����������Ԫ�ظ���
template <class T>
int LinkedList<T>::getSize() const {
    return size;
}

//�����Ƿ�Ϊ��
template <class T>
bool LinkedList<T>::isEmpty() const {
    return (size == 0);
}

//��ʼ���α��λ��
template <class T>
void LinkedList<T>::reset(int pos) { //�ƶ��α�(��ǰָ��currPtr)��pos��ָ��λ��
    if (pos > size) {
        cout << "Խ�磬�޷�����" << endl;
        return;
    }
    int i = 0;
    prevPtr = front;
    currPtr = front->next;
    while (i < pos) {
        if (currPtr == rear) {
            cout << "Խ�磬�޷�����" << endl;
            return;
        }
        i ++;
        currPtr = currPtr->next;
        prevPtr = prevPtr->next;
    }
    position = pos;
}

//ʹ�α�(��ǰָ��currPtr)�ƶ�����һ���ڵ�
template <class T>
void LinkedList<T>::next() {
    if (currPtr == rear) {
        cout << "�Ѿ���������β���޷��ƶ�" << endl;
        return;
    }
    currPtr = currPtr->next;
    prevPtr = prevPtr->next;
    position ++;
}

//�α��Ƿ��ƶ�����β
template <class T>
bool LinkedList<T>::endOfList() const {
    return (currPtr == rear);
}

//�����α굱ǰ��λ��
template <class T>
int LinkedList<T>::currentPosition() const {
    return position;
}

//�ڱ�ͷ����ڵ�,ԭͷ�ڵ�front֮ǰ���� ������֮��ԭͷ�ڵ��ֵΪ�գ������²����ͷ���Ҳ��Ϊ�գ�ֵΪitem.
template <class T>
void LinkedList<T>::insertFront(const T& item) {
//    Node<T>* n = new Node<T>(item, front);
    Node<T>* n = newNode(item, front->next);
//    front = n;
    front -> next = n;
    if(prevPtr == front)  //�����ǰ�ڵ��ǰ�ڵ���ͷ���front
        prevPtr = n;      //��ǰ�ڵ��ǰ�ڵ�Ӧ�����²����ͷ���
    size ++;
    position ++;
}

//������β�ڵ�֮ǰ����ڵ�
template <class T>
void LinkedList<T>::insertRear(const T& item) {
    Node<T>* temp = front;
    while (temp->next != rear)
        temp = temp->next;    //temp����rear֮ǰ
    Node<T> *n = new Node<T>(item, rear);
    temp->next = n;
    size ++;
}

//�ڵ�ǰ�ڵ�֮ǰ����ڵ�
template <class T>
void LinkedList<T>::insertAt(const T& item) {
    Node<T>* temp = new Node<T>(item, currPtr);
    prevPtr->next = temp;
    size ++;
    position ++;
}

//�ڵ�ǰ�ڵ�֮�����ڵ�
template <class T>
void LinkedList<T>::insertAfter(const T& item) {
    if (currPtr == rear) {
        insertAt(item);
    }

    Node<T>* temp = new Node<T>(item, currPtr->next);
    currPtr->next = temp;
    size ++;
}

//ɾ��ͷ�ڵ㣬ʵ����ɾ��front->next�������ر�ɾͷ�ڵ��ֵ
template <class T>
T LinkedList<T>::deleteFront() {
    if (front->next == rear) {
        cout << "û�нڵ����ɾ��" << endl;
    }
    if (prevPtr == front->next) { //�����ǰ�ڵ��ǰ�ڵ��Ǳ�ɾ��ͷ���front->next
        prevPtr = prevPtr->next;  //��Ӧ���ƶ��� Ӧ���ж�currPtr== front->next
        currPtr = currPtr->next;  //���position���䣬��ǰλ��Ҫ����һλ���������position-- ��ì��
    }
    Node<T>* temp = front->next; // ��ɾ��㴦��
    T d = temp->getData();
    front->next = temp->next;   //�޸�ͷָ��
    delete temp;
    size --;
    if (front->next != rear)
        position --;    //��ɾ�ڵ��ڵ�ǰ�ڵ�֮ǰ��
    return d;
}

//ɾ����ǰ�ڵ�
template <class T>
void LinkedList<T>::deleteCurrent() {
    if (currPtr == rear || currPtr == front) {
        cout << "û�нڵ����ɾ��" << endl;
        return;
    }
    Node<T>* temp = currPtr;
    currPtr = currPtr->next;
    delete temp;
    size --;
}

//���ضԵ�ǰ�ڵ��Ա���ݵ�����
template <class T>
T& LinkedList<T>::data() {
    return currPtr->getData();
}

//���ضԵ�ǰ�ڵ��Ա���ݵĳ�����
template <class T>
const T& LinkedList<T>::data() const {
    return currPtr->getData();
}

//����������ݣ��ͷ����нڵ���ڴ�ռ䣬������������operator=ʹ��
template <class T>
void LinkedList<T>::clear() {
    Node<T>* temp;
    while (front->next != rear) {
        temp = front->next;
        front->next = temp->next;
        delete temp;
    }
    size = 0;
    position = 0;
}

void disp(LinkedList<int> &list){  	//�������
    cout << "List: ";
    list.reset();
    //�����������ݣ�ֱ������β
    while (!list.endOfList()) {
        cout << list.data() << "  ";
        list.next();	//ʹ�α�ָ����һ�����
    }
    cout << endl;
}

int main() {
    LinkedList<int> list;

    cout<<"insertFront Bug"<<endl;
    list.insertFront(6);  //ͷ�ڵ�֮ǰ����
    list.insertAt(7);    //��ǰ�ڵ�֮ǰ����
    disp(list);  //��ΪinsertFront()bug��6��7֮�����0������6��ʾ������

    cout<<"insertAfter Bug"<<endl;
    list.insertAfter(8);
    disp(list);  //��ΪinsertAfter()bug�����²����8��Ҳ�޷���ʾ

    cout<<"deleteCurrent Bug"<<endl;
    list.deleteCurrent();   //����βָ��rear�ڵ㱻��ǰɾ��
    disp(list);


}
