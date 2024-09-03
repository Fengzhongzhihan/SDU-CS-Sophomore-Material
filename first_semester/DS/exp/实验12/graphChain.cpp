#include"graphChain.h"

int main()
{
    GraphChain<int> g;
    g.insertVertex(2);
    g.insertVertex(1);
    g.insertVertex(3);
    g.insertVertex(5);
    g.insertVertex(4);
    cout<<g<<endl;
}