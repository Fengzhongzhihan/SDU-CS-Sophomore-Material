#include <iostream>
using namespace std;
int main()
{
   int ival1=1, ival2=2, ival3=3, ival4=4;
   bool nFlag;
   nFlag = ival1==ival2?true:false;
   cout <<"Is 1 equals 2?:"<<nFlag<<endl;
   nFlag = ival1<ival2?true:false;
   cout <<"Is 1less than 2?: "<<nFlag<<endl;
   nFlag = (ival1<ival2 && ival3<ival4)?true:false;
   cout <<"Is 1less than 2 and 3 less than 4:"<<nFlag<<endl;
}