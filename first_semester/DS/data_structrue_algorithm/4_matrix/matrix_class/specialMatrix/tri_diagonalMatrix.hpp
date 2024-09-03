#include<iostream>
using namespace std;

template<class T>
class TriDiagonalMatrix
{
public:
    //构造析构函数
    TriDiagonalMatrix(int theN=10);
    ~TriDiagonalMatrix(){delete[]element;}
    void set(int i,int j,const T& value);
    T& get(int i,int j)const;
private:
    int n;
    T* element;
};

template <class T>
inline TriDiagonalMatrix<T>::TriDiagonalMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");
    n=theN;
    //n+n-1+n-1
    element=new T[3n-2];
}   

template <class T>
inline void TriDiagonalMatrix<T>::set(int i, int j, const T &value)
{
     if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    switch (i-j)
    {
        //低对角线
        case 1:
        {
            element[i-2]=value;
            break;
        }
        //主对角线
        case 0:
        {
            //n-1+i-1
            element[n+i-2]=value;
            break;
        }
        //高对角线
        case -1:
        {
            //n-1+n+i-1
            element[2*n+i-2]=value;
            break;
        }
        default:
        {
            break;
        }
    }

}

//按对角线从低到高排列
template <class T>
inline T &TriDiagonalMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    switch (i-j)
    {
        //低对角线
        case 1:
        {
            return element[i-2];
            break;
        }
        //主对角线
        case 0:
        {
            //n-1+i-1
            return element[n+i-2];
            break;
        }
        //高对角线
        case -1:
        {
            //n-1+n+i-1
            return element[2*n+i-2];
            break;
        }
        default:
        {
            break;
        }
    }
}

