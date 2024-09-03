#include<iostream>
using namespace std;

class A{
	public:
	virtual ~A(){
	};
};
class B:public A{
	
};
class C:public A{
	private:
		int i;
};

int main(){
	A a,*pa;
	pa=&a;
	
	C c1;
	B b1,*bp;
	bp=dynamic_cast<B*>(pa);  //转换错，bp=0 
	cout<<bp<<endl;   
	bp=dynamic_cast<B*>(&c1); //转换错，bp=0 
	cout<<bp<<endl;
	
	pa=&c1;
	bp=dynamic_cast<B*>(pa);  //转换错，bp=0 
	cout<<bp<<endl;   
	
	pa=&b1;
	bp=dynamic_cast<B*>(pa);  //转只有原来是b1的对象，dynamic_case转换后才是对的。 
	cout<<bp<<endl;   
}
