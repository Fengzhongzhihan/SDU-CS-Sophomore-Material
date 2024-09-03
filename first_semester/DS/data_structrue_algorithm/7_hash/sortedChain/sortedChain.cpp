#include"sortedChain.hpp"
#include"dictionary.h"
#include"pairNode.h"

int main()
{
    SortedChain<int,int>s;
    s.insert(pair<int,int>(1,2));
    s.insert(pair<int,int>(2,3));
    cout<<s.find(2)->second<<endl;
    cout<<s.find(1)->second<<endl;
    return 0;
}