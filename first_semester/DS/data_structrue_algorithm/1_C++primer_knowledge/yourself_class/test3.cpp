#include "currency.h"
#include "currency.cpp"

int main()
{
    Currency g,h(PLUS,3,50),i,j;
    i.setValue(MINUS,2,25);
    j.setValue(3.45);
    //h 3.50 i -2.25 j 3.45 
    g.input();
    g.output();
    cout<<g.subtract(1.2)<<endl;
    g.percent(1.2).output();
    g.multiply(-2).output();
    g.divide(2).output();

    return 0;
}