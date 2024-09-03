#include"currency.h"
#include"currency.cpp"
int main()
{
    //以下为测试代码
    Currency g,h(PLUS,3,50),i,j;
    i.setValue(MINUS,2,25);
    j.setValue(3.45);

    g=i.add(j).add(h);
    g.output();
    g=i.increment(j).add(h);
    g.output();

    try{i.setValue(PLUS,3,152);}
    catch(const char * e)
    {
        cout<<e<<endl;
    }
    return 0;
}


