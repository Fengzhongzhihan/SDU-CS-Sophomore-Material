#include<iostream>
using namespace std;

template<class T>
class stack
{
    public:
    virtual ~stack(){}
    virtual bool empty() const =0;
    virtual int size()const =0;
    virtual T top()=0;
    virtual void pop()=0;
    virtual void push(const T& theElement)=0;
};
#ifndef myExceptions_
#define myExceptions_
#include <string>
#include<iostream>

using namespace std;

// illegal parameter value
class illegalParameterValue 
{
   public:
      illegalParameterValue(string theMessage = "Illegal parameter value")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// illegal input data
class illegalInputData 
{
   public:
      illegalInputData(string theMessage = "Illegal data input")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// illegal index
class illegalIndex 
{
   public:
      illegalIndex(string theMessage = "Illegal index")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// matrix index out of bounds
class matrixIndexOutOfBounds 
{
   public:
      matrixIndexOutOfBounds
            (string theMessage = "Matrix index out of bounds")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// matrix size mismatch
class matrixSizeMismatch 
{
   public:
      matrixSizeMismatch(string theMessage = 
                   "The size of the two matrics doesn't match")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// stack is empty
class stackEmpty
{
   public:
      stackEmpty(string theMessage = 
                   "Invalid operation on empty stack")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// queue is empty
class queueEmpty
{
   public:
      queueEmpty(string theMessage = 
                   "Invalid operation on empty queue")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// hash table is full
class hashTableFull
{
   public:
      hashTableFull(string theMessage = 
                   "The hash table is full")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// edge weight undefined
class undefinedEdgeWeight
{
   public:
      undefinedEdgeWeight(string theMessage = 
                   "No edge weights defined")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};

// method undefined
class undefinedMethod
{
   public:
      undefinedMethod(string theMessage = 
                   "This method is undefined")
            {message = theMessage;}
      void outputMessage() {cout << message << endl;}
   private:
      string message;
};
#endif

#include"unordered_map"

template<class T>
class ArrayStack :public stack<T>
{
public:
    ArrayStack(int theCapacity=10);
    ~ArrayStack(){delete[] stack;}
    bool empty() const{return stackTop==-1;}
    int size()const {return stackTop+1;}
    T top()
    {
        if(stackTop==-1)
            throw stackEmpty();
        return stack[stackTop];
    }
    void pop()
    {
        if(stackTop==-1)
            throw stackEmpty();
        stack[stackTop--].~T();
    }
    void push(const T& theElement);
    void clear()
    {
        stackTop=-1;
    }
private:
    int stackTop;
    int arrayLength;
    T* stack;
};
template<class T>
void changeLength(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
        throw illegalParameterValue("the newlength must >0");
    T *temp=new T[newLength];
    int size=min(oldLength,newLength);
    copy(a,a+size,temp);
    delete[]a;
    a=temp;
}

template <class T>
inline ArrayStack<T>::ArrayStack(int theCapacity)
{
    if(theCapacity<1)
        throw illegalParameterValue("Capacity must >0");
    arrayLength=theCapacity;
    stack=new T[theCapacity];
    stackTop=-1;
}

template <class T>
inline void ArrayStack<T>::push(const T &theElement)
{
    if(stackTop+1==arrayLength)
    {
        changeLength(stack,arrayLength,arrayLength*2);
        arrayLength*=2;
    }
    stack[++stackTop]=theElement;
}
int n;
ArrayStack<double>num;
ArrayStack<char>op;
unordered_map<char,int>mp;
string s;

//进行计算
void eval()
{
    double result=0;
    double b=num.top();num.pop();
    double a=num.top();num.pop();
    char c=op.top();op.pop();
    if(c=='+')
        result=a+b;
    else if(c=='-')
        result=a-b;
    else if(c=='*')
        result=a*b;
    else 
        result=a/b;
    num.push(result);
}

int main()
{
    cin>>n;
    mp.insert({'+',1});mp.insert({'-',1});
    mp.insert({'*',2});mp.insert({'/',2});

    while(n--)
    {
        num.clear();
        op.clear();
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(isdigit(c))
            {
                int j=i;
                double x=0;
                while(j<s.size()&&isdigit(s[j]))
                {
                    x=x*10+s[j]-'0';
                    j++;
                }
                i=j-1;
                num.push(x);
            }
            else if(c=='(')
            {
                op.push(c);
            }
            else if(c==')')
            {
                while(op.top()!='(')
                    eval();
                op.pop();//删除(
            }
            else 
            {
                while(op.size()&&mp[op.top()]>=mp[c])
                    eval();
                op.push(c);
            }
        }
        while(op.size())
            eval();
        printf("%.2f\n",num.top());
    }
    return 0;
}
