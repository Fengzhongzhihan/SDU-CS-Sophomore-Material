//9_11.h
#ifndef HEADER_9_11_H
#define HEADER_9_11_H

//��ֱ�Ӳ������򷨶�����A�е�Ԫ�ؽ�����������
template <class T>
void insertionSort(T a[], int n) {
	int i, j;
	T temp;

	//���±�Ϊ1��n-1��Ԫ��������뵽�������������ʵ���λ��
	for (int i = 1; i < n; i++) {
		//��a[i - 1]��ʼ��a[0]����ɨ���Ԫ��,Ѱ���ʵ�λ�ò���a[i]
		int j = i;
		T temp = a[i];
		while (j > 0 && temp < a[j - 1]) {
			//����Ƚϣ�ֱ��temp >= a[j - 1]ʱ��j����Ӧ�����λ�á�
			//���ﵽj == 0����0��Ӧ�����λ�á�
			a[j] = a[j - 1];    //��Ԫ��������ƣ��Ա��ҵ�����λ��ʱ���������롣
			j--;
		}
		//����λ�����ҵ����������롣
		a[j] = temp;
	}
}
#endif	//HEADER_9_11_H
