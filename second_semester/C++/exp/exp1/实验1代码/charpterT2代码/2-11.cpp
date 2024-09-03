#include <iostream>
using namespace std;
int main()
{
       int  ival1, ival2;
       double fval;
       char cval;
       ival1=1;           
       ival2=2;
       cout<<"ival1= "<<ival1<<endl;
       cout<<"ival2= "<<ival2<<endl;
       ival1=ival2=0;          
       ival1=fval=0;
       ival1=cval='a';cout<<"ival1= "<<ival1<<endl;
       cout<<"ival2= "<<ival2<<endl;
       cout<<"fval= "<<fval<<endl;
       cout<<"cval= "<<cval<<endl;
       int ival3=fval=8;     
       cout <<"ival3= "<<ival3<<endl;
       cout <<"fval= "<<fval<<endl;      
       cout <<"ival1 = "<<ival1<<" ival2 = "<<ival2<<endl;
       ival2 = -ival1++; 
       cout <<"ival2 = -ival1++, ival1= "<<ival1<<"ival2 = " << ival2;
       ival1 = ++ival2+ival1;
       cout <<"ival1 = ++ival2+ival1, ival1= "<<ival1<<endl;
       return 0;
}
       