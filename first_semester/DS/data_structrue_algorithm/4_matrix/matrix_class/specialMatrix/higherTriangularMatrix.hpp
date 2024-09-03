//下三角矩阵
#include<iostream>
using namespace std;
template<class T>
class higherTriangularMatrix
{
public:
    //构造析构函数
    higherTriangularMatrix(int theN=10);
    higherTriangularMatrix(const higherTriangularMatrix<T>& s);
    ~higherTriangularMatrix(){delete[]element;}
    int size()const {return n;}
    void set(int i,int j,const T& value);
    T get(int i,int j)const;
    void output(ostream& out);
private:
    int n;
    T* element;
};

template <class T>
inline higherTriangularMatrix<T>::higherTriangularMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");
    n=theN;
    //1+2+...+n
    element=new T[n*(n+1)/2];
}

//拷贝构造很重要
template <class T>
inline higherTriangularMatrix<T>::higherTriangularMatrix(const higherTriangularMatrix<T> &s)
{
    this->n=s.n;
    int len=n*(n+1)/2;
    element=new T[len];
    copy(s.element,s.element+len,element);
}

template <class T>
inline void higherTriangularMatrix<T>::set(int i, int j, const T &value)
{
     if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i<=j)
    {
        element[(2*n-(i-2))*(i-1)/2+j-i]=value;
        //按列映射则
        //element[(1 + (j - 1))(j - 1) / 2 + i - 1]=value;
    }
    else 
    {
        if(value!=0)
            throw("elements not in lower triangle must be zero");
    }
}

template <class T>
inline T higherTriangularMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i<=j)
        return element[(2*n-i+2)*(i-1)/2+j-i];
    else
        return 0;
}

template <class T>
inline void higherTriangularMatrix<T>::output(ostream& out)
{
    for(int i=1;i<=size();i++)
    {
        for(int j=1;j<=size();j++)
            out<<get(i,j)<<" ";
        out<<endl;
    }
}
