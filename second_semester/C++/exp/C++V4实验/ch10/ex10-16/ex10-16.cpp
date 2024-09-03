#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template<class InputIterator, class OutputIterator>
void mySort0(InputIterator first, InputIterator last, OutputIterator result,
		output_iterator_tag) {
	//ͨ�����������p���������ݴ�����������s��
	vector<typename iterator_traits<InputIterator>::value_type> s(first, last);
	//��s��������sort�����Ĳ���������������ʵ�����
	sort(s.begin(), s.end());
	//��s����ͨ��������������
	copy(s.begin(), s.end(), result);
}

template<class InputIterator, class OutputIterator>
void mySort0(InputIterator first, InputIterator last, OutputIterator result,
		random_access_iterator_tag) {
	OutputIterator resultLast = copy(first, last, result);
	sort(result, resultLast);
}

//���������������p��n����ֵ���򣬽����ͨ�����������result���
template<class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
	mySort0(first, last, result,
			typename iterator_traits<OutputIterator>::iterator_category());
}

int main() {
	//��s�����������������
	double a[5] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
	double b[5];
	mySort(a, a + 5, b);
	copy(b, b + 5, ostream_iterator<double> (cout, " "));
	cout << endl;
	//�ӱ�׼����������ɸ��������������Ľ�����
	mySort(istream_iterator<int> (cin), istream_iterator<int> (),
			ostream_iterator<int> (cout, " "));
	cout << endl;
	return 0;
}
