//9_14.h
#ifndef HEADER_9_14_H
#define HEADER_9_14_H

//��˳����ҷ�������list�в���ֵΪkey��Ԫ��
//���ҵ������ظ�Ԫ���±꣬���򷵻�-1
template <class T>
int seqSearch(const T list[], int n, const T &key) {
	for(int i = 0; i < n; i++)
		if (list[i] == key)
			return i;            
	return -1;                 
}

#endif	//HEADER_9_14_H
