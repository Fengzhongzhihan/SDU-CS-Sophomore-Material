//LinearEqu.h  �ļ�����LinearEqu�ඨ��
#ifndef _LINEAR_EQU_H
#define _LINEAR_EQU_H

#include "Matrix.h"

class LinearEqu: public Matrix {	//����������LinearEqu����
public:	//�ⲿ�ӿ�
	LinearEqu(int size = 2);	//���캯��
	~LinearEqu();	//��������
	void setLinearEqu(const double *a, const double *b);	//���̸�ֵ
	bool solve();	//ȫѡ��Ԫ��˹��ȥ����ⷽ��
	void printLinearEqu() const;	//��ʾ����
	void printSolution() const;	//��ʾ���̵Ľ�
private:	//˽������
	double *sums;	//�����Ҷ���
	double *solution;	//���̵Ľ�
};

#endif //_LINEAREQU_H
