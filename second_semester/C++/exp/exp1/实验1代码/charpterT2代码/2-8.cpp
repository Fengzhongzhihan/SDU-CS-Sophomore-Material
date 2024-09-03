#include <iostream>
using namespace std;
int main()
{
   cout << 'A'<< ' '<<'a'<<endl;     //输出普通字符
   cout << "one\ttwo\tthree\n";    //使用水平制表符
   cout << "123\b\b45\n";             //使用退格符
   cout << "Alert\a\n";                   //使用响铃键
   return 0;
}
