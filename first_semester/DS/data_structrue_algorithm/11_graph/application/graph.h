#pragma once
#include<iostream>
using namespace std;
#include"edge.h"
#include"vertexIterator.h"
#include<queue>
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

        virtual void bfs(int v,int reach[],int lable)
        {
            queue<int>q ;
            reach[v]=lable;
            q.push(v);

            while(!q.empty())
            {
                int w=q.front();
                q.pop();

                VertexIterator<T>* iw =iterator(w);

                int u;
                while((u=iw->next())!=0)
                {
                    if (reach[u] == 0)
                    {
                        q.push(u);
                        reach[u]=lable;
                    }
                }
                delete iw;
            }
        }

        virtual void dfs(int v,int reach[],int lable)
        {
            this->reach=reach;
            this->lable=lable;
            rdfs(v);
        }
        
        void rdfs(int v)
        {
            reach[v]=lable;
            VertexIterator<T>* iv=iterator(v);
            int u;
            while((u=iv->next())!=0)
            {
                //没有被遍历过
                if(reach[u]==0)
                    rdfs(u);    
            }
            delete iv;
        }
        //成功找到返回Path,否则返回NULL
        int * findPath(int theSource, int theDestination)
        {
            //初始化
            desitination=theDestination;
            int n=numberOfVertices();
            //初始化path,reach
            path=new int [n+1];     
            reach=new int [n+1];
            for(int i=0;i<=n;i++)
            {
                reach[i]=0;
                path[i]=0;
            }
            path[1]=theSource;
            length=1;
            //找到一条路径,则将path[0]更新为边长
            if(theSource==theDestination||dfs(theSource))
            {
                path[0]=length-1;
            }
            else 
            {
                delete[]path;
                path=NULL;
            }

            delete []reach;
            return path;
        }

        bool dfs(int s)
        {
            reach[s]=1;
            VertexIterator<T>* is=iterator(s);

            int u;
            while((u=is->next())!=0)
            {
                if(reach[u]==0)
                {
                    path[++length]=u;
                    if(u==desitination||dfs(u))
                        return true;
                    //如果没有找到从u开始的路径,就把length--,继续找下一个u
                    length--;
                }
            }

            delete is;
            return false;
        }

        int lableComponents(int c[])
        {
            int n=numberOfVertices();

            for(int i=1;i<=n;i++)
                c[i]=0;
            
            lable=0;
            //遍历所有元素
            for(int i=1;i<=n;i++)
            //如果没有被标记
            if(c[i]==0)
            {
                lable++;
                bfs(i,c,lable);
            }
            return lable;
        }

        int desitination;
        int *path;
        int length;
        int* reach;
        int lable;
};