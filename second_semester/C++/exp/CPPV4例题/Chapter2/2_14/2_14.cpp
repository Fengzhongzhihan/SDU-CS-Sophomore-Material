//2_14.cpp
#include <iostream>
using namespace std;

struct Aircraft {
	int wingspan;	//���
	int passengers; //�˿�
	union {					//����������Ϊ�ṹ�����Ƕ��Ա
		float fuelLoad; 	//ս����װ�ص�ȼ��
		float bombLoad; 	//��ը��װ�ص�ը��
		int pallets; 		//������Ļ���
	};
} fighter, bomber, transport;

int main() {
	fighter.wingspan = 40;
	fighter.passengers = 1;
	fighter.fuelLoad = 12000.0;
	
	bomber.wingspan = 90;
	bomber.passengers = 12;
	bomber.bombLoad = 14000.0;
	
	transport.wingspan = 106;
	transport.passengers = 4;
	transport.pallets = 42;
	
	transport.fuelLoad = 18000.0;
	fighter.pallets = 4;
	
	cout << "The fighter carries " << fighter.pallets << " pallets." << endl;
	cout << "The bomber bomb load is " << bomber.bombLoad << endl;

	return 0;
}
