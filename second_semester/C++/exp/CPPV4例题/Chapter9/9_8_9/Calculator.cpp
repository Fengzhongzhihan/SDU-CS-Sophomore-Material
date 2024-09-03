#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

void Calculator::enter(double num) {	//��������numѹ��ջ
	s.push(num);
}

//��������������������ջ������opnd1��opnd2��
//���ջ��û���������������򷵻�False ����������Ϣ
bool Calculator::getTwoOperands(double &opnd1, double &opnd2) {
	if (s.isEmpty()) {	//���ջ�Ƿ��
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd1 = s.pop();	//���Ҳ���������ջ
	if (s.isEmpty()) {	//���ջ�Ƿ��
		cerr << "Missing operand!" << endl;
		return false;
	}
	opnd2 = s.pop();	//�������������ջ
	return true;
}

void Calculator::compute(char op) {	//ִ������
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);   //����������������ջ

	if (result) {	//����ɹ���ִ�����㲢��������ѹ��ջ
		switch(op) {
		case '+':
			s.push(operand2 + operand1);
			break;
		case '-':
			s.push(operand2 - operand1);
			break;
		case '*':
			s.push(operand2 * operand1);
			break;
		case '/':
			if (operand1 == 0) {	//�������Ƿ�Ϊ0
				cerr << "Divided by 0!" << endl;
				s.clear();	//����Ϊ0ʱ���ջ
			} else
				s.push(operand2 / operand1);
			break;
		case '^':
			s.push(pow(operand2, operand1));
			break;
		default:
			cerr << "Unrecognized operator!" << endl;
			break;
		}
		cout << "= " << s.peek() << " ";	//������������� 
	} else
		s.clear();	//���������������ջ
}

//���ߺ��������ڽ��ַ���ת��Ϊʵ��
inline double stringToDouble(const string &str) {
	istringstream stream(str);	//�ַ���������
	double result;
	stream >> result;
	return result;
}

void Calculator::run() {	//���벢�����׺���ʽ
	string str;
	while (cin >> str, str != "q") {
		switch(str[0]) {
		case 'c':
			s.clear();	//��'c'��ղ�����ջ
			break;
		case '-':	//��'-'���ж��Ǽ��Ż��Ǹ���
			if (str.size() > 1)	//���ַ�������>1��˵���������Ǹ����ĸ���
				enter(stringToDouble(str));	//���ַ���ת��Ϊ������ѹ��ջ
			else
				compute(str[0]);	//���Ǽ�����ִ�м���
			break;

		case '+':	//��������������ʱ
		case '*':
		case '/':
		case '^':
			compute(str[0]);	//ִ�м���
			break;

		default:	//��������ǲ�������ת��Ϊ���ͺ�ѹ��ջ
			enter(stringToDouble(str));
			break;
		}
	}
}

void Calculator::clear() {	//��ղ�����ջ
	s.clear(); 
}
