#include<iostream>
using namespace std;

template<class T>
class DiagonalMatrix
{
public:
    //构造析构函数
    DiagonalMatrix(int theN=10);
    ~DiagonalMatrix(){delete[]element;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
private:
    int n;
    T* element;
};

template <class T>
inline DiagonalMatrix<T>::DiagonalMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");

    n=theN;
    element=new T[n];
}   

template <class T>
inline void DiagonalMatrix<T>::set(int i, int j, const T &value)
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i==j)
        element[i-1]=value;
    else
        if(value!=0)
            throw ("nondiagonal elements must be zero");
    return;
}

template <class T>
inline T &DiagonalMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i==j)
        return element[i-1];
    else
        return 0;
}

