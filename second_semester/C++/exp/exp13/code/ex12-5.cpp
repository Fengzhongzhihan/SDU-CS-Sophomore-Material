#include <iostream>
#include <new> // ��Ҫ�������ͷ�ļ���ʹ�� std::bad_alloc
using namespace std;

int main()
{
    char *buf;
    try
    {
        buf = new char[10000000000000000]; // ���Է���1,000,000�ֽڵ��ڴ�
        // ʹ���ڴ滺���� buf
    }
    catch (const bad_alloc& e)
    {
        cout << "���쳣�������ڴ����ʧ��! ������Ϣ��" << e.what() << endl;
    }
    return 0;
}
