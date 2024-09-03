#include"arrayStack.hpp"
const int N= 1e5+10;
ArrayStack<int>* track;
int numberOfCars,numberOfTracks,smallestCar,itsTrack,inputOrder[N];

bool putCarIntoHodingTrack(int);
void outputCarFromHodingTrack();

bool railRoadReset()
{
    track=new ArrayStack<int>[numberOfTracks+1];

    int nextCar=1;
    smallestCar=N;//随意初始化

    for(int i=1;i<=numberOfCars;i++)
    {
        //如果左侧的车厢是下一个需要输出的车厢,直接从左轨道移到右轨道
        if(inputOrder[i]==nextCar)
        {
            cout<<" move car "<<inputOrder[i]<<" from input track to output track"<<endl;
            nextCar++;

            //再判断轨道中能不能继续输出
            while(smallestCar==nextCar)
            {
                outputCarFromHodingTrack();
                nextCar++;
            }
        }
        //否则移到缓冲轨道
        else
        {
            if(!putCarIntoHodingTrack(inputOrder[i]))
                return false;
        }
    }
    return true;
}

bool putCarIntoHodingTrack(int inputValue)
{
    int bestTrack=0;
    int bestTop=numberOfCars+1;

    //找轨道
    for(int i=1;i<=numberOfTracks;i++)
    {
        if(!track[i].empty())
        {
            int t=track[i].top();
            if(t>inputValue&&t<bestTop)
            {
                bestTop=t;
                bestTrack=i;
            }
        }
        //如果有空轨道,且这个时候还没有找到轨道
        else 
            if(bestTrack==0)bestTrack=i;
    }

    //如果一直找不到轨道, 就返回失败
    if(bestTrack==0)return false;

    //放东西
    track[bestTrack].push(inputValue);
    cout<<" move car "<<inputValue<<" from input track to holding track "<<bestTrack<<endl;
    
    //有无可能更新最小值
    if(inputValue<smallestCar)
    {
        smallestCar=inputValue;
        itsTrack=bestTrack;
    }
    return true;
}


void outputCarFromHodingTrack()
{
    cout<<" move car "<<smallestCar<<" from hoding track "<<itsTrack<<" to output track"<<endl;
    track[itsTrack].pop();
    //更新最小值
    smallestCar=N;
    for(int i=1;i<=numberOfTracks;i++)
    {
        if(!track[i].empty()&&track[i].top()<smallestCar)
        {
            smallestCar=track[i].top();
            itsTrack=i;
        }
    }
}

int main()
{
    cin>>numberOfCars>>numberOfTracks;
    for(int i=1;i<=numberOfCars;i++)
        cin>>inputOrder[i];
    if(railRoadReset())
    cout<<"reSet Successful"<<endl;
    else cout<<"reSet failure"<<endl;
    return 0;
}