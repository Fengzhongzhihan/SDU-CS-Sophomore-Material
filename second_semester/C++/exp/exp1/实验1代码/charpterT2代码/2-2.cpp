#include <iostream>
using namespace std;
int main()
{   const double PI(3.14159);  	
     int radius;	
     cout<<"Please enter the radius!\n";
     cin>>radius;	
     cout<<"The radius is:"<<radius<<'\n';	
     cout<<"PI is:"<<PI<<'\n';	
     cout<<"Please enter a different radius!\n"; 
     cin>>radius;	
     cout<<"Now the radius is changed to:"<<radius<<'\n';
     cout<<"PI is still:"<<PI<<'\n';
     //cin>>pi;
     return 0;
}
