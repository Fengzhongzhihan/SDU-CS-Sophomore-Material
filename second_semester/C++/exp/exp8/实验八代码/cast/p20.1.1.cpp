//static_castʾ����p20.1.1.cpp
#include <iostream> 
using namespace std; 
class A{
	public:
		operator int()	{ return 1; }   //int����ת���������� 
		operator char * (){ return NULL; }   //char*����ת����������
};

int main(){
	A a;
	int n; 
	char * p = "New Dragon Inn";
	n = static_cast<int>(3.14);	// n ��ֵ��Ϊ 3
	n = static_cast<int>(a);	//����a.operator int, n��ֵ��Ϊ 1
	p = static_cast<char*>(a);	//����a.operator int *,p��ֵ��ΪNULL
	
	//n = static_cast<int> (p);	//�������static_cast���ܽ�ָ��ת��������
	p = static_cast<char*>(n);	//�������static_cast���ܽ�����ת����ָ��
	return 0;
}

