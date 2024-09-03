#ifndef ARRAY1_H_
#define ARRAY1_H_

#include <iostream>
using namespace std;

template <class T>
class Array
{
	T* alist;
	int size;
public:
	Array() {size = 0;}
	Array(int sz) {alist = new T[sz]; size = sz;}
	Array(T a[], int sz) {
		size = sz;
		alist = new T[size];
		for (int i = 0; i < size; i ++)
			alist[i] = a[i];
	}
	~Array() {size = 0; delete []alist;}
	int getSize() {return size;}
	T& operator [](int i) {return alist[i];}
	void insertSort();
	void selectSort();
	void bubbleSort();
	int seqSearch(T key) {
		int i;
		for (i = 0; i < size; i ++)
			if (alist[i] == key)
				return i;
		if (i == size) {
			cout << "û���ҵ�Ԫ��" << endl;
			return -1;
		}
	}
};

template <class T>
void Array<T>::insertSort()
{
	int i, j;
	T temp;
	//���±�Ϊ1��size-1��Ԫ��������뵽�������������ʵ���λ��
	for (i = 1; i < size; i ++) 
	{
		//��a[i-1]��ʼ��a[0]����ɨ���Ԫ��,Ѱ���ʵ�λ�ò���a[i]
		j = i;
		temp = alist[i];
		while (j > 0 && temp < alist[j-1]) 
		{   //����Ƚϣ�ֱ��temp>=a[j-1]ʱ��j����Ӧ�����λ�á�
			alist[j] = alist[j-1];  //��Ԫ��������ƣ��Ա��ҵ�����λ��ʱ���������롣
			j--;
		}
		//����λ�����ҵ����������롣
		alist[j] = temp;
	}
	//�������
	for(i = 0; i < size; i ++)
		cout << alist[i] << "  ";
	cout << endl;
}

template <class T>
void Array<T>::selectSort()
{
	int minIndex; //ÿһ��ѡ������СԪ��֮�±�
	int i, j;
	T temp;
	//sort a[0]..a[size-2], and a[size-1] is in place
	for (i = 0; i < size - 1; i ++) 
	{
		minIndex = i;    //��СԪ��֮�±��ֵ��Ϊi
		//��Ԫ��a[i+1]..a[size-1]������Ƚ��Գ���Сֵ
		for (j = i + 1; j < size; j++) 
			//minIndexʼ�ռ�¼��ǰ�ҵ�����Сֵ���±�
			if (alist[j] < alist[minIndex])
				minIndex = j;
		//����һ���ҵ�����СԪ����a[i]����
		temp = alist[i];
		alist[i] = alist[minIndex];
		alist[minIndex] = temp;
	}
	//�������
	for(i = 0; i < size; i ++)
		cout << alist[i] << "  ";
	cout << endl;
}

template <class T>
void Array<T>::bubbleSort()
{
	T temp;
	int i, j;
	for (i = 1; i < size; i ++) {
		for (j = size - 1; j >= i; j --) {
			if (alist[j - 1] > alist[j]) {
				temp = alist[j];
				alist[j] = alist[j - 1];
				alist[j - 1] = temp;
			}
		}
	}
	for(i = 0; i < size; i ++)
		cout << alist[i] << "  ";
	cout << endl;
}

#endif //ARRAY1_H_

