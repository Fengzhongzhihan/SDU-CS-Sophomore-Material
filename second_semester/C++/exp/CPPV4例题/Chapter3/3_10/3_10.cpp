//3_10.cpp
#include <iostream>
using namespace std;

//��src���������һ�������ƶ���dest����
void move(char src, char dest) { 
	cout << src << " --> " << dest << endl;
}

//��n�����Ӵ�src���ƶ���dest�룬��medium����Ϊ�н�
void hanoi(int n, char src, char medium, char dest) {
	if (n == 1)
		move(src, dest);
	else {
		hanoi(n - 1, src, dest, medium);
		move(src, dest);
		hanoi(n - 1, medium, src, dest);
	}
}

int main() {
	int m;
	cout << "Enter the number of diskes: ";
	cin >> m;
	cout << "the steps to moving " << m << " diskes:" << endl;
	hanoi(m,'A','B','C');
	return 0;
}
