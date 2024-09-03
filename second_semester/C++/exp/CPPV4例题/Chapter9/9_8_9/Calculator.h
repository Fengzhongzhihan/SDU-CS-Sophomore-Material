//Calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Stack.h"	// ����ջ��ģ�嶨���ļ�

class Calculator {	//��������
private:
	Stack<double> s;	// ������ջ
	void enter(double num);	//��������numѹ��ջ
	//��������������������ջ������opnd1��opnd2��
	bool getTwoOperands(double &opnd1, double &opnd2);
	void compute(char op);	//ִ���ɲ�����opָ��������
public:
	void run();		//���м���������
	void clear();	//��ղ�����ջ
};

#endif //CALCULATOR_H
