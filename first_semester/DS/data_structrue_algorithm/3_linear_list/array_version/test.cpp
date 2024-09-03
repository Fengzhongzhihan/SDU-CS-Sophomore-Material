#include"arrayListWithIterator.hpp"
int main()
{
    arrayList<int>s(10);
    s.push_back(10);
    s.push_back(20);
    cout<<s<<endl;
    arrayList<int>::iterator i;
    for(i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i < 10 ; i++)
    cout << "Hello, World!" << endl;
    return 0;
}


