//LinearEqu.cpp  �ļ��ģ�LinearEqu��ʵ��
#include "LinearEqu.h"	//������Ķ���ͷ�ļ�
#include <iostream>
#include <cmath>
using namespace std;

LinearEqu::LinearEqu(int size/* = 2 */) : Matrix(size) {	//��size���û��๹�캯��
	sums = new double[size];	//��̬�ڴ����
	solution = new double[size];
}

LinearEqu::~LinearEqu()	{ //������LinearEqu����������
	delete[] sums;	//�ͷ��ڴ�
	delete[] solution;
	//���Զ����û�����������
}

void LinearEqu::setLinearEqu(const double *a, const double *b) {	//�������Է�����
	setMatrix(a);	//���û��ຯ��
	for(int i = 0; i < getSize(); i++)
		sums[i] = b[i];
}

void LinearEqu::printLinearEqu() const {	//��ʾ���Է�����
	cout << "The Line eqution is:" << endl;
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++)
			cout << element(i, j) << " ";
			cout << "     " << sums[i] << endl;
		}
}

void LinearEqu::printSolution() const {	//������̵Ľ�
	cout << "The Result is: " << endl;
	for (int i = 0; i < getSize(); i++)
		cout << "x[" << i << "] = " << solution[i] << endl;
}

inline void swap(double &v1, double &v2) {	//��������ʵ��
	double temp = v1;
	v1 = v2;
	v2 = temp;
}

bool LinearEqu::solve() {	//ȫѡ��Ԫ�ظ�˹��ȥ����ⷽ��
	int *js=new int[getSize()];	//�洢��Ԫ�������кŵ�����
	for (int k = 0; k < getSize() - 1; k++)	{ 
		//ѡ��Ԫ��
		int is;	//��Ԫ�������к�
		double max = 0;	//����Ԫ�ص����ֵ
		for (int i = k; i < getSize(); i++)
			for (int j = k; j < getSize(); j++) {
				double t = fabs(element(i, j));
				if (t > max) {
					max = t;
					js[k] = j;
					is = i;
				}
			}
		if (max == 0) {
			delete[] js;
			return false;
		} else {
			//ͨ���С��н���������Ԫ�ؽ�������k�е�k��
			if (js[k] != k)
				for (int i = 0; i < getSize(); i++)
					swap(element(i, k), element(i, js[k]));
			if (is != k) {
				for (int j = k; j < getSize(); j++)
					swap(element(k, j), element(is, j));
				swap(sums[k], sums[is]);
			}
		}
		//��ȥ����
		double major = element(k, k);
		for (int j = k + 1; j < getSize(); j++)
			element(k, j) /= major;
		sums[k] /= major;
		for (int i = k + 1; i < getSize(); i++) {
			for (int j = k + 1; j < getSize(); j++)
				element(i, j) -= element(i, k) * element(k, j);
			sums[i] -= element(i, k) * sums[k];
		}
	}
	//�ж�ʣ�µ�һ��Ԫ���Ƿ����0
	double d = element(getSize() - 1, getSize() - 1);
	if (fabs(d) < 1e-15) {
		delete[] js;
		return false;
	}
	//�ش�����
	solution[getSize() - 1] = sums[getSize() - 1] / d;	
	for (int i = getSize() - 2; i >= 0; i--) {
		double t = 0.0;
		for (int j = i + 1; j <= getSize() - 1; j++)
			t += element(i, j) * solution[j];
		solution[i] = sums[i] - t;
	}
	js[getSize() - 1] = getSize() - 1;
	for (int k = getSize() - 1; k >= 0; k--)
		if (js[k] != k) swap(solution[k], solution[js[k]]);
	delete[] js;
	return true;
}
