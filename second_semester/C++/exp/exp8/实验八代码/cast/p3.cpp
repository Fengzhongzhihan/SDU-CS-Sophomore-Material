//dynamic_cast示例
#include <iostream>
#include <string> 
using namespace std; 
class Base{ //有虚函数，因此是多态基类
	public:
		virtual ~Base() { }
};

class Derived:public Base {	};

int main(){
	Base b, *pb; 
	Derived d, *pd;

	pb=pd;   // 父指子是自然的，安全的，可隐式转换。
	 
	pd = static_cast<Derived*> ( &b);  //父类对象地址转为子类指针（子指针指向父对象），不安全，需用static_cast显式转换，能转换。 
	if( pd == NULL) // 
		cout << "static_cast failed!" << endl; //如果不成功，显示。 
		
	pd = dynamic_cast<Derived*> ( &b); //父类对象地址转为子类地址指针（子指针指向父对象） ，用dynamic_cast
	if( pd == NULL)   //对于不安全的指针转换，转换结果返回NULL指针
		cout << "unsafe dynamic_cast_1" << endl;	//如果不成功，显示。
		
	pd = dynamic_cast<Derived*> ( &d); //子类对象地址转为子类地址指针 ，用dynamic_cast
	if( pd == NULL)	 
		cout << "unsafe dynamic_cast_2" << endl; //上面转换是安全的，所以不会显示
	return 0;
}

