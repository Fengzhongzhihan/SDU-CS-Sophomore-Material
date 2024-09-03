#include <fstream>
#include <iostream>
using namespace std;

int main()  
{
	ofstream file1("test.txt");
	file1 << "已成功写入文件！";
	file1.close();
    file1.open("test.txt",ios::app);
    file1 << "已成功添加字符！";
	file1.close();
	char ch;
    ifstream file2("test.txt");
	while (file2.get(ch))
		cout << ch;
	file2.close();
	return 0;
}
