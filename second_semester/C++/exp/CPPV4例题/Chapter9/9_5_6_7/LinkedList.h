//9_6.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList {
private:
	//���ݳ�Ա��
	Node<T> *front, *rear;	//��ͷ�ͱ�βָ��
	Node<T> *prevPtr, *currPtr;   //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
	int size;	//���е�Ԫ�ظ���
	int position;	//��ǰԪ���ڱ��е�λ����š��ɺ���resetʹ��

	//������Ա��
	//�����½�㣬������Ϊitem��ָ����ΪptrNext
	Node<T> *newNode(const T &item,Node<T> *ptrNext=NULL);

	//�ͷŽ��
	void freeNode(Node<T> *p);

	//������L ��������ǰ�����赱ǰ��Ϊ�գ���
	//���������캯����operator = ����
	void copy(const LinkedList<T>& L);

public:
	LinkedList();	//���캯��
	LinkedList(const LinkedList<T> &L);  //�������캯��
	~LinkedList();	//��������
	LinkedList<T> & operator = (const LinkedList<T> &L); //���ظ�ֵ�����

	int getSize() const;	//����������Ԫ�ظ���
	bool isEmpty() const;	//�����Ƿ�Ϊ��

	void reset(int pos = 0);//��ʼ���α��λ��
	void next();	//ʹ�α��ƶ�����һ�����
	bool endOfList() const;	//�α��Ƿ�����β
	int currentPosition(void) const;	//�����α굱ǰ��λ��

	void insertFront(const T &item);	//�ڱ�ͷ������
	void insertRear(const T &item);		//�ڱ�β��ӽ��
	void insertAt(const T &item);		//�ڵ�ǰ���֮ǰ������
	void insertAfter(const T &item);	//�ڵ�ǰ���֮�������

	T deleteFront();	//ɾ��ͷ���
	void deleteCurrent();	//ɾ����ǰ���

	T& data();				//���ضԵ�ǰ����Ա���ݵ�����
	const T& data() const;   //���ضԵ�ǰ����Ա���ݵĳ�����

	//��������ͷ����н����ڴ�ռ䡣������������operator= ����
	void clear();
};

#endif  //LINKEDLIST_H
