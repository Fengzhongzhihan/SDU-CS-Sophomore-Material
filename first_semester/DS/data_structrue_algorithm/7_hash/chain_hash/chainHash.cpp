#include"chainHash.hpp"
int main()
{
    HashChains<int,int>s(10);
    s.insert(pair<int,int>(18,1));//8
    s.insert(pair<int,int>(32,1));//2
    s.insert(pair<int,int>(2,1));//2
    s.insert(pair<int,int>(5,1));//5
    cout<<s<<endl;

    return 0;
}