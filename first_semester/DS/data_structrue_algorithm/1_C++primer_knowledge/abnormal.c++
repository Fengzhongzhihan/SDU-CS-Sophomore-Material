#include<iostream>
using namespace std;

// 异常类
class illegalParameterValue
{
    public:
    illegalParameterValue():
        message("Illegal parameter value"){};
    illegalParameterValue(char* themessage)
    {
        message=themessage;
    }

    void outputMessage(){ cout<<message<<endl;}
    private:
        string message;
};

int abc(int a,int b,int c)
{
    if(a>0)throw illegalParameterValue("a should be <= 0");
    return a+b+c;
}

int main()
{
    try{cout<<abc(1,2,3)<<endl;}
    catch(illegalParameterValue e)
    {
        e.outputMessage();
        return 1;
    }
    return 0;
}

// //处理异常
// int abc(int a,int b,int c)
// {
//     if(a<0||b<0||c<0)
//         throw"all parameters should be >0";
//     return a+b+c;
// }
// int main()
// {
//     try{cout<<abc(10,20,-1);}
//     catch(char const *e)//注意得是char const *
//     {
//         cout<<"FALSE"<<endl;
//         cout<<e<<endl;
//         return 1;
//     }
//     return 0;
// }

// //内存分配异常
// const long long  N=100000000000000000;

// int main()
// {
//     int *y=new int (10);
//     float *array;
//     try{array=new float[N];}
//     catch(bad_alloc e)
//     {
//         cout<<"out of memory "<<endl;
//         exit(1);
//     }
//     return 0;
// }