#include"linkedDigraph.h"
#include"unweightedEdge.h"
int main()
{
   LinkedDigraph mGraph(10);
   mGraph.insertEdge(new UnWeightedEdge(1,2));
   mGraph.insertEdge(new UnWeightedEdge(2,3));
   mGraph.insertEdge(new UnWeightedEdge(1,4));
   mGraph.insertEdge(new UnWeightedEdge(5,7));
   mGraph.insertEdge(new UnWeightedEdge(6,8));
   
   int c[11]={0};
   cout<<mGraph.lableComponents(c);
}