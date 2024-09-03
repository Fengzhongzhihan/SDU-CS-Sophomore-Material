#include<iostream>
using namespace std;
int n;
template <class T>
class MySort
{
private:
    T* a=new T[n];
    T* r=new T[n];
public:
    ~MySort(){delete[]a,delete[] r;}
    void set_element(T x,int index)
        {
            a[index]=x;
        }   
    T get_element(int index)
        {
            return a[index];
        }
    T get_r_element(int index)
    {
        return r[index];
    }
public:
    void rank_compute()
    {
        for(int i=0;i<n;i++)
        r[i]=0;
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
            if(a[j]<=a[i])
            r[i]++;
            else r[j]++;
    }
    void rank_sort()
    {
        T *u= new T[n];
        for(int i=0;i<n;i++)
        u[r[i]]=a[i];
        for(int i=0;i<n;i++)
        a[i]=u[i];
        delete[] u;
    }
    void improve_seletion_sort()
    {
        bool sort=false;
        for(int i=n-1;i>=1&&!sort;i--)
    {
        sort=true;
        int indexOfMax=0;
        for(int j=1;j<i+1;j++)
        if(a[j]>a[indexOfMax])
        {
            indexOfMax=j;
        }
        else sort=false;
        swap(a[i],a[indexOfMax]);
    }
    }
    void improve_bubble_sort()
    {
        bool sort=false;
        for(int i=n-1;i>=1&&!sort;i--)
        {
            sort=true;
            for(int j=0;j<i;j++)
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                sort=false;
            }
        }
    }
    void insert_sort()
    {
        for(int i=1;i<n;i++)
        {
            int x=a[i];
            int j;
            for(j=i-1;j>=0&&a[j]>x;j--)
                a[j+1]=a[j];    
            a[j+1]=x;
        }
    }   
};


int main()
{
    cin>>n;
    MySort<int> m_sort;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m_sort.set_element(x,i);
    }
    m_sort.insert_sort();
    for(int i=0;i<n;i++)
    cout<<m_sort.get_element(i)<<" ";
    return 0;
}