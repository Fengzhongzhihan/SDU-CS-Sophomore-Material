#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> INTVECTOR;
int main()
{
	INTVECTOR s;
	for (int i = 0; i < 5; i++) {
		s.push_back(i);
		cout << "����һ��Ԫ�غ�����������������s����" << s.capacity() << "��Ԫ��" << endl;
	}
	return 0;
}
