#include <iostream>
#include <cmath>
using namespace std;

int prime(int i); 		//��һ�����Ƿ��������ĺ���

int main()
{
	int i;
	cout << "������һ��������";
	cin >> i;
	if (prime(i))
		cout << i << "������." << endl;
	else
		cout << i << "��������." << endl;
	return 0;
}

int prime(int i)
{
	int j,k,flag;
	flag = 1;
	k = sqrt(1.0*i);
	for (j = 2; j <= k; j++)
	{
		if(i%j == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
	
}
