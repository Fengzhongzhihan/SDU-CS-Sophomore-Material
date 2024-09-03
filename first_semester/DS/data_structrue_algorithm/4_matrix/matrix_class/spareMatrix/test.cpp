#include"spareMatrix.hpp"
int main()
{
    // SparseMatrix<int>s(3,3,3);
    // s.set(2,2,1);
    // s.set(2,3,2);
    // s.set(3,1,1);
    // cout<<s;
    // cout<<s.get(2,2)<<endl;
    // cout<<s.get(2,3)<<endl;
    // cout<<s.get(3,1);
    // return 0;
    SparseMatrix<int>a,b,c;
    cin>>a>>b;
    a.add(b,c);
    cout<<"Matrix a"<<endl;
    cout<<a<<endl;
    cout<<"Matrix b"<<endl;
    cout<<b<<endl;
    cout<<"Matrix a+b"<<endl;
    cout<<c<<endl;
}