#include<iostream>
#include"arrayQueue.hpp"

using namespace std;

template<class T>
void calCulateOutDegree(graph<T> &g)
{
    int n=g.numberOfVertices();
    int *outDegree=new int [n+1];
    fill(outDegree+1, outDegree+1+n, 0);

    //遍历每一个点
    for(int i=1;i<=n;i++)
    {
        VertexIterator<T> *ii= g.iterator(i);
        //初始化InDegree
        int u;
        while((u=ii->next())!=0)
        {
            outDegree[i]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<outDegree[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    // ArrayQueue<int>q(1);
    // q.push(1);
    // cout<<"front:"<<q.front()<<" back:"<<q.back()<<endl;
    // cout<<"size:"<<q.size()<<endl;
    // q.push(2);
    // cout<<"front:"<<q.front()<<" back:"<<q.back()<<endl;
    // cout<<"size:"<<q.size()<<endl;
    // q.push(3);
    // cout<<"front:"<<q.front()<<" back:"<<q.back()<<endl;
    // cout<<"size:"<<q.size()<<endl;
    // q.pop();
    // cout<<"front:"<<q.front()<<" back:"<<q.back()<<endl;
    // cout<<"size:"<<q.size()<<endl;
    // q.push(4);
    // cout<<"front:"<<q.front()<<" back:"<<q.back()<<endl;
    // cout<<"size:"<<q.size()<<endl;
    // q.push(5);
    // cout<<"front:"<<q.front()<<" back:"<<q.back()<<endl;
    // cout<<"size:"<<q.size()<<endl;
    // return 0;
    cout<<"helloWorld"<<endl;
}
