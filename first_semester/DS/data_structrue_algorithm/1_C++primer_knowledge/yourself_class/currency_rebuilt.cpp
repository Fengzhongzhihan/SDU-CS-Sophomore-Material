#include"currency_rebuilt.h"

 Currency::Currency(signType theSign,ul theDollars,ui theCents)
{
    setValue(theSign,theDollars,theCents);
}
void Currency::setValue(signType theSign,ul theDollars,ui theCents)
{
    if(theCents>99)throw ("cents should be <100");
    my_amount=theCents+theDollars*100;
    if(theSign==MINUS)
    my_amount=-my_amount;
}

void Currency::setValue(double amount)
{
    if(amount <0) 
    {
        my_amount=-amount;
    }
    my_amount=amount*100;
}

Currency Currency::operator+ (const Currency&x)const
{
    Currency result;
    result.my_amount=x.my_amount+my_amount;
    return result;
}

//不加入友元的写法
// void Currency::output(ostream& out)const
// {
//     if(my_amount<0)out<<"-";
//    ul dollars=getDollars();
//    out<<"$"<<dollars<<".";
//    ui cents=getCents();
//    if(cents<10)out<<"0";
//    out<<cents<<endl;
// }

ostream & operator<<(ostream& out,const Currency &x)
{
    // x.output(out);return out;

    if(x.my_amount<0)out<<"-";
   ul dollars=x.getDollars();
   out<<"$"<<dollars<<".";
   ui cents=x.getCents();
   if(cents<10)out<<"0";
   out<<cents<<endl;
}






