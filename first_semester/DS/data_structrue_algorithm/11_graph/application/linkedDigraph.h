#include"edge.h"
#include"graph.h"
#include"graphChain.h"

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
                aList[v1].insert(0,v2);
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