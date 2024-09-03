#include <iostream>
using namespace std;
int main()
{
   int val1=24;
   int val2=5;
   double val3=24;
   double val4=5;
   cout << "int/int, 24/5= "<<val1/val2<<endl;    
   cout << "int/int, 24%5= "<<val1%val2<<endl;  
   val2=-5;
   cout << "int/int, 24%(-5)= "<<val1%val2<<endl;
   cout << "double/double, 24/5= "<<val3/val4<<endl; 
cout << "double/int, 24/5= "<<val3/val2<<endl;   
   cout << "int/double, 24/5= "<<val1/val4<<endl;   
       val1=5;  
       cout <<"val1 = "<<val1<<endl; 
       cout <<val1++<<", ";
       cout <<++val1<<", ";
       cout <<val1--<<", ";
       cout <<--val1<<endl;    
       val1=5;  
       cout <<"val1 = "<<val1<<endl;            
   cout <<val1++<<", "<<++val1<<", "<<val1--<<", "<<--val1<<endl; //不同的编译器求值顺序可能不同
}
