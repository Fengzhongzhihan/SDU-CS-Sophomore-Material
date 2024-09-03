#include <iostream>

using namespace std;
#ifndef HEADER_9_13_H
#define HEADER_9_13_H

//��������������x��y��ֵ
template <class T>
void mySwap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

//�����������Ƚ�x��y�Ĵ�С
template <class T>
bool LessThan(T &x, T &y) {
	return x<y;
}

//�����������Ƚ�*x��*y�Ĵ�С
template <class T>
bool LessThan (T* &x, T* &y) {
	return *x<*y;
}

//�����ݷ�������A��n��Ԫ�ؽ�������
template <class T>
void bubbleSort(T a[], int n) {
	int i = n - 1;	// i����һ����������򽻻���Ԫ��֮����±�
	while (i > 0) {	//����������̣�ֱ�����һ������û�н������������Ѵ�n - 1��
		int lastExchangeIndex = 0;	//ÿһ�˿�ʼʱ�����ý�����־Ϊ0��δ������
		for (int j = 0; j < i; j++)	//ÿһ�˶�Ԫ��a[0]..a[i]���бȽϺͽ���
			if (LessThan (a[j + 1],a[j])) {	//���Ԫ��a[j + 1] < a[j]������֮
				mySwap(a[j], a[j + 1]);
				lastExchangeIndex = j;	//��¼��������һ��Ԫ���н�С���±�
			}
		i = lastExchangeIndex;	//��i����Ϊ���˱����������һ��Ԫ���н�С���±�
	}
}
#endif	//HEADER_9_13_H

int main()
{
	int data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
	int *p[20];

	for(int i=0; i<20; ++i)
	{
		p[i] = &data[i];
	}
	bubbleSort(p,20);
	for(int i=0; i<20; ++i)
	{
		cout << *p[i] << "\t";
	}

	cout << endl;
	return 0;
}
