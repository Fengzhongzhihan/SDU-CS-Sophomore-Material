//9_2.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct Student {	// �ṹ��Student
	int id;		//ѧ��
	float gpa;	//ƽ����
};  

template <class T>  //��ģ�壺ʵ�ֶ������������ݽ��д�ȡ
class Store {
private:
	T item;			// item���ڴ���������͵�����
	bool haveValue;	// haveValue���item�Ƿ��ѱ���������
public:
	Store();		// ȱʡ��ʽ�����βΣ��Ĺ��캯��
	T &getElem();	//��ȡ���ݺ���
	void putElem(const T &x);  //�������ݺ���
};

//����ʵ�ָ���Ա������
template <class T>	//ȱʡ���캯����ʵ�� 
Store<T>::Store(): haveValue(false) { }

template <class T>                //��ȡ���ݺ�����ʵ��
T &Store<T>::getElem() {
	if (!haveValue) {	//�����ͼ��ȡδ��ʼ�������ݣ�����ֹ����
		cout << "No item present!" << endl;
		exit(1);	//ʹ������ȫ�˳������ص�����ϵͳ��
		//������������ʾ������ֹ��ԭ�򣬿��Ա�����ϵͳ����
	}
	return item;    // ����item�д�ŵ����� 
}

template <class T>	//�������ݺ�����ʵ�� 
void Store<T>::putElem(const T &x) {
	haveValue = true;	// ��haveValue ��Ϊtrue����ʾitem���Ѵ�����ֵ
	item = x;			// ��xֵ����item
}

int main() {
	Store<int> s1, s2;	//��������Store<int>������������ݳ�ԱitemΪint����
	s1.putElem(3);	//�����S1�д������ݣ���ʼ������S1��
	s2.putElem(-7);	//�����S2�д������ݣ���ʼ������S2��
	cout << s1.getElem() << "  " << s2.getElem() << endl;	//�������S1��S2�����ݳ�Ա

	Student g = { 1000, 23 };	//����Student���ͽṹ�������ͬʱ���Գ�ֵ
	Store<Student> s3;	//����Store<Student>�����s3���������ݳ�ԱitemΪStudent����
	s3.putElem(g); //�����D�д������ݣ���ʼ������D��
	cout << "The student id is " << s3.getElem().id << endl;	//�������s3�����ݳ�Ա

	Store<double> d;	//����Store<double>�����s4���������ݳ�ԱitemΪdouble����
	cout << "Retrieving object d... ";
	cout << d.getElem() << endl;  //�������D�����ݳ�Ա
	//����dδ����ʼ��,��ִ�к���D.getElement()�����е��³�����ֹ

	return 0;
}
