#include<iostream>
using namespace std;

const int N=20;
int chessBoard[N][N];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={0,1,-1,1,-1,0,1,-1};

bool checkWin()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            //先找到wang下的棋
            if(chessBoard[i][j]==1)
            {
                for(int k=0;k<8;k++)
                {
                    int count=1;
                    int ni=i+dx[k],nj=j+dy[k];
                    //不是1的时候再停下
                    while(ni>=0&&ni<15&&nj>=0&&nj<15&&chessBoard[ni][nj]==1)
                    {
                        count++;
                        ni+=dx[k];
                        nj+=dy[k];
                    }

                    if(count==4&&ni>=0&&ni<15&&nj>=0&&nj<15&&chessBoard[ni][nj]==0)
                    {
                        return true;
                    }
                }
            }
        }
    }  
    return false;
}

int main()
{
    int m;
    cin>>m;
    string s;

    while(m--)
    {
        for(int i=0;i<15;i++)
        {
            cin>>s;
            for(int j=0;j<15;j++)  
            {   
                chessBoard[i][j]=s[j]-'0';
            }
        }
        if(checkWin())  
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}