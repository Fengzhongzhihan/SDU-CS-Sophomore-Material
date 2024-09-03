#include <iostream>
#include <new> // 需要包含这个头文件以使用 std::bad_alloc
using namespace std;

int main()
{
    char *buf;
    try
    {
        buf = new char[10000000000000000]; // 尝试分配1,000,000字节的内存
        // 使用内存缓冲区 buf
    }
    catch (const bad_alloc& e)
    {
        cout << "有异常产生：内存分配失败! 错误信息：" << e.what() << endl;
    }
    return 0;
}
