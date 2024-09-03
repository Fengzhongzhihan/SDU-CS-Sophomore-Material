//第一种解决方法
//初始化
int n;
int * equivClass;
void initialize(int numberOfIndex)
{
    n=numberOfIndex;
    equivClass=new int[n+1];
    for(int e=1;e<=n;e++)
        equivClass[e]=e;
}
//合并类classA和classB,假设两类并不相同
void unite(int classA,int classB)
{
    for(int k=1;k<=n;k++)
        if(equivClass[k]==classB)
            equivClass[k]=classA;
}
//找到某个元素的类
int find(int e)
{
    return equivClass[e];
}
//第二种解决方法

