#include <iostream>
using namespace std;
int main()
{
    bool bV1= true, bV2= false;
    cout <<" value bV1 = "<<bV1<<endl;
    cout <<"bool value bV2 = "<<bV2<<endl;
    int nV1=bV1, nV2 = 0;
    bV1 = nV2;
    cout <<"int value nV1 = "<< nV1<<endl;
    cout <<"bool value bV1 = "<<bV1<<endl;
    return 0;
}
