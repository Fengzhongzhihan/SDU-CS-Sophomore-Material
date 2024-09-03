#include"lowerTriangularMatrix.hpp"
template<class T>
ostream& operator<<(ostream& out,lowerTriangularMatrix<T>x)
{
   x.output(out);
    return out;
}

template<class T>
ostream& operator<<(ostream& out,higherTriangularMatrix<T>x)
{
    x.output(out);
    return out;
}

int main()
{
    lowerTriangularMatrix<int>a(4);
    a.set(1,1,1);
    a.set(2,1,1);a.set(2,2,1);
    a.set(3,1,1);a.set(3,2,1);a.set(3,3,1);
    a.set(4,1,1);a.set(4,2,1);a.set(4,3,1);a.set(4,4,1);
    cout<<"matrix a"<<endl;
    cout<<a;
    higherTriangularMatrix<int>b(4);
    b.set(1,1,2);b.set(1,2,2);b.set(1,3,2);b.set(1,4,2);
    b.set(2,2,2);b.set(2,3,2);b.set(2,4,2);
    b.set(3,3,2);b.set(3,4,2);
    b.set(4,4,2);
    cout<<"matrix b"<<endl;
    cout<<b;

    int n=a.size();
    int ** c=a*b;

    cout<<"matrix a*b"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}