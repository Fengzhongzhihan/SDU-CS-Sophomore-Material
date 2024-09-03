//2_11.cpp
#include <iostream>
using namespace std;

enum GameResult { WIN, LOSE, TIE, CANCEL };

int main() {
	GameResult result;                  //��������ʱ,���Բ�д�ؼ���enum
	enum GameResult omit = CANCEL;      //Ҳ������������ǰдenum

	for (int count = WIN ; count <= CANCEL ; count++) {	//��������ת��
		result = GameResult(count);		//��ʽ����ת��
		if (result == omit) 
			cout << "The game was cancelled" << endl;
		else {
			cout << "The game was played ";
			if (result == WIN)
				cout << "and we won!";
			if (result == LOSE)
				cout << "and we lost.";
			cout << endl;
		}
	}
	return 0;
}
