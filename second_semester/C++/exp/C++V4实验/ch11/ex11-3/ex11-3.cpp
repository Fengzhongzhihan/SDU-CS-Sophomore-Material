#include <fstream>
using namespace std;

int main()  
{
	ofstream file1("test.txt");
	file1 << "�ѳɹ�д���ļ���";
	file1.close();
	return 0;
}
