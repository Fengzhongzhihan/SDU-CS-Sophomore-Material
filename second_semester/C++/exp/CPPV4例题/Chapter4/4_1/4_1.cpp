//4_1.cpp
#include <iostream>	
using namespace std;

class Clock	{ //ʱ����Ķ���
public:		//�ⲿ�ӿڣ����г�Ա����
	void setTime(int newH = 0, int newM = 0, int newS = 0);
	void showTime();
private:	//˽�����ݳ�Ա
	int hour, minute, second;
};

//ʱ�����Ա�����ľ���ʵ��
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}

inline void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second << endl;
}

//������
int main() {
	Clock myClock;	//�������myClock
	cout << "First time set and output:" << endl;
	myClock.setTime();	//����ʱ��ΪĬ��ֵ
	myClock.showTime();	//��ʾʱ��
	cout << "Second time set and output:" << endl;
	myClock.setTime(8, 30, 30);	//����ʱ��Ϊ8��30��30
	myClock.showTime();	//��ʾʱ��
	return 0;
}
