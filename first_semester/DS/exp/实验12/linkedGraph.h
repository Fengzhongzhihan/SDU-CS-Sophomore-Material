#pragma once
#include"linkedDigraph.h"
#include"unweightedEdge.h"


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