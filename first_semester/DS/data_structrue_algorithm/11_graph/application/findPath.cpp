#include"linkedDigraph.h"
#include"unweightedEdge.h"
int main()
{
   LinkedDigraph mGraph(10);
   mGraph.insertEdge(new UnWeightedEdge(1,2));
   mGraph.insertEdge(new UnWeightedEdge(2,3));
   mGraph.insertEdge(new UnWeightedEdge(3,4));
   mGraph.insertEdge(new UnWeightedEdge(4,5));
   mGraph.insertEdge(new UnWeightedEdge(6,4));
//    int  reach[11]={0};
//     int lable=666; 
//    mGraph.bfs(6,reach,lable); 
    auto k=mGraph.findPath(1,3);
    if(k!=NULL)
    for(int i=0;i<=10;i++)
        cout<<k[i]<<" ";
    
}