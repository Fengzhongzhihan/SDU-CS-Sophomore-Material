//10_2.cpp
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

//��ƽ���ĺ���
double square(double x) {
	return x * x;
}

int main() {
	//�ӱ�׼����������ɸ�ʵ�����ֱ����ǵ�ƽ�����
    transform(istream_iterator<double>(cin), istream_iterator<double>(),
		ostream_iterator<double>(cout, "\t"), square);
    cout << endl;
    return 0;
}
