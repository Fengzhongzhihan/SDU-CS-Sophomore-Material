#include <iostream>
#include <cstdlib>  
using namespace std ;

int main()
{
	char choice,c;
	while(1)
	{
		cout << "Menu: A(dd) D(elete) S(ort) Q(uit)�� Select one:";
		cin >> c;
		choice = toupper(c);
		if (choice == 'A')
		{
			cout << "�����Ѿ�����. " << endl;
			continue;
		}
		else if (choice == 'D')
		{
			cout << "�����Ѿ�ɾ��. " << endl;
			continue;
		}
		else if (choice == 'S')
		{
			cout << "�����Ѿ�����. " << endl;
			continue;
		}
		else if (choice == 'Q')
			break;
	}
	return 0;
}