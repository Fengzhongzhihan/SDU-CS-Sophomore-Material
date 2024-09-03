#include "currency.h"

 Currency::Currency(signType theSign,ul theDollars,ui theCents)
{
    setValue(theSign,theDollars,theCents);
}
void Currency::setValue(signType theSign,ul theDollars,ui theCents)
{
    if(theCents>99)throw ("cents should be <100");

    sign=theSign;dollars=theDollars;cents=theCents;
}

void Currency::setValue(double amount)
{
    if(amount <0) 
    {
        sign=MINUS;amount=-amount;
    }

    dollars=(ul)amount;
    cents=(ui)((amount+0.001-dollars)*100);
}

Currency Currency::add(const Currency&x)const 
{
    long a1,a2;
    Currency result;
    a1=dollars*100+cents;
    if(sign==MINUS)a1=-a1;
    a2=x.dollars*100+x.cents;
    if(x.sign==MINUS)a2=-a2;

    long a3=a1+a2;
    //给result赋值
    if(a3<0){a3=-a3;result.sign=MINUS;}
    result.dollars=a3/100;
    result.cents=a3-result.dollars*100;

    return result;
}

Currency& Currency::increment(const Currency&x)
{
    *this=add(x);
    return *this;
}

void Currency::output()const
{
    if(sign==MINUS)cout<<"-";
    cout<<"$"<<dollars<<".";
    if(cents<10)cout<<"0";
    cout<<cents<<endl;
}

void Currency::input()
{
    double value;
    cin>>value;
    if(value<0)
    {
        sign=MINUS;
        value=-value;
    }
    else sign=PLUS;

    dollars=ul(value);
    cents=ui((value-dollars+0.001)*100);
}

double Currency::subtract(double x)const
{
    double temp=(dollars*100+cents);
    if(sign==MINUS)temp=-temp;
    return temp/100-x;
}

Currency Currency::percent(double x)const
{
        Currency result;
        double temp=(dollars*100+cents)*x/100.0;
        result.dollars=temp/100;
        if(temp>0)
        result.sign=PLUS;
        else result.sign=MINUS;
        result.cents=temp-result.dollars*100;
        return result;
}

Currency Currency::multiply(double x)const 
{       Currency result;
        double temp=(dollars*100+cents)/100.0;
        if(sign==MINUS)temp=-temp;
        double res=temp*x;

        result.dollars=(ul)abs(res);

        if(res>0)
        result.sign=PLUS;
        else result.sign=MINUS;

        result.cents=(ui)((abs(res)-result.dollars+0.001)*100);

        return result;
}

 Currency Currency::divide(double x)const 
    {
         Currency result;
        double temp=(dollars*100+cents)/100.0;
        if(sign==MINUS)temp=-temp;
        double res=temp/x;

        result.dollars=(ul)abs(res);

        if(res>0)
        result.sign=PLUS;
        else result.sign=MINUS;

        result.cents=(ui)((abs(res)-result.dollars+0.001)*100);

        return result;
    }
