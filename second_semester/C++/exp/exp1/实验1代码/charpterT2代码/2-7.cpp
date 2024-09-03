#include <iostream>
#include <limits>
using namespace std;
const float PI_FLOAT = 3.1415926f;
const double PI_DOUBLE = 3.1415926;
const long double PI_LDOUBLE = 3.1415926; 
int main()
{
  float nRadiusFloat = 5.5f, nAreaFloat;
  double nRadiusDouble = 5.5, nAreaDouble;
  long double nRadiusLDouble = 5.5, nAreaLDouble;
  nAreaFloat = PI_FLOAT* nRadiusFloat* nRadiusFloat;
	   nAreaDouble = PI_DOUBLE* nRadiusDouble* 
                          nRadiusDouble;
nAreaLDouble = PI_DOUBLE* nRadiusDouble*  
                              nRadiusDouble;
  cout << "nAreaFloat = "<< nAreaFloat <<",sizeof(nAreaFloat) = "<< sizeof(nAreaFloat)<< endl;
           
 cout << "nAreaDouble = "<< nAreaDouble
         <<" , sizeof(nAreaDouble) = "
         << sizeof(nAreaDouble)<<endl;
 cout << "nAreaLDouble = "<< nAreaLDouble
         <<" , sizeof(nAreaLDouble) = "
         << sizeof(nAreaLDouble)<<endl;
return 0; }
