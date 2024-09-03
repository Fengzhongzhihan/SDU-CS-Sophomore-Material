#include<iostream>
using namespace std;

int main()
{
    int numberOfRows=5;
    int length[5]={6,3,4,2,7};

    int **irregularArray=new int *[numberOfRows];

    for(int i=0;i<numberOfRows;i++)
    {
        irregularArray[i]=new int[length[i]];
    }

    irregularArray[2][3]=5;
    irregularArray[4][6]=irregularArray[2][3]+3;
    irregularArray[1][1]=3;
    cout<<irregularArray[2][3]<<endl;
    cout<<irregularArray[4][6]<<endl;
    cout<<irregularArray[1][1]<<endl;
    return 0;
}