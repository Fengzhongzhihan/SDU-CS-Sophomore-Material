#include "matrix.hpp"

template<class T>
ostream &operator<<(ostream &out, const Matrix<T> &x)
{
    for(int i=1;i<=x.rows();i++)
    {
        for(int j=1;j<=x.columns();j++)
        {
            out<<x.get(i,j)<<" ";
        }
        cout<<endl;
    }
    return out;
}

int main()
{
    Matrix<int> a(2,3);
    Matrix<int> b(3,1);
    a.set(1,1,1);
    a.set(2,1,3);
    a.set(1,2,2);
    a.set(2,2,1);
    a.set(1,3,5);
    a.set(2,3,4);
    cout<<a<<endl;
    b.set(1,1,1);
    b.set(2,1,1);
    b.set(3,1,1);
    cout<<b<<endl;
    cout<<(a*b)<<endl;
    return 0;
}
