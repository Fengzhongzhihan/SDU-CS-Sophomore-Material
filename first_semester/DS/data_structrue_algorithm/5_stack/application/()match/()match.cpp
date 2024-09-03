#include"arrayStack.hpp"

void printMatchedPairs(string s)
{
    ArrayStack<int>stk;
    int length=s.size();

    for(int i=0;i<length;i++)
    {
        if(s[i]=='(')
            stk.push(i);
        else if(s[i]==')')
            try
            {
                cout<<stk.top()<<" "<<i<<endl;
                stk.pop();
            }
            catch(stackEmpty)
            {
                cout<<"No match for right pairs at "<<i<<endl;
            }
    }
    //输出剩下没有匹配的左括号
    while(!stk.empty())
    {
        cout<<"No match for left parenthesis at "<<stk.top()<<endl;
        stk.pop();
    }
}

int main()
{
    string str1("(a+b))))");
    printMatchedPairs(str1);
    string str2("(((aaa()))");
    printMatchedPairs(str2);
    return 0;
}