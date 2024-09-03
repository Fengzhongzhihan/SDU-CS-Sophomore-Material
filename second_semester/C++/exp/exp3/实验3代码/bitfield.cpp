//位域bit_fields，同类型的可以公用类型，但顺序排列彼此不覆盖；Struct（class)按最大元素对齐。 

#include <iostream>
using namespace std;
int fun(){//c++函数中可以定义类，可以定义类中的方法。但不能再定义函数。 
	class B  //函数中类的作用域仅限于函数
	{ 
	public:
		 int size(){
	 		return sizeof(B);
	 	}
	private:
		char a:2; //值范围0-3，1字节中的2位 
		char b:3; //值范围0-7，1字节中的3位，与a共用一个字节 
		char c:4; //值范围0-15,1字节中的4位，因>8，需要从第2个字节开始 	  
		int  d:6;  //值范围0-63，4个字节中的6位 
		int  e:2;  //值范围0-3,4个字节中的2位，与d共用一个 int 空间。表面上看是6个字节，但前2个char，需要和后面的int 对齐，所以系统分配总空间是4*2=8个字节。 
	} ;

	return B().size();// 返回内部类的对象中的方法size()的返回值; 
	                // 包装即将原有功能包裹后形成新的功能体(函数)，可在原有基础上改造加入新的功能。旧体的作用域变了。 
}

class BB 
	{ 
	public:
		 int size(){
	 		return sizeof(BB);
	 	}
	private:
		char a:2;
		char b:3;
		char c:4;
		int  d:6;
		int  e:2;
} ;

 int main(){
 	BB b; 
 	cout<<b.size()<<endl; 
 	cout<<fun()<<endl;   //生存期不同 
 }
