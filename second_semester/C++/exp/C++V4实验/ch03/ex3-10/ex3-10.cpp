#include <iostream>
#include <cmath>
using namespace std;

int fn1(int i,int j);  //�����Լ���ĺ���

int main()
{
	int i,j,x,y;
	cout << "������һ����������";
	cin >> i ;
	cout << "��������һ����������";
	cin >> j ;
	
	x = fn1(i,j);
	y = i * j / x;
	cout << i << "��" << j << "�����Լ���ǣ�" << x << endl;
	cout << i << "��" << j << "����С�������ǣ�" << y << endl;
	return 0;
}

int fn1(int i, int j)
{
	int temp;
	if (i < j)
	{
		temp = i;
		i = j;
		j =temp;
	}
	while(j != 0)
	{
		temp = i % j;
		i = j;
		j = temp;
	}
	return i;
}
