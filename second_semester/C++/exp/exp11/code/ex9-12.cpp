#include <iostream>
using namespace std;

// ��������������x��y��ֵ
template <class T>
void swapData(T &x, T &y)
{
	T temp;
	
	temp = x;
	x = y;
	y = temp;
}

// ��ѡ�񷨶�����A��n��Ԫ�ؽ�������
template <class T>
void selectSort(T a[], int n)
{
	int smallIndex;    //ÿ������ѡ������СԪ��֮�±�
	int i, j;
	
	// sort a[0]..a[n-2], and a[n-1] is in place
	for (i = 0; i < n-1; i++) 
	{
		smallIndex = i;    //��СԪ��֮�±��ֵ��Ϊi
		// ��Ԫ��a[i+1]..a[n-1]������Ƚ��Գ���Сֵ
		for (j = i+1; j < n; j++) 
			// smallIndexʼ�ռ�¼��ǰ�ҵ�����Сֵ���±�
			if (a[j] < a[smallIndex])
				smallIndex = j;
			// ����һ���ҵ�����СԪ����a[i]����
			swapData(a[i], a[smallIndex]);
			//�������
			for(int k=0;k<n;k++)
				cout << a[k] << "  ";
			cout << endl;
			//�������	
			
	}
}

int main()
{
	int i;
	
	int data1[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
	cout << "����ǰ�����ݣ�" << endl;
	for(i=0;i<20;i++)
		cout << data1[i] << "  ";
	cout << endl;
	cout << "��ʼ����..." << endl;
	selectSort(data1, 20);
	cout << "���������ݣ�" << endl;
	for(i=0;i<20;i++)
		cout << data1[i] << "  ";
	cout << endl;
	return 0;
}
