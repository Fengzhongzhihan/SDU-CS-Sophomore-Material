#include<iostream>
using namespace std;

//模板函数
// template <class T>
// T abc(T a,T b,T c)
// {
//     return a+b*c;
// }

// //引用参数节省空间,且可以改变变量的值
// int abc(int &a,int &b,int &c)

// {
//     return a+b+c;
// }

// 常量引用参数,不可修改变量的值,但是节省空间
// int abc(const int &a,const int &b,const int &c)
// {
//     return a+b+c;
// }

// 引用返回
// int & abc(int &a,int b,int c)
// {
//     a=20;
//     return a;
// }

//常量引用返回,注意此时必须要将值赋给const 常量
int &abc(int a)
{
    int b ;
    return b;
}

const int &ab(int a)
{
    int b ;
    return b;
}



