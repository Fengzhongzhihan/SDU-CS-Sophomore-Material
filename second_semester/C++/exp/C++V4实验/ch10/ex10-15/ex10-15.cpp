#include <iterator>
#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
using namespace std;

template<class T>
class IncrementIterator: public iterator<random_access_iterator_tag, T,
		ptrdiff_t, const T*, const T&> {
private:
	T value;
	const T* valuePtr;
	mutable set<T> valueSet;

	const T* getValuePtr(int n) const {
		pair<typename set<T>::iterator, bool> iter = valueSet.insert(n);
		return &(*iter.first);
	}

	void updateValuePtr() {
		valuePtr = getValuePtr(value);
	}

public:
	typedef IncrementIterator<T> Self;
	IncrementIterator(const T& value = T()) :
		value(value) {
		updateValuePtr();
	}
	bool operator ==(const Self& rhs) const {
		return value == rhs.value;
	}
	bool operator !=(const Self& rhs) const {
		return value != rhs.value;
	}
	Self& operator ++() { //ǰ׺��++��
		value++;
		updateValuePtr();
		return *this;
	}
	Self operator ++(int) { //��׺��++��
		Self tmp = *this;
		value++;
		updateValuePtr();
		return tmp;
	}
	Self& operator --() { //ǰ׺��--��
		value--;
		updateValuePtr();
		return *this;
	}
	Self operator --(int) { //��׺��--��
		Self tmp = *this;
		value--;
		updateValuePtr();
		return tmp;
	}
	Self& operator +=(ptrdiff_t delta) {
		value += delta;
		updateValuePtr();
		return *this;
	}
	Self& operator -=(ptrdiff_t delta) {
		value -= delta;
		updateValuePtr();
		return *this;
	}
	Self operator +(ptrdiff_t delta) const {
		return Self(value + delta);
	}
	friend Self operator +(ptrdiff_t delta, const Self& iter) {
		return iter + delta;
	}
	Self operator -(ptrdiff_t delta) const {
		return Self(value - delta);
	}
	ptrdiff_t operator -(const Self& iter) const {
		return value - iter.value;
	}
	bool operator <(const Self& iter) const {
		return value < iter.value;
	}
	const T & operator [](ptrdiff_t delta) const {
		return getValuePtr(value + delta);
	}
	const T & operator *() const {
		return *valuePtr;
	}
	const T * operator ->() const {
		return valuePtr;
	}
};

int main() {
	//��[0, 10)��Χ�ڵ��������
	copy(IncrementIterator<int> (), IncrementIterator<int> (10),
			ostream_iterator<int> (cout, " "));
	cout << endl;

	//�����������е����ֱ����0��1��2��3��������Ȼ�����
	int s[] = { 5, 8, 7, 4, 2, 6, 10, 3 };
	transform(s, s + sizeof(s) / sizeof(int), IncrementIterator<int> (),
			ostream_iterator<int> (cout, " "), plus<int> ());
	cout << endl;

	return 0;
}
