#include"maxHblt.hpp"
int main()
{
    MaxHblt<int> hblt;
    int arr[]={7,4,5,1,2};
    hblt.initilize(arr,5);
    hblt.inOrderOutput();
    hblt.push(3);
    hblt.inOrderOutput();
    hblt.pop();
    hblt.inOrderOutput();
    cout<<hblt.size()<<endl;
}