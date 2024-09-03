//p20.1.2.cpp reinterpret_cast示例；请用32位编译器编译，否则出错 
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
	int & r = reinterpret_cast<int&>(a); //强行让 r引用a，实际引用a.i 
	r = 200;	//把 a.i变成了 200
	cout << a.i << "," << a.j << endl;	//输出200,100
	int n = 300;
	A * pa = reinterpret_cast<A*> ( & n); //强行让 pa指向 n（pa->i指n) 
	pa->i = 400;	// n变成 400
	pa->j = 500;	//此条语句不安全，很可能导致程序崩溃
	cout << n << endl;	// 输出 400
	long long la = 0x12345678abcdLL;  //vc6中用 _int64 la = 0x12345678abcd; la占8个字节
	cout<<sizeof(la)<<"  "<<sizeof(pa)<<endl; //vc6等32位编译器中pa是4个字节，其他64位编译器pa是8个字节 
	pa = reinterpret_cast<A*>(la); // la太长，只取低32位0x5678abcd拷贝给pa;如果pa是8个字节，则此句非法。
	unsigned int u = reinterpret_cast<unsigned int>(pa); //pa逐个比特拷贝到u
	cout << hex << u << endl;	//输出 5678abcd
	typedef void (* PF1) (int); typedef int (* PF2) (int,char *); PF1 pf1;	PF2 pf2;
	pf2 = reinterpret_cast<PF2>(pf1); //两个不同类型的函数指针之间可以互相转换
}

