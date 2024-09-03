#include<iostream>
#include"arrayStack.hpp"
using namespace std;
//表示三个塔
ArrayStack<int>tower[4];

//递归算法
void towersOfHanoi(int n,int x,int y,int z)
{
    //将n盘子从x移到y中
    if(n>0)
    {
        towersOfHanoi(n-1,x,z,y);
        cout<<"move top disk from tower "<<x<<" to tower "<<y<<endl;
        towersOfHanoi(n-1,z,y,x);
    }
}

//栈实现
void moveAndShow(int n,int x,int y,int z)
{
    if(n>0)
    {
        moveAndShow(n-1,x,z,y);
        int d=tower[x].top();
        tower[x].pop();
        tower[y].push(d);
        moveAndShow(n-1,z,y,x);
    }
}
void towerOfHanoiWithStack(int n)
{
    for(int d=n;d>=1;d--)
        tower[1].push(d);
    moveAndShow(n,1,2,3);
    while(!tower[2].empty())
    {
        cout<<tower[2].top()<<endl;
        tower[2].pop();
    }
}




int main()
{
    towerOfHanoiWithStack(4);
    return 0;
}