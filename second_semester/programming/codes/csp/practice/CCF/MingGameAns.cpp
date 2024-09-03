//
// Created by Lenovo on 2024-03-16.
//
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100+10;//方格图的最大宽度+一个安全量
const int MAXT = 10000;//最长的时间

struct Node{//各个方格的信息
    int row;//行
    int col;//列
    int step;//步数——所用时间
    Node(){}
    Node(int r,int c,int s):row(r),col(c),step(s){}
};

bool visit[MAXN][MAXN][MAXT]={false};//定义时，直接进行初始化
queue<Node>que;
int rows[4]={0,0,1,-1};//上下左右四个方向移动
int cols[4]={1,-1,0,0};

int BFS(int n,int m){
    que.push(Node(1,1,0));//开始时，位于（1,1）且所用时间为0
    Node front,current;
    while(!que.empty()){
        front = que.front();
        que.pop();
        //若队首元素满足调价，返回队首元素的时间
        if(front.row == n && front.col == m){
            return front.step;
        }
        for(int i=0;i<4;i++){
            current.col = front.col + cols[i];
            current.row = front.row + rows[i];
            current.step = front.step + 1;
            //对各点的合法性以及是否被访问过进行判断
            if(current.row<1 || current.col<1 || current.row>n || current.col>m || visit[current.row][current.col][current.step]){
                continue;
            }
            //将该点标记为已访问过并压入队列
            visit[current.row][current.col][current.step] = true;
            que.push(current);
        }
    }
}

int main(){
    int n,m,t,r,c,a,b;
    cin>>n>>m>>t;//按照题目要求进行输入
    for(int i=0;i<t;i++){
        cin>>r>>c>>a>>b;
        for(int j=a;j<=b;j++){
            //将[a,b]时间内(a,b)点的visit都标记为已访问过
            visit[r][c][j]=true;
        }
    }
    int answer = BFS(n,m);//将方格图的行列作为参数传入，以便进行越界判断
    cout<<answer;//输出答案即可
    return 0;
}
