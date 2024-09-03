#include <iostream>
using namespace std;

// ���۰���ҷ�������Ԫ�س��������е�����list�в���ֵΪkey��Ԫ��
template <class T>
int binarySearch(T list[], int n, T key)
{
   int mid, low, high;
   T midvalue;
   low=0;
   high=n-1;
   while (low <= high)   // low <= high��ʾ����������δ������
   {
      mid = (low+high)/2;     // ���м�Ԫ�ص��±�
      midvalue = list[mid];   // ȡ���м�Ԫ�ص�ֵ
      if (key == midvalue)    
         return mid;          // ���ҵ�,�����±�
      else if (key < midvalue)
         high = mid-1;  
              // ��key < midvalue�����ҷ�Χ��С�������ǰһ��
      else
         low = mid+1;   // ���򽫲��ҷ�Χ��С������ĺ�һ��
   }
   return -1;           // û���ҵ�����-1
}

int main()
{
	int i, n;
	
	int data1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	cout << "��������ҵ�����(1~20)��";
	cin >> n;
	cout << "����Ϊ��" << endl;
	for(i=0;i<20;i++)
		cout << data1[i] << "  ";
	cout << endl;
	i = binarySearch ( data1 , 20 , n );
	if (i<0)
		cout << "û���ҵ�����" << n << endl;
	else
		cout << n << "�ǵ�" << i+1 << "������" << endl;
	return 0;
}
