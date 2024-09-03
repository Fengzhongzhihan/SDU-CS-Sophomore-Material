#include"adjWdigraph.h"
#include "weightedEdge.h"
int main()
{
    AdjacencyWDigraph<int> mGraph(10,0);
    mGraph.insertEdge(new WeightedEdge<int> (1,2,4));
    mGraph.insertEdge(new WeightedEdge<int> (1,3,4));
    // cout<<mGraph.existsEdge(1,2)<<endl;
    // cout<<mGraph.existsEdge(2,1)<<endl;
    // cout<<mGraph.inDegree(1)<<endl;
    // cout<<mGraph.outDegree(1)<<endl;
    // cout<<mGraph.inDegree(2)<<endl;
    // cout<<mGraph.outDegree(2)<<endl;
    // AdjacencyWDigraph<int>::myIterator* k=mGraph.iterator(1);
    // int weight=0;
    // while(1)
    // {
    //     int t=k->next(weight);
    //     if(t==0)
    //         break;
    //     else 
    //         cout<<t<<" "<<weight<<endl;;
    // }
}