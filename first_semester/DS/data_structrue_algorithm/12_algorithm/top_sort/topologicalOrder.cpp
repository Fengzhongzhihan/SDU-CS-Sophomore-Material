#include<iostream>
#include<cstring>
#include<algorithm>
#include"adjWdigraph.h"
#include"weightedEdge.h"

using namespace std;

int main()
{
    int *arr=new int [10];
    AdjacencyWDigraph<int> m_graph(6);
    m_graph.insertEdge(new WeightedEdge<int>(1,4,1));
    m_graph.insertEdge(new WeightedEdge<int>(2,4,1));
    m_graph.insertEdge(new WeightedEdge<int>(2,5,1));
    m_graph.insertEdge(new WeightedEdge<int>(1,3,1));
    m_graph.insertEdge(new WeightedEdge<int>(3,4,1));
    m_graph.insertEdge(new WeightedEdge<int>(3,6,1));
    m_graph.insertEdge(new WeightedEdge<int>(4,6,1));
    m_graph.insertEdge(new WeightedEdge<int>(5,6,1));
    if(m_graph.topologicalOrder(arr))
        for(int i=0;i<m_graph.numberOfVertices();i++)
            cout<<arr[i]<<" ";
    
    return 0;
}