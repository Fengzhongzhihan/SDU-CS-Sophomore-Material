#include <iostream>
using namespace std;

int main()
{
    char *buf;
    try
    {
        buf = new char[512];
        if( buf == 0 )
            throw "�ڴ����ʧ��!";
    }
    catch( char * str )
    {
        cout << "���쳣������" << str << endl;
    }
	return 0;
}
