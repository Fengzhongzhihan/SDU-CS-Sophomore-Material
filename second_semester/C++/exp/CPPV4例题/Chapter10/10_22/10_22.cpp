//10_22.cpp
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
using namespace std;

int main() {
	int iarray[] = { 26, 17, 15, 22, 23, 33, 32, 40 };
	vector<int> ivector(iarray, iarray + sizeof(iarray) / sizeof(int));
	
	// ���Ҳ������һ�����ֵԪ�ؼ���λ��
	vector<int>::iterator p = max_element(ivector.begin(), ivector.end());
	int n = p  - ivector.begin();
	cout << "max element: " << *p << " found at " << n << endl;

	//�ֲ����򲢸��Ƶ���
	vector<int> ivector1(5);
	partial_sort_copy(ivector.begin(), ivector.end(), ivector1.begin(), ivector1.end());
	copy(ivector1.begin(), ivector1.end(), ostream_iterator<int>(cout, " "));
	cout << endl; 

	//����ȱʡΪ������
	sort(ivector.begin(), ivector.end());
	copy(ivector.begin(), ivector.end(), ostream_iterator<int>(cout, " "));
	cout << endl; 

	// ����С�ڵ���24�ʹ��ڵ���24��Ԫ�ص�λ��
	cout << *lower_bound(ivector.begin(), ivector.end(), 24) << endl;
	cout << *upper_bound(ivector.begin(), ivector.end(), 24) << endl;

	//�����������䣬�����ö��ֲ��ҷ���Ѱ��ĳ��Ԫ��
    cout << binary_search(ivector.begin(), ivector.end(), 33) << endl;

	//�ϲ���������ivector��ivector1����������ŵ�ivector2��
	vector<int> ivector2(13);
	merge(ivector.begin(), ivector.end(), ivector1.begin(), ivector1.end(), ivector2.begin());
	copy(ivector2.begin(), ivector2.end(), ostream_iterator<int>(cout, " "));
	cout << endl; 

	//��С��*(ivector.begin()+5)��Ԫ�ط����ڸ�Ԫ��֮��
	//�������ڸ�Ԫ��֮�ҡ�����֤ά��ԭ�е����λ��
	nth_element(ivector2.begin(), ivector2.begin() + 5, ivector2.end());
	copy(ivector2.begin(), ivector2.end(), ostream_iterator<int>(cout, " "));
	cout << endl; 

	//���򣬲�����ԭ�����λ��
	stable_sort(ivector2.begin(), ivector2.end());
	copy(ivector2.begin(), ivector2.end(), ostream_iterator<int>(cout, " "));
	cout << endl; 

	//�ϲ������������У�Ȼ��͵��滻
	int iarray3[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	vector<int> ivector3(iarray3, iarray3 + sizeof(iarray3) / sizeof(int));
	inplace_merge(ivector3.begin(), ivector3.begin() + 4, ivector3.end());
	copy(ivector3.begin(), ivector3.end(), ostream_iterator<int>(cout, " "));  
	cout<<endl; 
	
	//���ֵ�˳��Ƚ�����ivector3��ivector4
	int iarray4[] = { 1, 3, 5, 7, 1, 5, 9, 3 };
	vector<int> ivector4(iarray4, iarray4 + sizeof(iarray4) / sizeof(int));
	cout<< lexicographical_compare(ivector3.begin(), ivector3.end(), ivector4.begin(), ivector4.end()) << endl;
	return 0;
}
