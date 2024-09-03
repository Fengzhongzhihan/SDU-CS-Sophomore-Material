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
                    if(reach[u]==0)
                    {
                        q.push(u);
                        reach[u]=lable;
                    }
                }
                delete iw;
            }
        }
        //求长度
        virtual int lbfs(int v,int reach[])
        {
            length=0;
            this->reach=reach;
            l2bfs(v);
            return length;
        }
        
        virtual void l2bfs(int v)
        {
            reach[v]=1;
            queue<int>q ;
            q.push(v);

            while(!q.empty())
            {
                length++;
                int w=q.front();
                q.pop();
                VertexIterator<T>* iw =iterator(w);
                int u;
                while((u=iw->next())!=0)
                {
                    if(reach[u]==0)
                    {
                        q.push(u);
                        reach[u]=1;
                    }
                }
                delete iw;
            }
        }

        //求序列
        virtual void rbfs(int v,int reach[])
        {
            this->reach=reach;
            r2bfs(v);
        }
        virtual void r2bfs(int v)
        {
            reach[v]=1;
            queue<int>q ;
            q.push(v);
            while(!q.empty())
            {
                int w=q.front();
                q.pop();

                cout<<w<<" ";
                VertexIterator<T>* iw =iterator(w);

                int u;
                while((u=iw->next())!=0)
                {
                    if(reach[u]==0)
                    {
                        q.push(u);
                        reach[u]=1;
                    }
                }
                delete iw;
            }
        }
        //求长度
        int  ldfs(int v,int reach[])
        {
            length=1;
            this->reach=reach;
            l2dfs(v);
            return length;
        }

        void  l2dfs(int v)
        {
            reach[v]=lable;
            VertexIterator<T>* iv=iterator(v);
            int u;
            while((u=iv->next())!=0)
            {
                //没有被遍历过
                if(reach[u]==0)
                {
                    l2dfs(u);
                    length++;
                }
            }
            delete iv;
        }

        void rdfs(int v,int reach[])
        {
            this->reach=reach;
            r2dfs(v);
        }


        void r2dfs(int v)
        {
            cout<<v<<" ";
            reach[v]=lable;
            VertexIterator<T>* iv=iterator(v);
            int u;
            while((u=iv->next())!=0)
            {
                //没有被遍历过
                if(reach[u]==0)
                    r2dfs(u);    
            }
            delete iv;
        }     
        //找最短路径
        int findMinPath(int s,int t,int path[],int reach[])
        {
            int n=numberOfVertices();
            this->path=path;
            this->reach=reach;
        
            length=0;

            queue<int>q;
            reach[s]=1;
            q.push(s);

            while(!q.empty())
            {
                int w=q.front();
                q.pop();

                VertexIterator<bool>* is= iterator(w);

                int u;
                while((u=is->next())!=0)
                {
                    //如果还没有遍历
                    if(reach[u]==0)
                    {
                        //找到了终点
                        if(u==t)
                        {
                            return path[w]+1;
                        }
                        //没到终点,更新从w->u的路
                        else 
                        {
                            path[u]=path[w]+1;
                            reach[u]=1;
                            q.push(u);
                        }
                    }
                }
            }
            return -1;
        }

        int lableComponents(int c[])
        {
            int n=numberOfVertices();
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