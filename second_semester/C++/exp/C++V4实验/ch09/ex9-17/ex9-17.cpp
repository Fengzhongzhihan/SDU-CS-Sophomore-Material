#include <iostream>
using namespace std;

template <class T>
int seqSearch(T list[], int n, T key)
{
	for(int i=0;i < n;i++)
		if (list[i] == key)
			return i;            
		return -1;                 
}

int main()
{
	int i, n;
	
	int data1[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
	cout << "��������ҵ�����(1~20)��";
	cin >> n;
	cout << "����Ϊ��" << endl;
	for(i=0;i<20;i++)
		cout << data1[i] << "  ";
	cout << endl;
	i = seqSearch ( data1 , 20 , n );
	if (i<0)
		cout << "û���ҵ�����" << n << endl;
	else
		cout << n << "�ǵ�" << i+1 << "������" << endl;
	return 0;
}
