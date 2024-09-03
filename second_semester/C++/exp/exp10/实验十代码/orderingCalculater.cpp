#include"bits/stdc++.h"
using namespace std;
stack<int>num;
stack<char>op;
map<char, int>pr = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}};

void eval() {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}
int main() {
    string s;
    while (1) {
        num = stack<int>();
        op = stack<char>();
           getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        auto c = s[i];
        if (c == '(') {
            op.push(c);
        }
        else if (isdigit(c)) {
            int j = i, x = 0;
            while (j < s.size() && isdigit(s[j])) {
                x = x * 10 + s[j++] - '0';
            }
            i = j - 1;
            num. push(x);
        }
        else if(c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/'){
            // 如果当前操作符的优先级小于等于栈顶操作符的优先级, 则先计算栈顶操作符
            while (op.size() && pr[c] <= pr[op.top()] ) eval();
            op.push(c);
        }
    }

    while (op.size()) eval();

    cout << num.top() <<endl;

    }
 
    return 0;
}