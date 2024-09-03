#include"arrayStack.hpp"
int n,m;
const int N=100;
bool st[N][N];
struct position
{
    int row,col;
};

bool findPath()
{
    ArrayStack<position> path;
    int nextRow,nextCol;
    position offset[4];
    offset[0].row=0;offset[0].col=1; //右
    offset[1].row=1;offset[1].col=0; //下
    offset[2].row=0;offset[2].col=-1; //左
    offset[3].row=-1;offset[3].col=0; //上

    //建立(n+2)*(n+2)的迷宫,给边界设置障碍
    for(int i=0;i<=n+1;i++)
    {
        st[0][i]=st[n+1][i]=1;
        st[i][0]=st[i][n+1]=1;
    }
    position here={1,1};
    int option=0,lastOption=3;
    while(here.row!=n||here.col!=n)
    {
        while(option<=lastOption)
        {
            nextRow=here.row+offset[option].row;
            nextCol=here.col+offset[option].col;
            if(!st[nextRow][nextCol])
                break;
            option++;
        }

        //找到了位置
        if(option<=lastOption)
        {
            path.push(here);
            here.row=nextRow;
            here.col=nextCol;
            st[nextRow][nextCol]=1;
            option=0;//继续选择
        }
        //没有找到位置
        else
        {
            
            if(path.empty())
                return false;
            
            position next=path.top();
            path.pop();

            //此时next是原来的位置,here
            //如果是左右平移,退回 下 上
            if(next.row==here.row)
                option=2+next.col-here.col;
            else 
                option=3+next.row-here.row;

            here=next;
        }
    }

    while(!path.empty())
    {
        cout<<path.top().row<<" "<<path.top().col<<endl;
        path.pop();
    }
    return true;
}


int main()
{
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        st[x][y]=1;
    }
    if(findPath())
        cout<<"Success"<<endl;
    else 
        cout<<"Fairlure"<<endl;
    return 0;
}