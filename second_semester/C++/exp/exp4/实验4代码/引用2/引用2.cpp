//�������÷��ʵĲ��� 
#include <iostream>
using namespace std;
class B{
	public:
		B(int j):j(j){
		}
		private:
		int j;
};

class A{
	public:
		A(int y){i=y;
		}
		void show(A& a){
			cout<<"i="<<i<<" a.i="<<a.i<<endl;  //ֱ��ʹ��ͬ������е�private���ԣ�a.i�� 
		}
	void fun1(const A& a){
		i=a.i;  //a.i��private���ԣ�ͬ������private���Կ���ֱ�ӷ��ʡ�
		cout<<a.i<<endl; 
		//a.i=3; //���ͨ������ֱ�Ӹ�������������ԣ��ǳ�Σ�գ�Ӧ����const����. 
		}
	/*void fun2( B& b){
		i=b.j;  //��ͬ��Ķ����private���Բ���ֱ�ӷ��ʣ� 
	}*/
	private:
	int i;
}; 

int main(){
	
	A a1(1),a2(2);
	a1.show(a2);
	a2.show(a1);
	//cout<<"a1.i=:"<<a1.i<<endl; //�Ƿ����� 

	a1.fun1(a2);     //Ϊʲô��a2���ԣ�
	a1.show(a2);
	a2.show(a1);
	
	/*B b(3);
	a1.fun2(b);*/  //Ϊʲô��b�����ԣ�
	
	return 0;
} 
