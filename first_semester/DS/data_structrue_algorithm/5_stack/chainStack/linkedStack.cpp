#include"linkedStack.hpp"
int main()
{
    linkedStack<int>s;
    chainNode<int>*a=new chainNode<int>(1);
    chainNode<int>*b=new chainNode<int>(2);
    s.pushNode(a);s.pushNode(b);
    cout<<s.top()<<endl;//2
    cout<<s.popNode()<<endl;//2
    cout<<s.popNode()<<endl;//1
    cout<<s.top();
    return 0;
}