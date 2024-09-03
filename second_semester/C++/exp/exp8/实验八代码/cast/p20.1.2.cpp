//p20.1.2.cpp reinterpret_castʾ��������32λ���������룬������� 
#include <iostream> 
using namespace std; 
class A{
	public:
		int i;
		int j;
		A(int n):i(n),j(n) { }
};
int main(){
	A a(100);
	int & r = reinterpret_cast<int&>(a); //ǿ���� r����a��ʵ������a.i 
	r = 200;	//�� a.i����� 200
	cout << a.i << "," << a.j << endl;	//���200,100
	int n = 300;
	A * pa = reinterpret_cast<A*> ( & n); //ǿ���� paָ�� n��pa->iָn) 
	pa->i = 400;	// n��� 400
	pa->j = 500;	//������䲻��ȫ���ܿ��ܵ��³������
	cout << n << endl;	// ��� 400
	long long la = 0x12345678abcdLL;  //vc6���� _int64 la = 0x12345678abcd; laռ8���ֽ�
	cout<<sizeof(la)<<"  "<<sizeof(pa)<<endl; //vc6��32λ��������pa��4���ֽڣ�����64λ������pa��8���ֽ� 
	pa = reinterpret_cast<A*>(la); // la̫����ֻȡ��32λ0x5678abcd������pa;���pa��8���ֽڣ���˾�Ƿ���
	unsigned int u = reinterpret_cast<unsigned int>(pa); //pa������ؿ�����u
	cout << hex << u << endl;	//��� 5678abcd
	typedef void (* PF1) (int); typedef int (* PF2) (int,char *); PF1 pf1;	PF2 pf2;
	pf2 = reinterpret_cast<PF2>(pf1); //������ͬ���͵ĺ���ָ��֮����Ի���ת��
}

