//10_26.cpp
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

//���������������p��n����ֵ���򣬽����ͨ�����������result���
template <class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
	//ͨ�����������p���������ݴ�����������s��
	vector<typename iterator_traits<InputIterator>::value_type> s(first, last);
	//��s��������sort�����Ĳ���������������ʵ�����
	sort(s.begin(), s.end());
	//��s����ͨ��������������
	copy(s.begin(), s.end(), result);
}

int main() {
	//��s�����������������
	double a[5] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
	mySort(a, a + 5, ostream_iterator<double>(cout, " "));
	cout << endl;
	//�ӱ�׼����������ɸ��������������Ľ�����
	mySort(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
