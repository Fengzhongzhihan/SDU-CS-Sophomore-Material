//p20.1.3.cpp,dynamic_castʾ��
#include <iostream>
#include <string> 
using namespace std; 
class Base{ //���麯��������Ƕ�̬����
	public:
		virtual ~Base() { }
};

class Derived:public Base {	};

int main(){
	Base b; Derived d; Derived * pd;
	pd = reinterpret_cast<Derived*> ( &b);  //����ȫ������ת���� 
	if( pd == NULL) //�˴�pd����ΪNULL��reinterpret_cast����鰲ȫ�ԣ����ǽ���ת��
	      cout << "unsafe reinterpret_cast" << endl; //����ִ��

		
	pd = dynamic_cast<Derived*> ( &b); //���飬����ȫ 
	if( pd == NULL) //�������NULL����Ϊ &b����ָ����������󣬴�ת������ȫ
		cout << "unsafe dynamic_cast1" << endl;	//��ִ��
		
	pd = dynamic_cast<Derived*> ( &d); //��ȫ��ת��
	if( pd == NULL)	//�˴�pd����ΪNULL
		cout << "unsafe dynamic_cast2" << endl; //����ִ��
		
	return 0;
}

