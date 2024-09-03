#include"higherTriangularMatrix.hpp"

//下三角矩阵
template<class T>
class lowerTriangularMatrix
{
public:
    //构造析构函数
    lowerTriangularMatrix(int theN=10);
    lowerTriangularMatrix(const lowerTriangularMatrix<T>&s);
    ~lowerTriangularMatrix(){delete[]element;}
    int size()const {return n;}
    void set(int i,int j,const T& value);
    T get(int i,int j)const;
    T** operator*(const higherTriangularMatrix<T>&x);
    void output(ostream& out);
private:
    int n;
    T* element;
};

template <class T>
inline lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{
    if(theN<1)
        throw ("matrix size must be >0");
    n=theN;
    element=new T[n*(n+1)/2];
}   

template <class T>
inline void lowerTriangularMatrix<T>::set(int i, int j, const T &value)
{
     if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i>=j)
    {
        element[i*(i-1)/2+j-1]=value;
        //按列映射则
        //element[(2n-(j-2))*(j-1)/2+i-j]=value;
    }
    else 
    {
        if(value!=0)
            throw("elements not in lower triangle must be zero");
    }
}
template <class T>
inline lowerTriangularMatrix<T>::lowerTriangularMatrix(const lowerTriangularMatrix<T> &s)
{
    this->n=s.n;
    int len=n*(n+1)/2;
    element=new T[len];
    copy(s.element,s.element+len,element);
}

template <class T>
inline T lowerTriangularMatrix<T>::get(int i, int j) const
{
    if(i<1||i>n||j<1||j>n)
        throw("index out of matrix");
    if(i>=j)
        return element[i*(i-1)/2+j-1];
    else
        return 0;
}

template <class T>
inline T ** lowerTriangularMatrix<T>::operator*(const higherTriangularMatrix<T>&x)
{
    if(this->size()!=x.size())
        throw("dismatch matrix");
    int n=size();
    //创建二维数组
    T ** w=new T*[n];
    for(int i=0;i<n;i++)
        w[i]=new T[n];
    //二维数组赋值
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            T sum=0;
            for(int k=1;k<=n;k++)
            {
                sum+=get(i,k)*x.get(k,j);
            }
            w[i-1][j-1]=sum;
        }
    }
    return w;
}

template <class T>
inline void lowerTriangularMatrix<T>::output(ostream& out)
{
    for(int i=1;i<=size();i++)
    {
        for(int j=1;j<=size();j++)
            out<<get(i,j)<<" ";
        out<<endl;
    }
}
