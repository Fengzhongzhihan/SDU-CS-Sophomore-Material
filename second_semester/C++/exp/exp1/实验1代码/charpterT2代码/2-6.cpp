#include <iostream>
#include <limits>
using namespace std;
int main()
{
   int isample, osample, hsample;
   unsigned long ulsample;   
   cin>>isample>>oct>>osample>>hex>>hsample; 
   cout<<isample<<';'<<oct<<osample<<';'<<hex<<hsample<<endl;   
   isample=123;
   osample=0173;
   hsample=0x7B;
  ulsample=4294967295UL;
  cout<<dec<<isample<<';'<<oct<< isample 
       <<';'<<hex<< isample <<endl;
  cout<<dec<< osample<<';' <<oct<<osample
       <<';'<<hex<< osample <<endl;
  cout<< dec<<hsample <<';'<<oct<< hsample<<';'  
       <<hex<<hsample<<endl;
  cout<<dec<< ulsample <<';'<<oct<<ulsample<<';' 
       <<hex<<ulsample<<endl;
 return 0;
}
