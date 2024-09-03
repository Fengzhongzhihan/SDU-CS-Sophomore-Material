#ifndef LINK_H_
#define LINK_H_

#include <iostream>
using namespace std;
#include "node.h"

/*
* ��LinkedList������У������˸���ָ��front��rear��������ĽṹΪfront->a1->a2->...->rear
* ֻ�������������в�ɾ��������ָ�룬�����ʱ��������ָ�붼�Ǵ��ڵģ����е�����ʼ��Ϊ0�����洢�û�����
*/
template <class T>
class LinkedList {
private:
	Node<T> *front, *rear; //��ͷ�ͱ�βָ��
	Node<T> *prevPtr, *currPtr; //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
	int size; //����Ԫ�ظ���
	int position; //��ǰԪ���ڱ��е�λ����š��ɺ���resetʹ��

	Node<T>* newNode(const T& item, Node<T> *ptrNext = NULL); //�����½ڵ㣬������Ϊitem��ָ����ΪprtNext
	void freeNode(Node<T> *p); //�ͷŽڵ�

	void copy(const LinkedList<T>& L); //������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ��������ƹ��캯����operator=����

public:
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
	
	void insertFront(const T& item); //�ڱ�ͷ����ڵ�
	void insertRear(const T& item); //�ڱ�β����ڵ�
	void insertAt(const T& item); //�ڵ�ǰ�ڵ�֮ǰ����ڵ�
	void insertAfter(const T& item); //�ڵ�ǰ�ڵ�֮�����ڵ�

	T deleteFront(); //ɾ��ͷ�ڵ�
	void deleteCurrent(); //ɾ����ǰ�ڵ�
	
	T& data(); //���ضԵ�ǰ�ڵ��Ա���ݵ�����
	const T& data() const; //���ضԵ�ǰ�ڵ��Ա���ݵĳ�����

	void clear(); //��������ͷ����нڵ���ڴ�ռ䣬������������operator=ʹ��
};

//�����½ڵ㣬������Ϊitem��ָ����ΪprtNext
template <class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T> *ptrNext) {
	Node<T> *n = new Node<T>(item, ptrNext);
	return n;
}

//�ͷŽڵ�
template <class T>
void LinkedList<T>::freeNode(Node<T> *p) {
	Node<T>* temp = front;
	while (temp->next != p) {
		temp = temp->next;
		if (temp == currPtr)
			position ++;
	}
	temp->next = p->next;
	if (currPtr == p)
		currPtr = currPtr->next;
	if (prevPtr == p) {
		prevPtr = prevPtr->next;
		currPtr = currPtr->next;
	}
	delete p;
	size --;
	position --;
}

//������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ��������ƹ��캯����operator=����
template <class T>
void LinkedList<T>::copy(const LinkedList<T>& L) {
	Node<T> *temp = L.front, *ptr = front;
	while (temp != L.rear) {
		ptr->next = new Node<T>(temp->getData, NULL);
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
	front = new Node<T>();
	rear = new Node<T>();
	front->next = rear;
	currPtr = rear;
	prevPtr = front;
	size = 0; //������front��rear
	position = 0; //��front��һ��Ԫ����Ϊ0
}

//���ƹ��캯��
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L) {
	clear();
	copy(L);
}

//��������
template <class T>
LinkedList<T>::~LinkedList() {
	LinkedList::clear();
	delete front;
	delete rear;
}

//���ظ�ֵ�����
template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& L) {
	clear();
	copy(L);
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
void LinkedList<T>::reset(int pos) { //��ʼ���α�λ��
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

//ʹ�α��ƶ�����һ���ڵ�
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

//�ڱ�ͷ����ڵ�
template <class T>
void LinkedList<T>::insertFront(const T& item) {
	Node<T>* n = new Node<T>(item, front);
	front = n;
	size ++;
	position ++;
}

//�ڱ�β����ڵ�
template <class T>
void LinkedList<T>::insertRear(const T& item) {
	Node<T>* temp = front;
	while (temp->next != rear)
		temp = temp->next;
	Node<T> *n = new Node<T>(item, rear);
	temp->next = n;
	size ++;
}

//�ڵ�ǰ�ڵ�֮ǰ����ڵ�
template <class T>
void LinkedList<T>::insertAt(const T& item) {
	Node<T>* temp = new Node<T>(item, currPtr);
	prevPtr->next = temp;
	prevPtr = temp;
	size ++;
	position ++;
}

//�ڵ�ǰ�ڵ�֮�����ڵ�
template <class T>
void LinkedList<T>::insertAfter(const T& item) {
	Node<T>* temp = new Node<T>(item, NULL);
	temp->next = currPtr->next;
	currPtr->next = temp;
	size ++;
}

//ɾ��ͷ�ڵ㣬ʵ����ɾ��front->next
template <class T>
T LinkedList<T>::deleteFront() {
	if (front->next == rear) {
		cout << "û�нڵ����ɾ��" << endl; 
	}
	if (prevPtr == front->next) {
		prevPtr = prevPtr->next;
		currPtr = currPtr->next;
	}
	Node<T>* temp = front->next;
	T d = temp->getData();
	front->next = temp->next;
	delete temp;
	size --;
	if (front->next != rear)
		position --;
	return d;
}

//ɾ����ǰ�ڵ�
template <class T>
void LinkedList<T>::deleteCurrent() {
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

//��������ͷ����нڵ���ڴ�ռ䣬������������operator=ʹ��
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

#endif //LINK_H_
