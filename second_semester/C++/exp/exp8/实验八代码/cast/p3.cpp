//dynamic_castʾ��
#include <iostream>
#include <string> 
using namespace std; 
class Base{ //���麯��������Ƕ�̬����
	public:
		virtual ~Base() { }
};

class Derived:public Base {	};

int main(){
	Base b, *pb; 
	Derived d, *pd;

	pb=pd;   // ��ָ������Ȼ�ģ���ȫ�ģ�����ʽת����
	 
	pd = static_cast<Derived*> ( &b);  //��������ַתΪ����ָ�루��ָ��ָ�򸸶��󣩣�����ȫ������static_cast��ʽת������ת���� 
	if( pd == NULL) // 
		cout << "static_cast failed!" << endl; //������ɹ�����ʾ�� 
		
	pd = dynamic_cast<Derived*> ( &b); //��������ַתΪ�����ַָ�루��ָ��ָ�򸸶��� ����dynamic_cast
	if( pd == NULL)   //���ڲ���ȫ��ָ��ת����ת���������NULLָ��
		cout << "unsafe dynamic_cast_1" << endl;	//������ɹ�����ʾ��
		
	pd = dynamic_cast<Derived*> ( &d); //��������ַתΪ�����ַָ�� ����dynamic_cast
	if( pd == NULL)	 
		cout << "unsafe dynamic_cast_2" << endl; //����ת���ǰ�ȫ�ģ����Բ�����ʾ
	return 0;
}

