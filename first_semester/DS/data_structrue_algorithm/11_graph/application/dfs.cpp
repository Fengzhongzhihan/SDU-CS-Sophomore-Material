#include"linkedDigraph.h"
#include"unweightedEdge.h"
int main()
{
   LinkedDigraph mGraph(10);
   mGraph.insertEdge(new UnWeightedEdge(1,2));
   mGraph.insertEdge(new UnWeightedEdge(2,3));
   mGraph.insertEdge(new UnWeightedEdge(1,4));
   mGraph.insertEdge(new UnWeightedEdge(1,5));
   mGraph.insertEdge(new UnWeightedEdge(6,4));
    auto k=mGraph.findPath(1,5);
}