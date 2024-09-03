//9_13.h
#ifndef HEADER_9_13_H
#define HEADER_9_13_H

//��������������x��y��ֵ
template <class T>
void mySwap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

//�����ݷ�������A��n��Ԫ�ؽ�������
template <class T>
void bubbleSort(T a[], int n) {
	int i = n - 1;	// i����һ����������򽻻���Ԫ��֮����±�
	while (i > 0) {	//����������̣�ֱ�����һ������û�н������������Ѵ�n - 1��
		int lastExchangeIndex = 0;	//ÿһ�˿�ʼʱ�����ý�����־Ϊ0��δ������
		for (int j = 0; j < i; j++)	//ÿһ�˶�Ԫ��a[0]..a[i]���бȽϺͽ���
			if (a[j + 1] < a[j]) {	//���Ԫ��a[j + 1] < a[j]������֮
				mySwap(a[j], a[j + 1]);
				lastExchangeIndex = j;	//��¼��������һ��Ԫ���н�С���±�
			}
		i = lastExchangeIndex;	//��i����Ϊ���˱����������һ��Ԫ���н�С���±�
	}
}
#endif	//HEADER_9_13_H
