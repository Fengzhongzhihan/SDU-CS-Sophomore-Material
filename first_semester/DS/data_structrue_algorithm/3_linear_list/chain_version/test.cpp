#include"chainWithIterator.hpp"
int main()
{
    Chain<int>a(10);
    a.push_back(1);a.push_back(2);a.push_back(3);a.push_back(4);a.push_back(5);
    Chain<int>::iterator i;
    for(i=a.begin();i!=a.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}