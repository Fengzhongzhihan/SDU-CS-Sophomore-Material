#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	const int SIZE1 = 6, SIZE2 = 4;
	int a1[SIZE1];
	int a2[SIZE2];
	ostream_iterator<int> output(cout, " ");

	cout << "��������a1��6��Ԫ��: ";
	for (int i = 0; i < SIZE1; i ++)
		cin >> a1[i];
	cout << "��������a2��4��Ԫ��: ";
	for (int i = 0; i < SIZE2; i ++)
		cin >> a2[i];

	cout << "����a1��Ԫ��: ";
	copy(a1, a1 + SIZE1, output);
	cout << "\n����a2��Ԫ��: ";
	copy(a2, a2 + SIZE2, output);

	int intersection[SIZE1+SIZE2];
	int *ptr = set_intersection(a1, a1 + SIZE1, a2, a2 + SIZE2, intersection);
	cout << "\na1��a2�Ľ���: ";
	copy(intersection, ptr, output);

	int unionSet[SIZE1];
	ptr = set_union(a1, a1 + SIZE1, a2, a2 + SIZE2, unionSet);
	cout << "\na1��a2�Ĳ���: ";
	copy(unionSet, ptr, output);

	int difference[SIZE1];
	ptr = set_difference(a1, a1 + SIZE1, a2, a2 + SIZE2, difference);
	cout << "\na1/a2����: ";
	copy(difference, ptr, output);

	return 0;
}
