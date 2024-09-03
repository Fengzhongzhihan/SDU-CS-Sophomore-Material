#include"linkedDigraph.h"
#include"unweightedEdge.h"
int main()
{
    LinkedDigraph mGraph(10);
    mGraph.insertEdge(new UnWeightedEdge (1,2));
    mGraph.insertEdge(new UnWeightedEdge (1,3));
    mGraph.insertEdge(new UnWeightedEdge (2,1));
    // cout<<mGraph.inDegree(1)<<endl;
    // cout<<mGraph.outDegree(1)<<endl;
    // cout<<mGraph.inDegree(2)<<endl;
    // cout<<mGraph.outDegree(2)<<endl;

    // mGraph.eraseEdge(1,2);
    // cout<<mGraph.inDegree(1)<<endl;
    // cout<<mGraph.outDegree(1)<<endl;
    // cout<<mGraph.inDegree(2)<<endl;
    // cout<<mGraph.outDegree(2)<<endl;

    // auto k=mGraph.iterator(1);
    // while(1)
    // {
    //     int t=k->next();
    //     if(t!=0)
    //         cout<<t<<endl;
    //     else 
    //         break;
    // }


}