#include <fstream>
#include <iostream>
using namespace std;

int main()  
{
    ofstream file1("test.txt",ios::app);
    file1 << "�ѳɹ�����ַ���";
	file1.close();
	char ch;
    ifstream file2("test.txt");
	while (file2.get(ch))
		cout << ch;
	file2.close();
	return 0;
}
