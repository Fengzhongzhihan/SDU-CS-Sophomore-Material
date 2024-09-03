//关于引用访问的测试 
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
			cout<<"i="<<i<<" a.i="<<a.i<<endl;  //直接使用同类对象中的private属性，a.i。 
		}
	void fun1(const A& a){
		i=a.i;  //a.i是private属性，同类对象的private属性可以直接访问。
		cout<<a.i<<endl; 
		//a.i=3; //如果通过引用直接改其他对象的属性，非常危险，应该用const保护. 
		}
	/*void fun2( B& b){
		i=b.j;  //不同类的对象的private属性不能直接访问！ 
	}*/
	private:
	int i;
}; 

int main(){
	
	A a1(1),a2(2);
	a1.show(a2);
	a2.show(a1);
	//cout<<"a1.i=:"<<a1.i<<endl; //非法访问 

	a1.fun1(a2);     //为什么用a2可以？
	a1.show(a2);
	a2.show(a1);
	
	/*B b(3);
	a1.fun2(b);*/  //为什么用b不可以？
	
	return 0;
} 
