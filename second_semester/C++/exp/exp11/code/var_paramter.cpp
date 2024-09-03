#include<iostream>
template <typename T>  
void print(T &t) { //��һ����
  std::cout<<t<<std::endl;
}   

template <typename T, typename... TypeArgs>  
void func(const T &t, const TypeArgs&... args) { 
  std::cout<<sizeof...(args)<<std::endl; //��������
  (print(args),...);  //�۵����ʽ����args��ÿ����������print
}

int main(){
	func(3, 4.5, "hello world!");
	return 0;
} 

