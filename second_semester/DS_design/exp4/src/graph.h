//
// Created by Lenovo on 2024-05-06.
//

#ifndef NETWORKAMPIFIER_GRAPH_H
#define NETWORKAMPIFIER_GRAPH_H
#include "bits/stdc++.h"
#include "windows.h"
using namespace std;
const int N = 1e3 + 10;

class Node{
public :
    Node * parent;
    int press, lever, cnt;
    bool status;
    Node (Node *parent, int press, int lever, int cnt, bool status) : parent(parent), press(press), lever(lever), cnt(cnt), status(status) {}
    Node () {}
};

class compare{
public:
    bool operator()(const Node* a, const Node* b) {
        return a->cnt > b->cnt;
    }

};

class Graph{
public:
    int n, m, pMax; // n����, m����, pMax���ѹ��
    int e[N], h[N], ne[N], idx, w[N]; // �ڽӱ�
    int ans ;// ���մ�
    int inDegree[N],topS[N];// ���, ��������
    int p[N]; int tmpP[N];// p[i]��ʾi���ѹ��, tmpP[i]��ʾi�����ʱѹ��
    double runTime;// ����ʱ��
    void add(int a, int b, int c) ;// ��ӱ�
    Graph(int n, int m, int pMax) ;// ���캯��
    Graph() {}
    void init();
    bool status[N]; // ����״̬
    bool st[N]; // ѡ��״̬
    void topSort() ;// ��������
    void solve1(int index);// ���ݷ�
    void solve2(int index);// ��֧���編
    void dfs1(int l, int cnt);// ���ݷ�
    void branchBound();// ��֧���編
    void visualize(int index);// ���ӻ�
    void readFile(string path);// ��ȡ�ļ�
    bool compareFile(string path);// �Ƚ��ļ�
    int mxSize = 0;// ���ѵĴ�С
};

void Graph::topSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        topS[++cnt] = t;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            inDegree[j]--;
            if (inDegree[j] == 0) {
                q.push(j);
            }
        }
    }
    if (cnt != n) {
        cout << "�������򲻴���" << endl;
    }
}

//���ݷ�
void Graph::solve1(int index) {
    //��������ʱ��
    LARGE_INTEGER start_time, end_time;   //��ʼ�ͽ���ʱ��
    double dqFreq;            //��ʱ��Ƶ��
    LARGE_INTEGER freq;       //��ʱ��Ƶ��
    QueryPerformanceFrequency(&freq);
    dqFreq = (double)freq.QuadPart;
    QueryPerformanceCounter(&start_time); //��ʱ��ʼ

    topSort();
    status[1] = true;
    p[1] = pMax;
    tmpP[1] = pMax;
    dfs1(2, 0);
    mxSize = n;

    ofstream sfile(to_string(index) + "solve1Size.out", ios::trunc);
    sfile << mxSize << endl;
    QueryPerformanceCounter(&end_time); //��ʱend
    runTime = (end_time.QuadPart - start_time.QuadPart) / dqFreq * 1000;
    ofstream ofile(to_string(index) + "solve1y.out", ios::trunc);
    ofile << runTime;
//    visualize(index);
}

//��֧���編
void Graph::solve2(int index) {
    LARGE_INTEGER start_time, end_time;   //��ʼ�ͽ���ʱ��
    double dqFreq;            //��ʱ��Ƶ��
    LARGE_INTEGER freq;       //��ʱ��Ƶ��
    QueryPerformanceFrequency(&freq);
    dqFreq = (double)freq.QuadPart;
    QueryPerformanceCounter(&start_time); //��ʱ��ʼ

    topSort();
    branchBound();

    ofstream sfile(to_string(index) + "solve2Size.out", ios::trunc);
    sfile << mxSize << endl;
    QueryPerformanceCounter(&end_time); //��ʱend
    runTime = (end_time.QuadPart - start_time.QuadPart) / dqFreq * 1000;
    ofstream ofile(to_string(index) + "solve2y.out", ios::trunc);
    ofile << runTime ;
//    visualize(index);
}

void Graph::add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
    inDegree[b]++;
}

void Graph::init() {
    memset(h, -1, sizeof h);
    memset(inDegree, 0, sizeof inDegree);
    memset(p, 0, sizeof p);
    memset(topS, 0, sizeof topS);
    memset(status, false, sizeof status);
    memset(st, false, sizeof st);
    memset(w, 0, sizeof(w));
    memset(e, 0, sizeof(e));
    memset(ne, 0, sizeof(ne));
    memset(tmpP, 0, sizeof tmpP);
    idx = 0;
    ans = INT_MAX;
}

//����Ŀǰ���u����û��ǲ�����
void Graph::dfs1(int l, int cnt) {
    int u = topS[l]; // u�����ڵĽ��, ����ֻ�������Ժ�������Ӱ��
    if (l > n) { // �������, ����
        ans = min (ans, cnt);
        memcpy(status, st, sizeof st);
        memcpy(p, tmpP, sizeof tmpP);
        return;
    }

    //�ҵ�u��ǰ���ڵ����Сֵ
    int pre = INT_MAX;
    for (int k = 1; k <= l - 1; k++) {
        for (int i = h[topS[k]]; i != -1; i = ne[i]) {
            int j = e[i];
            if (j == u) {
                pre = min (pre, tmpP[topS[k]] - w[i]);
            }
        }
    }

    //�ҵ�u�ĺ�������Ƿ���� < 0 �����
    bool flag = false;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (pre - w[i] < 0) {
            flag = true;
            break;
        }
    }

    //���������Ҫ����u
    if (pre < 0 || flag) {
        st[u] = true;
        tmpP[u] = pMax;
        //��֦
        if (++cnt >= ans) {
            return;
        }
        dfs1(l + 1, cnt);
    }
    else {
        //�ɷ��ÿɲ�����

        //������
        st[u] = false;
        tmpP[u] = pre;
        //��֦
        if (cnt >= ans) {
            return;
        }
        dfs1(l + 1, cnt);
        //����
        st[u] = true;
        tmpP[u] = pMax;
        //��֦
        if (++cnt >= ans) {
            return;
        }
        dfs1(l + 1, cnt);
    }
}

void Graph::branchBound() {
    priority_queue<Node*, vector<Node*>, compare> heap;
    int mx = 0;
    Node *activePoint = new Node(nullptr, pMax, 2, 0, false);
    int level = 2;
    while (level <= n - 1) {
       int u = topS[level];
       int pre = INT_MAX;
        for (int k = 1; k <= level - 1; k++) {
            for (int i = h[topS[k]]; i != -1; i = ne[i]) {
                int j = e[i];
                if (j == u) {
                    auto t = activePoint;
                    //��activePoint �ƶ�����Ӧ�Ľ����
                    for (int v = level - 1; v > k; v--) {
                       t = t ->parent;
                    }
                    pre = min(pre, t->press - w[i]);
                }
            }
       }

        bool flag = false;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (pre - w[i] < 0) {
                flag = true;
                break;
            }
        }

        Node *newNode;
        if (pre < 0 || flag) {
            //����
            newNode = new Node(activePoint, pMax, activePoint->lever + 1, activePoint->cnt + 1, true);
            heap.push(newNode);
        }
        else {
            //������
            newNode = new Node(activePoint, pre, activePoint->lever + 1, activePoint->cnt, false);
            heap.push(newNode);
            //����
            newNode = new Node(activePoint, pMax, activePoint->lever + 1, activePoint->cnt + 1, true);
            heap.push(newNode);
        }

        activePoint = heap.top();
        heap.pop();
        level = activePoint->lever;
        if (heap.size() > mx) {
            mx = heap.size();
        }
    }

    mxSize = mx;
    ans = activePoint->cnt;
    auto t = activePoint;
    while (t) {
        status[topS[t->lever - 1]] = t->status;
        t = t->parent;
    }
}

void Graph::visualize(int index) {
    ofstream out("graph" + to_string(index) + ".dot", ios::trunc);
    out<<"digraph G{"<<endl;
    //��־��
    for (int i = 1; i <= n; i++) {
        out<<i<<"[label=\""<<i<<", "<<p[i]<<"\"]"<<endl;
    }
    //���ӱ�
    for (int i = 1; i <= n; i++) {
        //�����õĵ�����Բȫ�����
        if (status[i]) {
            out<<i<<"[style = filled,fillcolor=red]"<<endl;
        }
        for (int j = h[i]; j != -1; j = ne[j]) {
            int k = e[j];
            out<<i<<"->"<<k<<"[label=\""<<w[j]<<"\"]"<<endl;
        }
    }
    out<<"}"<<endl;
    fclose(stdout);
    string cmd = "dot -Tpng graph" + to_string(index) + ".dot -o graph" + to_string(index) + ".png";
    system(cmd.c_str());
}

void Graph::readFile(string path) {
    ifstream inf(path, ios::in);
    inf >> n >> m >> pMax;
    for (int i = 0 ; i < m ; i++) {
        int a, b , c;
        inf >> a >> b >> c;
        add(a, b, c);
    }
}

bool Graph::compareFile(string path) {
    ifstream inf(path, ios::in);
    int res;
    inf >> res;
    if (res != ans) {
        return false;
    }
    else {
        return true;
    }
}

Graph::Graph(int n, int m, int pMax) {
    this->n = n;
    this->m = m;
    this->pMax = pMax;
    init();
}

#endif //NETWORKAMPIFIER_GRAPH_H
