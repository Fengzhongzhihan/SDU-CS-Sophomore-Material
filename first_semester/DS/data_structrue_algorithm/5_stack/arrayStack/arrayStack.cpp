#include"arrayStack.hpp"
int main()
{
    ArrayStack<int> s;
    s.push(1);
    cout<<s.top()<<endl;
    s.push(2);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}