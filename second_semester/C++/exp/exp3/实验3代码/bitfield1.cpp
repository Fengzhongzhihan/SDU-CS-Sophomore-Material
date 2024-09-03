//位域，同类型的可以公用；Struct（class)按最大元素对齐。 
#include <iostream>
using namespace std;
int fun(){//c++函数中可以定义类，可以定义类中的方法。但函数中不能再定义函数。 
	class B
	{ 
	public:
		 int size(){
	 		return sizeof(B);
	 	}
	private:
	// 1byte = 8bit
		char a:2; //值范围0-3，1字节中的2位 
		char b:3; //值范围0-7，1字节中的3位，与a共用一个字节 
		char c:4; //值范围0-15,1字节中的4位，因>8，需要从第2个字节开始, 2字节8位	  
		int  d:6; //值范围0-63，4个字节中的6位 
		int  e:2; //值范围0-3,4个字节中的2位，与d共用一个 int 空间。表面上看是6个字节，但前2个char，需要和后面的int 对齐，所以系统分配总空间是4*2=8个字节。 
	} ; 
	/*int ff(){   //函数中不允许再定义函数 
	 		cout<<sizeof(B)<<endl; 
	 		return sizeof(B);
	 }*/
	 
	return B().size(); //sizeof(B) ;
	   //包装作用，即将原有功能包裹后形成新的功能体(函数)，可在原有基础上改造加入新的功能。旧体的作用域变了。 
}
 int main(){
 	//B b; //错。函数中类的作用域仅限于函数。 
 	cout<<fun()<<endl; 
 }
