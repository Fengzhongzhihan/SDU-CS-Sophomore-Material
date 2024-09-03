//10_21.cpp
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
using namespace std;

class evenByTwo {
private:
	int x;
public:
	evenByTwo() : x(0) { }
	int operator () () { return x += 2; }
};

int main() {
	int iarray1[]= { 0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 7, 8 };
	int iarray2[] = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
	vector<int> ivector1(iarray1, iarray1 + sizeof(iarray1) / sizeof(int));
	vector<int> ivector2(iarray2, iarray2 + sizeof(iarray2) / sizeof(int));
	vector<int> ivector3(2); 
	ostream_iterator<int> output(cout, " ");  //�����������������������
	
	//��������ivector3���䣬ÿ��Ԫ������-1
	fill(ivector3.begin(), ivector3.end(), -1);
	copy(ivector3.begin(), ivector3.end(), output);	// ʹ��copy�������
	cout << endl;

	//��������ivector3���䣬��ÿһ��Ԫ�ؽ���evenByTwo����
	generate(ivector3.begin(), ivector3.end(), evenByTwo());
	copy(ivector3.begin(), ivector3.end(), output);
	cout << endl; 

	//��ɾ��Ԫ��6���ivector2����������һ������ivector4֮��
	vector<int> ivector4;
	remove_copy(ivector2.begin(), ivector2.end(), back_inserter(ivector4), 6);
	copy(ivector4.begin(), ivector4.end(), output);
	cout << endl; 

	//ɾ��С��6��Ԫ��
	ivector2.erase(remove_if(ivector2.begin(), ivector2.end(), bind2nd(less<int>(), 6)), ivector2.end());
	copy(ivector2.begin(), ivector2.end(), output);
	cout << endl; 
	
	//�����е�Ԫ��ֵ6����ΪԪ��ֵ3
	replace(ivector2.begin(), ivector2.end(), 6, 3);
	copy(ivector2.begin(), ivector2.end(), output);
	cout << endl; 
	
	//��������ÿһ��Ԫ��
	reverse(ivector2.begin(), ivector2.end());
	copy(ivector2.begin(), ivector2.end(), output);
	cout << endl; 
	
	//��ת������Ԫ�أ�[first, middle),  ��[middle, end)�����ֱ�����
	rotate_copy(ivector2.begin(), ivector2.begin() + 3, ivector2.end(), output);
	cout << endl;
	return 0;
}
