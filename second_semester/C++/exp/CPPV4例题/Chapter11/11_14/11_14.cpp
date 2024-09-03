//11_14.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <locale>
using namespace std;

int main() {
	locale loc(".936");	//�������ػ����÷���

	wcout.imbue(loc);	//Ϊwcout���ñ��뷽��
	wifstream in("article.txt");	//�����ļ��������������ļ�article.txt
	in.imbue(loc);		//Ϊin���ñ��뷽��

	wstring line;			//�����洢һ������
	unsigned number = 0;	//��¼�к�
	while (getline(in, line)) {
		number++;			//�кż�1
		if (line.find_first_of(L'��') != wstring::npos)	//���ҡ��ˡ���
			wcout << number << L": " << line << endl;	//����������ˡ��ֵ���
	}

	return 0;
}
