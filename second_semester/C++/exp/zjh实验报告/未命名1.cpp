// ���쾲̬��Ա�����ƹ��캯�� ������ָ�롢���á�
// ��һ������û���ͷţ������ڴ�й©�� 

#include <iostream>
using namespace std;

class Object   //C++��û����java�еĸ���Object���˴�Ϊ�Լ������һ���ࡣ
{  
  public:
	static int count;  //��̬��Ա��ͳ�ƶ���ĸ�����
	
	Object(){            //���췽�� 
		count++;         //ͳ�Ƹ����ۼơ� 
		id=count;        //������ 
		cout<<"in Constructor. this:"<<this<<", id:"<<id<<endl;  //�����ã����ÿ��һ�������ָ��ͱ��

	} 
	
	Object(const Object &ob){   //���ƹ��캯��������Լ�д���ƹ��캯�������Ƴ�Ա��������Ҫ�Լ���ɡ�Ĭ��ϵͳ�Զ����� 
		count++;
		id=count;        // id����Ҫ���ƣ������ۼƱ�� 
		cout<<"in Copy constructor:Object(Object &ob) this:"<<this<<", ob:"<<&ob<<", id:"<<id<<endl; //�������ָ��ͱ����ƶ���ָ�뼰����id 

	}

	~Object(){
		cout<<"Remove:"<<this<<", id:"<<this->id<<endl;  //�����ɾ���Ķ���ָ��ͱ�� 
		count--;
	}

	int getId(){
		return id;
	}
	
	private:
	int id;  // ��Ա��������������š�

};

int Object::count=0;  // ��̬��Ա�������ʼ��

void exec()
{
   Object *a=new Object, b(*new Object(*a));// ��ע�ʹ˾�ĺ��� 
 
   cout<<"In exec:after(a,b),count="<<Object::count<<endl;
   cout<<"exec:a id:"<<a->getId()<<endl;
   cout<<"exec:b id:"<<b.getId()<<endl;
   
   Object c,&cc(c);
   cout<<"In exec:after c, count="<<Object::count<<endl;
   
   delete a;
   cout<<"after delete a, count="<<Object::count<<endl;
   
  
}

int main()
{
	exec();

	cout<<"return main, after exec, count:"<<Object::count<<endl;   
	
	return 0;           
}
