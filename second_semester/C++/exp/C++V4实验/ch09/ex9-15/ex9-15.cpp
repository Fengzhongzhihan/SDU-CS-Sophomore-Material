#include <iostream>
using namespace std;

// ��������������x��y��ֵ
template <class T>
void swapData (T &x, T &y)
{
	T temp;
	
	temp = x;
	x = y;
	y = temp;
}

// �����ݷ�������A��n��Ԫ�ؽ�������
template <class T>
void BubbleSort(T a[], int n)
{
	int i,j;             
	int lastExchangeIndex; 
                //���ڼ�¼ÿ�˱����������һ��Ԫ���н�С���±�
	i = n-1;      // i����һ����������򽻻���Ԫ��֮����±�
	
	while (i > 0) 
     //����������̣�ֱ�����һ������û�н������������Ѵ�n-1��
	{
		lastExchangeIndex = 0; 
                //ÿһ�˿�ʼʱ�����ý�����־Ϊ0��δ������
		for (j = 0; j < i; j++)  //ÿһ�˶�Ԫ��a[0]..a[i]���бȽϺͽ���
			if (a[j+1] > a[j])   //���Ԫ��a[j+1] < a[j]������֮
			{ 
				swapData(a[j],a[j+1]);
				lastExchangeIndex = j; 
                           //��¼��������һ��Ԫ���н�С���±�
			}
			
			// ��i����Ϊ���˱����������һ��Ԫ���н�С���±�
			i = lastExchangeIndex;
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
	BubbleSort(data1, 20);
	cout << "���������ݣ�" << endl;
	for(i=0;i<20;i++)
		cout << data1[i] << "  ";
	cout << endl;
	return 0;
}
