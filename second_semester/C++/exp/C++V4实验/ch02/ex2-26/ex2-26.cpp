#include <iostream>
#include <cstdlib> 
using namespace std ;

int main()
{
	char flag;
	while(1)
	{
		cout << "��������������(Y or N):";
		cin >> flag;
		if ( toupper(flag) == 'Y')
		{
			cout <<	"�����������ꡣ";
			break;
		}
		if ( toupper(flag) == 'N')
		{
			cout <<	"����û�����ꡣ";
			break;
		}
		cout << endl;
	}
	return 0;
}
