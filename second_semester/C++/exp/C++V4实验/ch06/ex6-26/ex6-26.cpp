#include <iostream>
using namespace std;
void move (int *matrix ,int n)
{
	int i, j, k;
	for(i=0; i<n; i++)
		for (j=0; j<i; j++)
		{
			k = *(matrix + i*n + j);
			*(matrix + i*n + j) = *(matrix + j*n + i);
			*(matrix + j*n + i) = k;
		}
}
int main()
{
	int n, i, j;
	int *p;
	cout << "�����������С�������";
	cin >> n;
	p = new int[n*n];
	cout << "��������Ԫ��" << endl;
	for(i=0; i<n; i++)
		for (j=0; j<n; j++)
		{
			cout << "��" << i+1 << "�е�" << j+1
			<<"��Ԫ��Ϊ��";
			cin >> p[i*n + j];
		}
	cout << "����ľ����Ϊ��" << endl;
	for(i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			cout << p[i*n + j] << " ";
		cout << endl;
	}
	move(p, n);
	cout << "ת�ú�ľ����Ϊ��" << endl;
	for(i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			cout << p[i*n + j] << " ";
		cout << endl;
	}
	return 0;
}