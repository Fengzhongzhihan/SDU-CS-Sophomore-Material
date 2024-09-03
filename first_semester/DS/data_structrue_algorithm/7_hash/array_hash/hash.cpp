#include"hash.hpp"

int main()
{
    hashTable<int,int>s(10);
    s.insert(pair<int,int>(13,2));
    s.insert(pair<int,int>(23,4));
    auto k=s.findPair(13);
    if(k!=NULL)
        cout<<k->first<<" "<<k->second<<endl;
    else 
        cout<<"NULL"<<endl;
    cout<<s.searchIndex(13)<<endl;

    s.insert(pair<int,int>(1,3));
    
    k=s.findPair(23);
    if(k!=NULL)
        cout<<k->first<<" "<<k->second<<endl;
    else 
        cout<<"NULL"<<endl;

    cout<<s.searchIndex(23)<<endl;
    return 0;
}