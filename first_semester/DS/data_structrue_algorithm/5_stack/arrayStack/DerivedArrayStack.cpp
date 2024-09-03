#include"DerivedArrayStack.hpp"
int main()
{
    DerivedArrayStack<int> s1;
    s1.push(1);
    s1.push(2);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    s1.pop();
    try{s1.pop();}
    catch(stackEmpty)
        {
            cout<<"hello"<<endl;
        }
}