#include"linkedDigraph.h"
#include"unweightedEdge.h"
int main()
{
   LinkedDigraph mGraph(10);
   mGraph.insertEdge(new UnWeightedEdge(1,2));
   mGraph.insertEdge(new UnWeightedEdge(2,3));
   mGraph.insertEdge(new UnWeightedEdge(1,4));
   mGraph.insertEdge(new UnWeightedEdge(1,5));
   mGraph.insertEdge(new UnWeightedEdge(1,6));
    mGraph.insertEdge(new UnWeightedEdge(1,7));
    mGraph.insertEdge(new UnWeightedEdge(1,8));
    mGraph.insertEdge(new UnWeightedEdge(1,9));
    mGraph.insertEdge(new UnWeightedEdge(1,10));
   
   int reach[11]={0};

   mGraph.dfs(1,reach,1);

    int flag=0;
   for(int i=1;i<=10;i++)
        if(reach[i]==0)
        {
            cout<<"No"<<endl;
            flag=1;
            break;
        }
    
    if(!flag)
    cout<<"Yes"<<endl;
}