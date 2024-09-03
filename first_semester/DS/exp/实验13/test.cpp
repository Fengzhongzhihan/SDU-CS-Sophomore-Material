#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include<cstdio>
//from yuanzi
//prim
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int dist[N];
bool st[N];

struct graphNode {
    int element;
    graphNode *next;
    int weight;

    graphNode(int e, graphNode *node, int w) {
        element = e;
        next = node;
        weight = w;
    }
};

struct graphChain {
    graphNode *firstNode;
    graphNode *lastNode;
};

class graph {
public:
    graph(int num = 0) {
        node = num;
        edge = 0;
        aList = new graphChain[node + 1];
        for (int i = 0; i <= node; i++) {
            aList[i].firstNode = nullptr;
        }

    }

    ~graph() { delete[]aList; }

    void insert(int v1, int v2, int w);

    long long prim();

private:
    int node;//the number of node
    int edge;//the number of edge
    graphChain *aList;
};

void graph::insert(int v1, int v2, int w) {
    if (aList[v1].firstNode == nullptr) 
    { aList[v1].firstNode = aList[v1].lastNode = new graphNode(v2, nullptr, w); }
    else {

        aList[v1].lastNode->next = new graphNode(v2, nullptr, w);
        aList[v1].lastNode = aList[v1].lastNode->next;
    }

}

long long graph::prim() {

    long long res = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;//小根堆初始化
    heap.push({0, 1});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;
        dist[ver] = 0;
        res += distance;
        for (graphNode *Node = aList[ver].firstNode; Node; Node = Node->next) 
        {
            int j = Node->element;
            if (dist[j] > Node->weight) 
            {
                dist[j] = Node->weight;
            }
            if (!st[j]) heap.push({dist[j], j});
        }
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    int v1, v2, c;
    graph a(n);
    while (m--) {
        cin >> v1 >> v2 >> c;
        a.insert(v1, v2, c);
        a.insert(v2, v1, c);
    }

    cout << a.prim() << endl;

    return 0;
}