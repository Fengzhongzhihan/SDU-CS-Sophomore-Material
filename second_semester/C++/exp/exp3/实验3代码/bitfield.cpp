//λ��bit_fields��ͬ���͵Ŀ��Թ������ͣ���˳�����б˴˲����ǣ�Struct��class)�����Ԫ�ض��롣 

#include <iostream>
using namespace std;
int fun(){//c++�����п��Զ����࣬���Զ������еķ������������ٶ��庯���� 
	class B  //�������������������ں���
	{ 
	public:
		 int size(){
	 		return sizeof(B);
	 	}
	private:
		char a:2; //ֵ��Χ0-3��1�ֽ��е�2λ 
		char b:3; //ֵ��Χ0-7��1�ֽ��е�3λ����a����һ���ֽ� 
		char c:4; //ֵ��Χ0-15,1�ֽ��е�4λ����>8����Ҫ�ӵ�2���ֽڿ�ʼ 	  
		int  d:6;  //ֵ��Χ0-63��4���ֽ��е�6λ 
		int  e:2;  //ֵ��Χ0-3,4���ֽ��е�2λ����d����һ�� int �ռ䡣�����Ͽ���6���ֽڣ���ǰ2��char����Ҫ�ͺ����int ���룬����ϵͳ�����ܿռ���4*2=8���ֽڡ� 
	} ;

	return B().size();// �����ڲ���Ķ����еķ���size()�ķ���ֵ; 
	                // ��װ����ԭ�й��ܰ������γ��µĹ�����(����)������ԭ�л����ϸ�������µĹ��ܡ��������������ˡ� 
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
 	cout<<fun()<<endl;   //�����ڲ�ͬ 
 }
