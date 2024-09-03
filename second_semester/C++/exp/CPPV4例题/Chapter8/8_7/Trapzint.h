//Trapzint.h  �ļ�һ���ඨ��

class Function {	//������Function�Ķ���
public:
	virtual double operator () (double x) const = 0;	//���麯�����������()
	virtual ~Function() { }
};

class MyFunction: public Function {	//����������MyFunction����
public:
	virtual double operator()(double x) const;	//�����麯��
};

class Integration {	//������Integration����
public:
	virtual double operator () (double a, double b, double eps) const = 0;
	virtual ~Integration() { }
};

class Trapz: public Integration	{	//����������Trapz����
public:
	Trapz(const Function &f) : f(f) {}	//���캯��
	virtual double operator ()(double a, double b,double eps) const;
private:
	const Function &f;	//˽�г�Ա��Function������ָ��
};	
