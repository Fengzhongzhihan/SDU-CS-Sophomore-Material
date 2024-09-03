//
// Created by Lenovo on 2024-05-26.
//

#include "bits/stdc++.h"
using namespace std;
// dragon 、ninja、iceman、lion、wolf
//    1     2     3     4      5
class headQuarter{
private:
    int color;//0代表红色，1代表蓝色
    int totalLifeValue; //总生命元
    int warriorsNum[6];//生成的武士对应的个数
    int totalWarriorNum;//生成的武士数量
    int makingSeq[6];//武士的制造顺序
    map<int, string> warriorName;
    int warrior2LifeValue[6] ;//武士对应的生命值
    int curMakingIndex;//当前制造的武士的索引
    int curId;//当前制造的武士的id
    int curTime;//当前时间
    int minLifeValue;//武士最小生命值
    bool Stop;//是否停止制造武士
public:
    //制造武士
    void makeWarrior();
    //构造函数
    headQuarter(int color_, int lifeValue_, int *makingSeq_, int *warrior2LifeValue_);
    bool isStop() const {
        return Stop;
    }
};

headQuarter::headQuarter(int color_, int lifeValue_, int *makingSeq_, int *warrior2LifeValue_) {
    color = color_;
    totalLifeValue = lifeValue_;
    totalWarriorNum = 0;
    curMakingIndex = 1;
    curId = 0;
    curTime = 0;
    Stop = false;
    for(int i = 1; i <= 5; i++){
        warriorsNum[i] = 0;
    }
    for(int i = 1; i <= 5; i++){
        makingSeq[i] = makingSeq_[i];
    }

    minLifeValue = INT_MAX;
    for(int i = 1; i <= 5; i++){
        warrior2LifeValue[i] = warrior2LifeValue_[i];
        minLifeValue = min(minLifeValue, warrior2LifeValue[i]);
    }
    warriorName[1] = "dragon";
    warriorName[2] = "ninja";
    warriorName[3] = "iceman";
    warriorName[4] = "lion";
    warriorName[5] = "wolf";
}

void headQuarter::makeWarrior() {
    if (Stop) {//如果已经停止制造武士
        return;
    }
    if(minLifeValue > totalLifeValue){//如果生命元不够制造最小生命值的武士
        cout << setw(3) << setfill('0') << curTime << " ";
        cout << (color == 0 ? "red" : "blue") << " headquarter stops making warriors" << endl;
        Stop = true;
        return;
    }
    while (totalLifeValue < warrior2LifeValue[makingSeq[curMakingIndex]]) {//找到下一个可以制造的武士
        curMakingIndex = (curMakingIndex + 1) % 6;
        if (curMakingIndex == 0)
            curMakingIndex = 1;
    }
    int lifeValue = warrior2LifeValue[makingSeq[curMakingIndex]];//当前制造的武士的生命值
    totalLifeValue -= lifeValue;//生命元减少
    totalWarriorNum++;
    curId = totalWarriorNum;//当前武士的id
    warriorsNum[makingSeq[curMakingIndex]]++;//当前武士的数量增加
    cout << setw(3) << setfill('0') << curTime << " ";
    cout << (color == 0 ? "red" : "blue") << " " << warriorName[makingSeq[curMakingIndex]] << " "
         << curId << " born with strength " << lifeValue << "," << warriorsNum[makingSeq[curMakingIndex]] << " " <<
         warriorName[makingSeq[curMakingIndex]] << " in " << (color == 0 ? "red" : "blue") << " headquarter" << endl;

    //更新当前制造的Index, 映射到1~5
    curMakingIndex = (curMakingIndex + 1) % 6;
    if (curMakingIndex == 0)
        curMakingIndex = 1;

    curTime++;//时间增加
}

void makeWarriors(headQuarter &redHeadQuarter, headQuarter &blueHeadQuarter){
    while (true) {
        redHeadQuarter.makeWarrior();
        blueHeadQuarter.makeWarrior();
        if (redHeadQuarter.isStop() && blueHeadQuarter.isStop()) {
            break;
        }
    }
}