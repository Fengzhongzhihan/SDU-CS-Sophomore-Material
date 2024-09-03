#include <iostream>

// 递归终止版本
void print() { }

// 打印单个参数的版本
template <typename T>
void print(const T &t) {
  std::cout << t << std::endl;
}

// 打印多个参数的版本
template <typename T, typename... TypeArgs>
void print(const T &t, const TypeArgs&... args) {
  std::cout << t << std::endl;
  print(args...); // 递归调用、参数包展开
}

int main() {
  print(3, 4.5, "hello world!");
  return 0;
}
