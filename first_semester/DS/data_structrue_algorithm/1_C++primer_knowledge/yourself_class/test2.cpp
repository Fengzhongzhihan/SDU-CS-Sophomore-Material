#include"currency_rebuilt.h"
#include"currency_rebuilt.cpp"
using namespace std;

int main()
{
    Currency g,h(PLUS,3,50),i,j;
    i.setValue(MINUS,2,25);
    j.setValue(3.45);
    //h 3.50 i -2.25 j 3.45 
    cout<<h<<i<<j;

    g=h+i+j;
    cout<<g;
    g+=i+j;
    cout<<g;
}