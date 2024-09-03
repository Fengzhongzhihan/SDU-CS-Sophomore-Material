#pragma once
#include"graph.h"
#include"edge.h"
#include"vertexIterator.h"
#include<iostream>
using namespace std;

template <class T>
void make2dArray(T ** &x, int numberOfRows, int numberOfColumns)
{
    x = new T * [numberOfRows];
    
    // get memory for each row
    for (int i = 0; i < numberOfRows; i++)
        x[i] = new int [numberOfColumns];
}


template<class T>
class AdjacencyWDigraph :public graph<T>
{

    protected:
        int n;
        int e;
        T ** arr;
        T noEdge;

    public:
        bool checkVertex(int theVertex)const 
        {
            if(theVertex>=1&&theVertex<=n)
                return true;
            else 
                return false;
        }
        AdjacencyWDigraph(int numberOfVertices=0, T theNoEdge=0)
        {
            if(numberOfVertices<0)
            {
                cout<<"wrongVertices"<<endl;
                return;
            }
            n=numberOfVertices;
            e=0;
            noEdge=theNoEdge;
            make2dArray(arr,n+1,n+1);

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    arr[i][j]=noEdge;
            }
        }
        int numberOfVertices()const
        {
            return n;
        }
        int numberOfEdges()const
        {
            return e;
        }
        bool existsEdge(int i,int j)const
        {
            if(checkVertex(i)&&checkVertex(j)&&arr[i][j]!=noEdge)
                return true;
            else
                return false;
        }
        void insertEdge(Edge<T>* theEdge)
        {
            int v1=theEdge->vertex1();
            int v2=theEdge->vertex2();
            if(checkVertex(v1)&&checkVertex(v2))
            {
                if(arr[v1][v2]==noEdge)
                     e++;
                arr[v1][v2]=theEdge->weight();
            }
        }
        void eraseEdge(int i,int j)
        {
            if(checkVertex(i)&&checkVertex(j)&&arr[i][j]!=noEdge)
            {
                arr[i][j]=noEdge;
                e--;
            }
            else 
            {
                cout<<"no right edge"<<endl;
                return;
            }
        }

        int inDegree(int theVertex) const
        {
            if(checkVertex(theVertex))
            {
                int sum=0;
                for(int j=1;j<=n;j++)
                    if(arr[j][theVertex]!=noEdge) 
                        sum++;

                return sum;
            }
            return 0;
        }

        int outDegree(int theVertex)const
        {
            if(checkVertex(theVertex))
            {
                int sum=0;
                for(int j=1;j<=n;j++)
                    if(arr[theVertex][j]!=noEdge) 
                        sum++;

                return sum;
            }
            return 0;
        }

        bool directed()const
        {
            return true;
        }

        bool weighted()const
        {
            return true;
        }
        class myIterator:public VertexIterator<T>
        {
            public:
                myIterator(T * theRow,T theNoEdge, int numberOfVertices)
                {
                    row=theRow;
                    noEdge=theNoEdge;
                    n=numberOfVertices;
                    currentVertex=1;
                }

                ~myIterator(){}

                int next(T & theWeight)
                {
                    //寻找下一个邻接顶点,并找出对应的权
                    for(int j=currentVertex;j<=n;j++)
                    {
                        if(row[j]!=noEdge)
                        {
                            currentVertex=j+1;
                            theWeight=row[j];
                            return j;
                        }
                    }
                    //找不到邻接节点了
                    currentVertex=n+1;
                    return 0;
                }

                int next()
                {
                    //寻找下一个邻接顶点,并找出对应的权
                    for(int j=currentVertex;j<=n;j++)
                    {
                        if(row[j]!=noEdge)
                        {
                            currentVertex=j+1;
                            return j;
                        }
                    }
                    //找不到邻接节点了
                    currentVertex=n+1;
                    return 0;
                }

            protected:
                T* row; //找到某个顶点的对应的行
                T noEdge;
                int n;
                int currentVertex;
        };

        myIterator* iterator(int theVertex)
        {
            if(checkVertex(theVertex))
                return new myIterator(arr[theVertex],noEdge,n);
            else 
                return NULL;
        }
};
