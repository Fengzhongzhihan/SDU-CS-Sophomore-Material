#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "�����Ԫ�أ�";
	copy(a, a+10, ostream_iterator<int>(cout," "));
	cout << endl;
	swap(a[5], a[6]);
	cout << "swap�������н����������Ԫ�أ�";
	copy(a, a+10, ostream_iterator<int>(cout," "));
	cout << endl;
	iter_swap(&a[1], &a[4]);
	cout << "iter_swap�������н����������Ԫ�أ�";
	copy(a, a+10, ostream_iterator<int>(cout," "));
	cout << endl;
	swap_ranges(a, a+5, a+5);
	cout << "swap_ranges�������н����������Ԫ�أ�";
	copy(a, a+10, ostream_iterator<int>(cout," "));
	cout << endl;
	return 0;
}
