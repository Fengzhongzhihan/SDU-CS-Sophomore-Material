#include<iostream>
using namespace std;

template<class T>
class Matrix
{
public:
    //构造析构函数
    Matrix(int theRows=0,int theColumns=0);
    Matrix(const Matrix<T>&);
    ~Matrix(){delete[]element;}
    int rows()const {return theRows;}
    int columns()const {return theColumns;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
    
    //运算符重载
    T& operator()(int i,int j)const ;
    Matrix<T>&operator=(const Matrix<T>&);
    Matrix<T>operator+()const;
    Matrix<T>operator+(const Matrix<T>&)const;
    Matrix<T>operator-()const;
    Matrix<T>operator-(const Matrix<T>&)const;
    Matrix<T>operator*(const Matrix<T>&)const;
    Matrix<T>&operator+=(const T&)const;
private:
    int theRows,theColumns;
    T* element;
};

//含参构造
template <class T>
Matrix<T>::Matrix(int theRows,int theColumns)
{
    if(theRows<0||theColumns<0)
        throw ("Rows and colums must be >=0");
    //一个等于零且一个不等于零
    if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0))
        throw ("Either both or neither rows and columns should be zero");
    
    this->theRows=theRows;
    this->theColumns=theColumns;
    element=new T[theRows*theColumns];
}

//拷贝构造
template<class T>
Matrix<T>::Matrix(const Matrix<T>&x)
{
    theRows=x.theRows;
    theColumns=x.theColumns;
    element=new T[theRows*theColumns];
    copy(x.element,x.element+theRows*theColumns,element);
}

template <class T>
inline void Matrix<T>::set(int i, int j,const T& value)
{
    element[(i-1)*theColumns+j-1]=value;
}

template <class T>
inline T& Matrix<T>::get(int i, int j) const
{
    return element[(i-1)*theColumns+j-1];
}

//()重载
template <class T>
T& Matrix<T>::operator()(int i, int j) const
{
    if(i<1||i>theRows||j<1||j>theColumns)
        throw ("index out of bounds");
        
    return element[(i-1)*theColumns+j-1];
}

//=重载
template <class T>
inline Matrix<T> &Matrix<T>::operator=(const Matrix<T> &x)
{
    //不能赋值自己
    if(this!=&x)
    {
        delete[]element;
        theRows=x.theRows;
        theColumns=x.theColumns;
        element=new T[theRows*theColumns];
        copy(x.element,x.element+theRows*theColumns,element);
    }
    return *this;
}

//+重载
template <class T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T> &x) const
{
    if(theRows!=x.theRows||theColumns!=x.theColumns)
        throw ("matrix size not matching");

    Matrix<T>w(theRows,theColumns);
    for(int i=0;i<theColumns*theRows;i++)
        w.element[i]=element[i]+x.element[i];
    return w;
}

template <class T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T> &x) const
{
    if(theColumns!=x.theRows)
        throw("mismatch");

    Matrix<T>w(theRows,x.theColumns);

    int ct=0,cx=0,cw=0;
    //进行赋值
    for(int i=1;i<=theRows;i++)
    {
        //求出w中一行的元素
        for(int j=1;j<=x.theColumns;j++)
        {
            //先写出来第一项
            T sum=element[ct]*x.element[cx];
            for(int k=2;k<=theColumns;k++)
            {
                ct++;
                cx+=x.theColumns;
                sum+=element[ct]*x.element[cx];
            }
            w.element[cw++]=sum;
            ct=ct+1-theColumns;//不能初始化为1
            cx=j;
        }
        
        //行求完了,换下一行继续求
        ct+=theColumns;
        cx=0;
    }

    return w;
}

//给定两个矩阵x,y, 进行矩阵乘法, 返回z, 换一种写法
template <class T>
Matrix<T> operator*(const Matrix<T> &x,const Matrix<T> &y)
{
    if(x.columns()!=y.rows())
        throw("mismatch");

    Matrix<T>z(x.rows(),y.columns());

    for(int i=1;i<=x.rows();i++)
        for(int j=1;j<=y.columns();j++)
        {
            T sum=x(i,1)*y(1,j);
            for(int k=2;k<=x.columns();k++)
                sum+=x(i,k)*y(k,j);
            z(i,j)=sum;
        }
    return z;
}

