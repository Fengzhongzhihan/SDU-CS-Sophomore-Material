//Trapzint.cpp  �ļ�������ʵ��
#include "Trapzint.h"	//������Ķ���ͷ�ļ�
#include <cmath>

//��������
double MyFunction::operator () (double x) const {
	return log(1.0 + x) / (1.0 + x * x);
}

//����������̣�����Ϊ�����()
double Trapz::operator () (double a,double b,double eps) const {
	bool done = false;	//��Trapz����麯����Ա
	int n = 1;
	double h = b - a;
	double tn = h * (f(a) + f(b)) / 2;	//����n = 1ʱ�Ļ���ֵ
	double t2n;
	do {
		double sum = 0;
		for(int k = 0; k < n; k++) {
			double x = a + (k + 0.5) * h;
			sum += f(x);
		}
		t2n = (tn + h * sum) / 2.0;	//�䲽�����η�����
		if (fabs(t2n - tn) < eps)
			done = true;	//�жϻ������
		else {	//������һ������
			tn = t2n;
			n *= 2;
			h /= 2;
		}
	} while (!done);
	return t2n;
}
