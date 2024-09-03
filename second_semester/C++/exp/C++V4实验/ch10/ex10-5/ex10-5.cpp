#include <iostream>
#include <typeinfo>
#include <list>
#include <deque>
#include <vector>
#include <ctime>
using namespace std;

template<class T>
void joseph(T collection, int n, int m) {
	if (n < 1 || m < 1) {
		cout << "������������" << endl;
		return;
	}
	for (int i = 1; i <= n; i ++)
		collection.push_back(i);
	typename T::iterator iter = collection.begin(), del;
	int counter = 1;
	clock_t start = clock(), finish;
	while (collection.size() > 1) {
		while (counter % m == 0 && collection.size() > 1) {
			counter = 1;
			if (typeid(collection) != typeid(list<int>))
				iter = collection.erase(iter);
			else {
				del = iter;
				iter ++;
				collection.erase(del);
			}
			if (iter == collection.end())
				iter = collection.begin();
		}
		counter ++;
		iter ++;
		if (iter == collection.end())
			iter = collection.begin();
	}
	finish = clock();
	cout << "���ʣ����˵ı����" << *iter << endl;
	cout << "ʹ������" << typeid(collection).name() << "������ʱ��Ϊ" << 1.0 * (finish - start) / CLOCKS_PER_SEC << "��" << endl;
}

int main() {
	list<int> l;
	vector<int> v;
	deque<int> d;
	joseph(l, 100000, 5);
	joseph(d, 100000, 5);
	joseph(v, 100000, 5);
	return 0;
}
