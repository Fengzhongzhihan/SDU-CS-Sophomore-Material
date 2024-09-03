#pragma once
#include<iostream>
using namespace std;
#include"edge.h"
#include"vertexIterator.h"
#include<stack>
template<class T>//权的类型
class graph
{
    public:
        virtual ~graph(){};

        virtual int numberOfVertices()const=0;
        virtual int numberOfEdges()const =0;
        virtual bool existsEdge(int ,int )const =0;
        virtual void insertEdge(Edge<T>* )=0;
        virtual void eraseEdge(int ,int)=0;
        virtual int inDegree(int) const =0;
        virtual int outDegree(int )const =0;

        virtual bool directed()const =0;
        virtual bool weighted()const =0;
        virtual VertexIterator<T>* iterator(int )=0;
        /**
         * Generates a topological order for the graph and stores it in the provided array.
         *
         * @param theOrder pointer to an array where the topological order will be stored
         *
         * @return true if a topological order was successfully generated, false otherwise
         *
         * @throws None
         */
        bool topologicalOrder(int *theOrder)
        {
            int n=numberOfVertices();
            int *inDegree=new int [n+1];
            fill(inDegree+1, inDegree+1+n, 0);

            //遍历每一个点
            for(int i=1;i<=n;i++)
            {
                VertexIterator<T> *ii= iterator(i);
                //初始化InDegree
                int u;
                while((u=ii->next())!=0)
                {
                    inDegree[u]++;
                }
            }

            stack<int> s;
            for(int i=1;i<=n;i++)
            {
                if(inDegree[i]==0)
                    s.push(i);
            }
            int j=0;
            while(!s.empty())
            {
                int t=s.top();
                s.pop();
                theOrder[j++]=t;

                VertexIterator<int>* ii=iterator(t);
                int u;
                while((u=ii->next())!=0)
                {
                    inDegree[u]--;
                    if(inDegree[u]==0)
                        s.push(u);
                }
            }  

            return j==n;
        }

        //2 5 1 3 4 6
};