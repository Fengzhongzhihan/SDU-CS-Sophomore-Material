//6_11.cpp
#include <iostream>
using namespace std;

void printStuff(float) {
	cout << "This is the print stuff function." << endl;
}

void printMessage(float data) {
	cout << "The data to be listed is " << data << endl;
}

void printFloat(float data) {
	cout << "The data to be printed is " << data << endl;
}

const float PI = 3.14159f;
const float TWO_PI = PI * 2.0f;

int main() {	//������
	void (*functionPointer)(float);	//����ָ��
	printStuff(PI);
	functionPointer = printStuff;	//����ָ��ָ��printStuff
	functionPointer(PI);	//����ָ�����
	functionPointer = printMessage;	//����ָ��ָ��printMessage
	functionPointer(TWO_PI);	//����ָ�����
	functionPointer(13.0);	//����ָ�����
	functionPointer = printFloat;	//����ָ��ָ��printFloat
	functionPointer(PI);	//����ָ�����
	printFloat(PI);
	return 0;
}
