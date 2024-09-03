//9_15.h
#ifndef HEADER_9_15_H
#define HEADER_9_15_H

//���۰���ҷ�������Ԫ�س��������е�����list�в���ֵΪkey��Ԫ��
template <class T>
int binSearch(const T list[], int n, const T &key) {
	int low = 0;
	int high = n - 1;
	while (low <= high) {	//low <= high��ʾ����������δ������
		int mid = (low + high) / 2;	//���м�Ԫ�ص��±�
		if (key == list[mid])    
			return mid;		//���ҵ�,�����±�
		else if (key < list[mid])
			high = mid - 1;	//��key < midvalue�����ҷ�Χ��С�������ǰһ��
		else
			low = mid + 1;	//���򽫲��ҷ�Χ��С������ĺ�һ��
	}
	return -1;	//û���ҵ�����-1
}

#endif	//HEADER_9_15_H
