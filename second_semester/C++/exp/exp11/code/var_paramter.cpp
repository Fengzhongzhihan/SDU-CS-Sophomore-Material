#include<iostream>
template <typename T>  
void print(T &t) { //另一函数
  std::cout<<t<<std::endl;
}   

template <typename T, typename... TypeArgs>  
void func(const T &t, const TypeArgs&... args) { 
  std::cout<<sizeof...(args)<<std::endl; //参数个数
  (print(args),...);  //折叠表达式，对args的每个参数调用print
}

int main(){
	func(3, 4.5, "hello world!");
	return 0;
} 

