#pragma once
#include<iostream>
#pragma once
#include<iostream>
using namespace std;

template <class T>
class Edge
{
   public:
      virtual ~Edge() {};
      virtual int vertex1() const = 0;
      virtual int vertex2() const = 0;
      virtual T weight() const = 0;
};


using namespace std;

class UnWeightedEdge: public Edge<bool>
{
    public:
        int vertex1() const
        {
            return v1;
        }
        int vertex2() const
        {
            return v2;
        }
        UnWeightedEdge(int v1,int v2)
        {
            this->v1=v1;
            this->v2=v2;
        }
        bool weight()const 
        { 
            return false;
        }

    protected:
        int v1,v2;
};
#pragma once

#pragma once
#pragma once
#include<iostream>
using namespace std;
#pragma once
#include<iostream>
using namespace std;

template<class T>
class VertexIterator
{
    public:
        virtual ~VertexIterator(){}
        virtual int next()=0;
        virtual int next(T& )=0;
};
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
#pragma once
#pragma once
template<class T>
class chainNode
{
    public:
    T element;
    chainNode<T>* next;

    chainNode(){};

    //两个构造函数
    chainNode(const T& element){this->element=element;}
    chainNode(const T& element,chainNode<T>*next)
    {
        this->element=element;
        this->next=next;
    }
};
#pragma once
#include<iostream>
using namespace std;
template <class T>
class LinearList
{
    public: 
    virtual ~LinearList(){};
    virtual bool empty()const =0;
    virtual int size()const =0;
    virtual T get(int theIndex)const =0;
    virtual int indexOf(const T& x)const =0;
    virtual void erase(int theIndex)=0;
    virtual void insert(int theIndex,const T &x)=0;
    virtual void output(ostream& out)const=0;
    virtual void clear()=0;
    virtual void push_back(const T& x)=0;
};
#include<sstream>
template<class T>
class GraphChain:public LinearList<T>
{
public:
    //似乎没用
    GraphChain()
    {
        firstNode=lastNode=NULL;
        listSize=0;
    }
    GraphChain(int initialCapacity);
    GraphChain(const GraphChain<T>&);
    ~GraphChain();

    //ADT
    bool empty()const  {return listSize==0;}
    int size()const {return listSize;}
    T get(int theIndex)const;
    int indexOf(const T& x)const;
    void erase(int theIndex);
    void insert(int theIndex,const T &x);
    void insertVertex(int theVertex);
    void output(ostream& out)const;
    void checkIndex(int theIndex)const;
    void clear();
    void push_back(const T& x);
    void set(int theIndex,T x); 
    void reverse();
    //新增ADT
    T*  eraseElement(int theVertex);
public:
    chainNode<T>* firstNode;
    chainNode<T>* lastNode;
    int listSize;

};
//赋值构造函数
template<class T>
GraphChain<T>::GraphChain(int initialCapacity)
{
    if(initialCapacity<1)return;
    firstNode=lastNode=NULL;
    listSize=0;
}
//拷贝构造函数
template<class T>
GraphChain<T>::GraphChain(const GraphChain<T>&theList)
{   
    listSize=theList.listSize;
    if(listSize==0)
    {
        firstNode=lastNode=NULL;
        return;
    }
    else
    {
        //先把被copy链表第一个结点作为第一个结点
        //sourceNode:指向被copy的结点
        //targetNode:指向copy链表的尾部结点
        chainNode<T>* sourceNode=theList.firstNode;
        firstNode=new chainNode<T>(sourceNode->element);
        sourceNode=sourceNode->next;
        chainNode<T>* targetNode=firstNode;
        while(sourceNode!=NULL)
        {
            targetNode->next=new chainNode<T>(sourceNode->element);
            targetNode=targetNode->next;
            sourceNode=sourceNode->next;
        }
        targetNode->next=NULL;
        lastNode=targetNode;
    }
}

//检查索引
template<class T>
void GraphChain<T>::checkIndex(int theIndex)const
{
    if(theIndex<0||theIndex>=listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }
}
//析构函数
template<class T>
GraphChain<T>::~GraphChain()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* tmp=firstNode->next;
        delete firstNode;
        firstNode=tmp;
    }
}

//得到元素
template<class T>
T GraphChain<T>::get(int theIndex)const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
    {
        currentNode=currentNode->next;
    }
    return currentNode->element;
}

//查询第一次出现的索引
template<class T>
int GraphChain<T>::indexOf(const T& x)const
{
    chainNode<T>* currentNode=firstNode;
    int index=0;
    while(currentNode!=NULL&&currentNode->element!=x)
    {
        currentNode=currentNode->next;
        index++;
    }
    if(currentNode==NULL)
    return -1;
    else return index;
}

//删除结点
template<class T>
void GraphChain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    //先判断是否删除第0结点
    if(theIndex==0)
    {
        deleteNode=firstNode;
        firstNode=firstNode->next;
    }
    //找到第theIndex-1的位置p
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;

        deleteNode=p->next;
        p->next=deleteNode->next;
    }
    delete deleteNode;
    listSize--;
    chainNode<T>* p=firstNode;
    for(int i=0;i<listSize-1;i++)
    p=p->next;
    lastNode=p;
}

//插入结点
template<class T>
void GraphChain<T>::insert(int theIndex,const T&x)
{
    if(theIndex<0||theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<"size="<<listSize;
        throw(s.str());
    }

    //无需扩容
    if(theIndex==0)
    firstNode=new chainNode<T>(x,firstNode);
    else
    {
        chainNode<T>*p=firstNode;
        for(int i=0;i<theIndex-1;i++)
        p=p->next;
        p->next=new chainNode<T>(x,p->next);
    }
    listSize++;
    chainNode<T>* p=firstNode; 
    for(int i=0;i<listSize-1;i++)
    p=p->next;
    lastNode=p;
}

template<class T>
inline void GraphChain<T>::insertVertex(int theVertex)
{
    //找到theVertex应该待的位置
    chainNode<T>* p= firstNode;
    chainNode<T>* pp=NULL;
    chainNode<T>* newNode=new chainNode<T>(theVertex,NULL);
    //如果链表是空的
    if(p==NULL)
    {
        firstNode=newNode;
    }
    else
    {
        //找到第一个大于thevertex的
        while(p!=NULL&&p->element<theVertex)
        {
            pp=p;
            p=p->next;
        }
        //没有找到,此时pp指向最后一个元素,p指向null
        if(p==NULL)
        {
            pp->next=newNode;
        }
        //如果需要头插
        else if(p==firstNode)
        {
            newNode->next=firstNode;
            firstNode=newNode;
        }
        //如果不需要头插,此时pp指向小于thevertex的元素,p指向大于thevertex的元素
        else
        {
            newNode->next=p;
            pp->next=newNode;
        }
    }
    listSize++;
    return;
}

//输出
template<class T>
void GraphChain<T>::output(ostream& out)const
{
    if(listSize==0)
    {
        out<<"empty";return;
    }
    
    for(chainNode<T>*currentNode=firstNode;currentNode!=NULL;currentNode=currentNode->next)
    {
        out<<currentNode->element<<" ";
    }
}
//重载
template<class T>
ostream& operator<<(ostream& out,const GraphChain<T>x)
{
    x.output(out);return out;
}

//后缀元素
template<class T>
void GraphChain<T>::clear()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
    listSize=0;
}

template<class T>
void GraphChain<T>::push_back(const T&x)
{
    chainNode<T>* newNode=new chainNode<T>(x,NULL);
    if(firstNode==NULL)
        firstNode=lastNode=newNode;
    else
    {
        lastNode->next=newNode;
        lastNode=newNode;
    }
    listSize++;
}

template<class T>
void GraphChain<T>::set(int theIndex,T x)
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    currentNode->element=x;
    return ;
}

template<class T>
void GraphChain<T>::reverse()
{
    chainNode<T>* currentNode=firstNode;
    chainNode<T>* previousNode=NULL;
    chainNode<T>*nextNode=firstNode;
    lastNode=firstNode;
    while(currentNode!=NULL)
    {
        nextNode=currentNode->next;
        currentNode->next=previousNode;
        previousNode=currentNode;
        currentNode=nextNode;
    }
    firstNode=previousNode;
}

template <class T>
inline T*  GraphChain<T>::eraseElement(int theVertex)
{
    chainNode<T> * p= firstNode;
    chainNode<T> *pp=NULL;
    chainNode<T> *returnNode=NULL;
    while(p!=NULL&&p->element!=theVertex)
    {
        pp=p;
        p=p->next;
    }


    if(p==NULL)
        return NULL;

    returnNode=p;

    if(p==firstNode)
    {
        firstNode=p->next;
    }
    else 
    {
        pp->next=p->next;
    }

    listSize--;
    return &returnNode->element;
}


class LinkedDigraph:public graph<bool>
{
    protected:
        int n;
        int e;
        GraphChain<int> *aList; //邻接表

    public:
        LinkedDigraph(int numberOfVertices=0)
        {
            if(numberOfVertices<0)
            {
                cout<<"wrong"<<endl;
                return;
            }
            n=numberOfVertices;
            e=0;
            aList= new GraphChain<int> [n+1];
        }

        ~LinkedDigraph(){delete[] aList;}
        
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
            if(i>=1&&i<=n&&j>=1&&j<=n&&aList[i].indexOf(j)!=-1)
                return true;
            else 
                return false;
        }

        void insertEdge(Edge<bool>* theEdge)
        {
            int v1=theEdge->vertex1();
            int v2=theEdge->vertex2();
            //新边才插入
            if(aList[v1].indexOf(v2)==-1)
            {
                e++;             
                aList[v1].insertVertex(v2);
            }
        }

        void eraseEdge(int i,int j)
        {

            if(i>=1&&i<=n&&j>=1&&j<=n)
            {
                int *v=aList[i].eraseElement(j);
                if(v!=NULL)
                    e--;
            }
        }

        int inDegree(int theVertex) const
        {
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                if(aList[i].indexOf(theVertex)!=-1)
                    sum++;
            }
            return sum;
        }
        int outDegree(int theVertex)const
        {
            if(theVertex>=1&&theVertex<=n)
                return aList[theVertex].size();
            else 
                return 0;
        }
        bool directed()const
        {
            return true;
        }
        bool weighted()const
        {
            return false;
        }
        class myIterator : public VertexIterator<bool>
      {
         public:
            myIterator(chainNode<int> *theNode) 
            {
                currentNode = theNode;
            }
      
            ~myIterator() {}
      
            int next()
            {
               if (currentNode == NULL)
                  return 0;
               int nextVertex = currentNode->element;
               currentNode = currentNode->next;
               return nextVertex;
            }
      
            int next(bool& theWeight)
            {
               if (currentNode == NULL)
                  return 0;
               int nextVertex = currentNode->element;
               currentNode = currentNode->next;
               theWeight = true;
               return nextVertex;
            }
      
         protected:
            chainNode<int> *currentNode;
      };

      myIterator* iterator(int theVertex)
      {// Return iterator for vertex theVertex.
            if(theVertex>=1&&theVertex<=n)
                return new myIterator(aList[theVertex].firstNode);
            else 
                return NULL;
      }
};

class LinkedGraph:public LinkedDigraph
{
    public:
        using LinkedDigraph::aList;
        LinkedGraph(int numberOfVertices=0):LinkedDigraph(numberOfVertices){}

        bool directed()const {return false;}

        void insertEdge(Edge<bool>* theEdge)
        {
            int pre=e;

            LinkedDigraph::insertEdge(theEdge);
            //如果增加边了,则增加相同的边
            if(e>pre)
            {
                LinkedDigraph::insertEdge(new UnWeightedEdge(theEdge->vertex2(),
                theEdge->vertex1()));
                e--;
            }
        }
        void eraseEdge(int i,int j)
        {
            int pre=e;
            LinkedDigraph::eraseEdge(i,j);
            //如果减少边了,那么就再减少
            if(e<pre)
            {
                LinkedDigraph::eraseEdge(j,i);
                e++;
            }
        }
};
#include<cstring>
int n,m,s,t;
const int N=100010;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s>>t;
    LinkedGraph mGraph(n);
    int op,u,v;
    while(m--)
    {
        cin>>op>>u>>v;
        //增加一条边
        if(op==0)
        {
            mGraph.insertEdge(new UnWeightedEdge(u,v));
        }
        else 
        {
            mGraph.eraseEdge(u,v);
        }
    }

    int c[n+1]={0};
    //输出连通分量
    cout<<mGraph.lableComponents(c)<<endl;

    //输出所有连通子图最小点的标号
    bool st[n+1]={false};
    for(int i=1;i<=n;i++)
    {
        if(st[c[i]]==false)
        {
            cout<<i<<" ";
            st[c[i]]=true;
        }
    }
    cout<<endl;

    //输出从s点开始的dfs序列长度
    for(int i=0;i<=n;i++)
        c[i]=0;
    cout<<mGraph.ldfs(s,c)<<endl;

    //输出从s点开始的dfs序列
    for(int i=0;i<=n;i++)
        c[i]=0;
    mGraph.rdfs(s,c);
    cout<<endl;

    //输出从t点开始的bfs序列长度
     for(int i=0;i<=n;i++)
        c[i]=0;
    cout<<mGraph.lbfs(t,c)<<endl;

    //输出从t点开始的bfs序列

    for(int i=0;i<=n;i++)
        c[i]=0;
    mGraph.rbfs(t,c);
    cout<<endl;

    //输出最短路径
    for(int i=0;i<=n;i++)
        c[i]=0;
    int path[n+1]={0};
    
    cout<<mGraph.findMinPath(s,t,path,c);
}