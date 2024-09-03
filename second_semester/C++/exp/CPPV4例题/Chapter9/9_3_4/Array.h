//Array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

//������ģ�嶨��
template <class T> 
class Array {
private:
	T* list;	//T����ָ�룬���ڴ�Ŷ�̬����������ڴ��׵�ַ
	int size;	//�����С��Ԫ�ظ�����
public:
	Array(int sz = 50);			//���캯��
	Array(const Array<T> &a);	//�������캯��
	~Array();	//��������
	Array<T> & operator = (const Array<T> &rhs); //����"="ʹ�������������帳ֵ
	T & operator [] (int i);	//����"[]"��ʹArray���������C++��ͨ���������
	const T & operator [] (int i) const;	//"[]"�������const�汾
	operator T * ();	//���ص�T*���͵�ת����ʹArray���������C++��ͨ���������
	operator const T * () const;	//��T*����ת����������const�汾
	int getSize() const;	//ȡ����Ĵ�С
	void resize(int sz);	//�޸�����Ĵ�С
};

//���캯��
template <class T>
Array<T>::Array(int sz) {
	assert(sz >= 0);	//szΪ�����С��Ԫ�ظ�������Ӧ���Ǹ�
	size = sz;	// ��Ԫ�ظ�����ֵ������size
	list = new T [size];	//��̬����size��T���͵�Ԫ�ؿռ�
}

//��������
template <class T>
Array<T>::~Array() {
	delete [] list;
}

//�������캯��
template <class T>
Array<T>::Array(const Array<T> &a) {
	//�Ӷ���xȡ�������С������ֵ����ǰ����ĳ�Ա
	size = a.size;
	//Ϊ���������ڴ沢���г�����
	list = new T[size];	// ��̬����n��T���͵�Ԫ�ؿռ�
	//�Ӷ���X��������Ԫ�ص�������  
	for (int i = 0; i < size; i++)
		list[i] = a.list[i];
}

//����"="�������������rhs��ֵ��������ʵ�ֶ���֮������帳ֵ
template <class T>
Array<T> &Array<T>::operator = (const Array<T>& rhs) {
	if (&rhs != this) {
		//����������������С��rhs��ͬ����ɾ������ԭ���ڴ棬Ȼ�����·���
		if (size != rhs.size) {
			delete [] list;		//ɾ������ԭ���ڴ�
			size = rhs.size;	//���ñ�����������С
			list = new T[size];	//���·���n��Ԫ�ص��ڴ�
		}
		//�Ӷ���X��������Ԫ�ص�������  
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;	//���ص�ǰ���������
}

//�����±��������ʵ������ͨ����һ��ͨ���±����Ԫ�أ����Ҿ���Խ���鹦��
template <class T>
T &Array<T>::operator[] (int n) {
	assert(n >= 0 && n < size);	//����±��Ƿ�Խ��
	return list[n];			//�����±�Ϊn������Ԫ��
}

template <class T>
const T &Array<T>::operator[] (int n) const {
	assert(n >= 0 && n < size);	//����±��Ƿ�Խ��
	return list[n];			//�����±�Ϊn������Ԫ��
}

//����ָ��ת�����������Array��Ķ�����ת��ΪT���͵�ָ�룬
//ָ��ǰ�����е�˽�����顣
//���������ʹ����ͨ�����׵�ַһ��ʹ��Array��Ķ�����
template <class T>
Array<T>::operator T * () {
	return list;	//���ص�ǰ������˽��������׵�ַ
}

template <class T>
Array<T>::operator const T * () const {
	return list;	//���ص�ǰ������˽��������׵�ַ
}

//ȡ��ǰ����Ĵ�С
template <class T>
int Array<T>::getSize() const {
	return size;
}

// �������С�޸�Ϊsz
template <class T>
void Array<T>::resize(int sz) {
	assert(sz >= 0);	//���sz�Ƿ�Ǹ�
	if (sz == size)	//���ָ���Ĵ�С��ԭ�д�Сһ����ʲôҲ����
		return;
	T* newList = new T [sz];	//�����µ������ڴ�
	int n = (sz < size) ? sz : size;	//��sz��size�н�С��һ����ֵ��n
	//��ԭ��������ǰn��Ԫ�ظ��Ƶ���������
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[] list;		//ɾ��ԭ����
	list = newList;	// ʹlistָ��������
	size = sz;	//����size
}
#endif  //ARRAY_H
