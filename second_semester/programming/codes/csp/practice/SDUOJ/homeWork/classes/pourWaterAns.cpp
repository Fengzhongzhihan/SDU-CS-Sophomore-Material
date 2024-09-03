//
// Created by Lenovo on 2024-03-17.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int ca,cb,n;//ca和cb分别表示两个杯子的最大容量,n表示目标值。
bool rem[1005][1005];
struct node
{
    int x,y;//x和y代表着a杯和b杯当前的水量
    vector  <int> ans;
};
void bfs(int x,int y){
    memset(rem,0,sizeof(rem));//不要忘了重置标记数组！！！！
    queue  <node> q;//搜索队列
    node ppp;
    ppp.x=x;
    ppp.y=y;
    q.push(ppp);
    while(1){
        node temp;
        temp=q.front();//从队头取出一个搜索状态
        q.pop();
        ///////////////////////////////////////
        if(temp.y==n){//终止条件
            cout<<temp.ans.size()<<" ";//输出步数
            for(int i=0;i<temp.ans.size();i++){
                cout<<temp.ans[i]<<" ";//输出解
            }
            cout<<endl;
            break;
        }
        ///////////////////////////////////////
        if(temp.x!=ca){//处理方式1
            node kater=temp;
            kater.x=ca;//这里由于我ca太菜不会构造函数，所以牺牲了美观性QAQ，别打我。
            kater.ans.push_back(1);//将新构筑出来的状态的操作后面加上个“1”。后面同理。
            if(!rem[kater.x][kater.y]){//如果之前被搜索过就不把他放到队列里
                q.push(kater);
                rem[kater.x][kater.y]=1;//记忆化，防止重搜
            }
        }
        ///////////////////////////////////////
        if(temp.y!=cb){//处理方式2
            node kater=temp;
            kater.y=cb;
            kater.ans.push_back(2);
            if(!rem[kater.x][kater.y]){
                q.push(kater);
                rem[kater.x][kater.y]=1;
            }
        }
        ///////////////////////////////////////
        if(temp.x!=0){//处理方式3
            node kater=temp;
            kater.x=0;
            kater.ans.push_back(3);
            if(!rem[kater.x][kater.y]){
                q.push(kater);
                rem[kater.x][kater.y]=1;
            }
        }
        ///////////////////////////////////////
        if(temp.y!=0){//处理方式4
            node kater=temp;
            kater.y=0;
            kater.ans.push_back(4);
            if(!rem[kater.x][kater.y]){
                q.push(kater);
                rem[kater.x][kater.y]=1;
            }
        }
        ///////////////////////////////////////
        if(temp.y!=0&&temp.x!=ca){//处理方式5
            node kater=temp;
            if(kater.y>ca-kater.x){
                kater.y-=ca-kater.x;
                kater.x=ca;
            }
            else{
                kater.x+=kater.y;
                kater.y=0;
            }//模拟倒水,注意这里的顺序不能反。
            kater.ans.push_back(5);
            if(!rem[kater.x][kater.y]){
                q.push(kater);
                rem[kater.x][kater.y]=1;
            }
        }
        ///////////////////////////////////////
        if(temp.x!=0&&temp.y!=cb){//处理方式6
            node kater=temp;
            if(kater.x>cb-kater.y){
                kater.x-=cb-kater.y;
                kater.y=cb;
            }
            else{
                kater.y+=kater.x;
                kater.x=0;
            }
            kater.ans.push_back(6);
            if(!rem[kater.x][kater.y]){
                q.push(kater);
                rem[kater.x][kater.y]=1;
            }
        }
    }
}
int main(){
    //    freopen("test.in","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>ca>>cb>>n;
        bfs(0,0);
    }
    return 0;
}