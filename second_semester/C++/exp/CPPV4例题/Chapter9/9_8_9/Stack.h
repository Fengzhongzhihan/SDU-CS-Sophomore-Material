//Stack.h
#ifndef STACK_H
#define STACK_H
#include <cassert> 

//ģ��Ķ��壬SIZEΪջ�Ĵ�С
template <class T, int SIZE = 50>
class Stack {
private:
	T list[SIZE];	//���飬���ڴ��ջ��Ԫ��
	int top;	//ջ��λ�ã������±꣩
public:
	Stack();	//���캯������ʼ��ջ
	void push(const T &item);	//��Ԫ��itemѹ��ջ
	T pop();	//��ջ��Ԫ�ص���ջ
	void clear();	//��ջ���
	const T &peek() const;	//����ջ��Ԫ��
	bool isEmpty() const;	//�����Ƿ�ջ��
	bool isFull() const;	//�����Ƿ�ջ��
};

//ģ���ʵ��
template <class T, int SIZE>
Stack<T, SIZE>::Stack() : top(-1) { }	//���캯����ջ����ʼ��Ϊ-1

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item) {	//��Ԫ��itemѹ��ջ
	assert(!isFull());	//���ջ���ˣ��򱨴�
	list[++top] = item;	//����Ԫ��ѹ��ջ��
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop() {	//��ջ��Ԫ�ص���ջ
	assert(!isEmpty());	//���ջΪ�գ��򱨴�
	return list[top--];	//����ջ��Ԫ�أ������䵯��ջ��
}

template <class T, int SIZE>
const T &Stack<T, SIZE>::peek() const {	//����ջ��Ԫ��
	assert(!isEmpty());	//���ջΪ�գ��򱨴�
	return list[top];	//����ջ��Ԫ��
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const {	//����ջ�Ƿ��
	return top == -1;
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const {	//�����Ƿ�ջ��
	return top == SIZE - 1;
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear() {	//���ջ
	top = -1;
}

#endif	//STACK_H
