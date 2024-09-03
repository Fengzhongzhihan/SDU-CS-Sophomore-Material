//10_20.cpp
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
	int iarray[] = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
	vector<int> ivector(iarray, iarray + sizeof(iarray) / sizeof(int));
	int iarray1[] = { 6, 6 };
	vector<int> ivector1(iarray1, iarray1 + sizeof(iarray1) / sizeof(int));
	int iarray2[] = { 5, 6 };
	vector<int> ivector2(iarray2, iarray2 + sizeof(iarray2) / sizeof(int));
	int iarray3[] = { 0, 1, 2, 3, 4, 5, 7, 7, 7, 9, 7 };
	vector<int> ivector3(iarray3, iarray3 + sizeof(iarray3) / sizeof(int));

	//�ҳ�ivector֮������Ԫ��ֵ��ȵĵ�һ��Ԫ��
	cout << *adjacent_find(ivector.begin(), ivector.end()) << endl; 

	//�ҳ�ivector֮��С��7��Ԫ�ظ���
	cout << count_if(ivector.begin(), ivector.end(), bind2nd(less<int>(), 7)) << endl; 

	//�ҳ�ivector֮�д���2�ĵ�һ��Ԫ������λ�õ�Ԫ��
	cout <<  *find_if(ivector.begin(), ivector.end(), bind2nd(greater<int>(), 2)) << endl; 
	
	//������ivector2��ivector�г��ֵ����λ��Ԫ��
	cout << *search(ivector.begin(), ivector.end(), 
		ivector2.begin(), ivector2.end()) << endl;

	//������������3��6�����λ��Ԫ��
	cout << *search_n(ivector.begin(), ivector.end(), 3, 6, equal_to<int>()) << endl;
	
	//�ж���������ivector��ivector3��ȷ�(0Ϊ�٣�1Ϊ��)
	cout << equal(ivector.begin(), ivector.end(), ivector3.begin()) << endl;

	//��������ivector3��ivector�в�ƥ����λ��
	pair<vector<int>::iterator, vector<int>::iterator> result = 
		mismatch(ivector.begin(), ivector.end(), ivector3.begin());
	cout << result.first - ivector.begin() << endl; 
	return 0;
}
