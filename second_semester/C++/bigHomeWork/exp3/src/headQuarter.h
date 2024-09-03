
// Created by Lenovo on 2024-05-16.
//司令部文件

#ifndef REDANDBLUEAGAINST_HEADQUARTER_H
#define REDANDBLUEAGAINST_HEADQUARTER_H
#include "bits/stdc++.h"
#include "warrior.h"
using namespace std;

//全局变量
int redMakingSeq[6] = {0, 3, 4, 5, 2, 1};
int blueMakingSeq[6] = {0, 4, 1, 2, 3, 5};
int warriorLife[6] = {0};
int warriorAttack[6] = {0};
warrior* city2Warrior[25][2] = {nullptr};//城市对应的武士
map<int ,string>warriorName;//武士的名字
int num, m, n, k, t;
int l1, l2, l3, l4, l5;
int a1, a2, a3, a4, a5;
int minLifeValue = INT_MAX;

class headQuarter{
private:
    int color;//0代表红色，1代表蓝色
    int totalLifeValue; //总生命元
    int warriorsNum[6] = {0};//生成的武士对应的个数
    int makingSeq[6] = {0};
    int curMakingIndex;//当前制造的武士的索引
    int curId;//当前制造的武士的id
    int curHour;//当前小时
    int curMinutes;//当前分钟
    int initialCity;//初始城市, 0表示红色司令部，n+1表示蓝色司令部
    bool Stop;//是否停止制造武士
    bool Taken;//是否被占领
public:
    void makeWarrior();    //制造武士
    headQuarter(int color_);    //构造函数
    ~headQuarter();    //析构函数
    bool isStop() const;
    bool isTaken() const;
    void reportLifeValue();
    void addTime(int extra);
    void printEscapeLion(warrior* theWarrior);
    void printWeapon(warrior *pWarrior);
    void printWarriorBorn(int lifeValue);//打印武士出生信息
    void printWarriorMove(warrior* theWarrior);//打印武士前进信息
    void printTaken(warrior* theWarrior);//打印被占领信息
    void printStealWeapon(wolf *pWolf, warrior *pWarrior, int weaponId, int weaponNum);
    void printDragonYell(warrior * theDragon);//dragon欢呼
    void printKill(warrior *winner, warrior *loser);
    void printBothAlive(warrior *pWarrior, warrior *pWarrior1);
    void printBothDie(warrior *pWarrior, warrior *pWarrior1);
    void setTaken(bool b);
};

headQuarter::headQuarter(int color_) {
    color = color_;
    if (color_ == 0) {
        initialCity = 0;
    } else {
        initialCity = n + 1;
    }
    totalLifeValue = m;
    curMakingIndex = 1;
    curId = 0;
    curHour = 0;
    curMinutes = 0;
    Stop = false;
    Taken = false;
    if (color == 0) {
        for (int i = 0; i < 6; i++) {
            makingSeq[i] = redMakingSeq[i];
        }
    } else {
        for (int i = 0; i < 6; i++) {
            makingSeq[i] = blueMakingSeq[i];
        }
    }
}

void headQuarter::makeWarrior() {
    if (Stop) {//如果已经停止制造武士
        return;
    }
    int lifeValue = warriorLife[makingSeq[curMakingIndex]];//当前制造的武士的生命值
    if (totalLifeValue < lifeValue) {//如果生命元不够
        Stop = true;
        return;
    }
    totalLifeValue -= lifeValue;//生命元减少
    warriorsNum[makingSeq[curMakingIndex]]++;//当前武士的数量增加
    curId++;//当前武士的id
    printWarriorBorn(lifeValue);//打印武士出生信息
    if (makingSeq[curMakingIndex] == 1) {//如果是dragon
        city2Warrior[initialCity][color] = new(dragon)(curId, lifeValue, warriorAttack[1], totalLifeValue, initialCity, color);
    } else if (makingSeq[curMakingIndex] == 2) {//如果是ninja
        city2Warrior[initialCity][color] = new(ninja)(curId, lifeValue, warriorAttack[2], initialCity, color);
    } else if (makingSeq[curMakingIndex] == 3) {//如果是iceman
        city2Warrior[initialCity][color] = new(iceman)(curId, lifeValue, warriorAttack[3], initialCity, color);
    } else if (makingSeq[curMakingIndex] == 4) {//如果是lion
        lion* curLion = new(lion)(curId, lifeValue, totalLifeValue, warriorAttack[4], initialCity, color);
        city2Warrior[initialCity][color] = curLion;
        curLion->printLoyalty();
    } else if (makingSeq[curMakingIndex] == 5) {//如果是wolf
        city2Warrior[initialCity][color] = new(wolf)(curId, lifeValue, warriorAttack[5], initialCity, color);
    }

    //更新当前制造的Index, 映射到1~5
    curMakingIndex = (curMakingIndex + 1) % 6;
    if (curMakingIndex == 0)
        curMakingIndex = 1;
}

void headQuarter::printWarriorBorn(int lifeValue) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "red" : "blue") << " " << warriorName[makingSeq[curMakingIndex]] << " "
         << curId << " born" << endl;
}

void headQuarter::printWarriorMove(warrior* theWarrior) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "red" : "blue") << " " << theWarrior->name << " " << theWarrior->id << " marched to city "
         << theWarrior->city << " with " << theWarrior->lifeValue << " elements and force " << theWarrior->attack << endl;
}

void headQuarter::printTaken(warrior* theWarrior) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "red" : "blue") << " " << theWarrior->name << " " << theWarrior->id << " reached "
         << (color == 0 ? "blue" : "red") << " headquarter with " << theWarrior->lifeValue << " elements and force "
         << theWarrior->attack << endl;
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "blue" : "red") << " headquarter was taken" << endl;
}

headQuarter::~headQuarter() {

}

bool headQuarter::isStop() const {
    return Stop;
}

bool headQuarter::isTaken() const {
    return Taken;
}

void headQuarter::printStealWeapon(wolf *pWolf, warrior *pWarrior, int weaponId, int weaponNum) {
    if (pWolf->weaponNum == 0){
        return;
    }
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "red" : "blue") << " wolf " << pWolf->id << " took ";
    fout << weaponNum << " " << (weaponId == 0 ? "sword" : (weaponId == 1 ? "bomb" : "arrow")) << " from ";
    fout <<  (color == 0 ? "blue" : "red") << " " << pWarrior->name << " " << pWarrior->id << " in city "
         << pWarrior->city << endl;
}


void headQuarter::printDragonYell(warrior * theDragon) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "red" : "blue") << " dragon " << theDragon->id << " yelled in city " << theDragon->city << endl;
}


void headQuarter::printKill(warrior *winner, warrior *loser) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (winner->color == 0 ? "red" : "blue") << " " << winner->name << " " << winner->id << " killed ";
    fout << (loser->color == 0? "red" : "blue") << " " << loser->name << " " << loser->id << " in city "
    << winner->city << " remaining " << winner->lifeValue << " elements" << endl;
}

void headQuarter::printBothAlive(warrior *pWarrior, warrior *pWarrior1) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << "both red " << pWarrior->name << " " << pWarrior->id << " and blue " << pWarrior1->name << " "
         << pWarrior1->id << " were alive in city " << pWarrior->city << endl;
}

void headQuarter::printBothDie(warrior *pWarrior, warrior *pWarrior1) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << "both red " << pWarrior->name << " " << pWarrior->id << " and blue " << pWarrior1->name << " "
         << pWarrior1->id << " died in city " << pWarrior->city << endl;
}

void headQuarter::reportLifeValue() {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << totalLifeValue << " elements in " << (color == 0 ? "red" : "blue") << " headquarter" << endl;
}

void headQuarter::addTime(int extra) {
    curMinutes += extra;
    if (curMinutes >= 60) {
        curMinutes -= 60;
        curHour++;
    }
}


void headQuarter::printWeapon(warrior *pWarrior) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (color == 0 ? "red" : "blue") << " " << pWarrior->name << " " << pWarrior->id << " has ";
    for (int i = 0; i < 3; i++) {
        if (pWarrior->weapons[i] > 0) {
            fout << pWarrior->weapons[i] << " " << (i == 0 ? "sword" : (i == 1 ? "bomb" : "arrow")) << " ";
        }else {
            fout << "0 " << (i == 0 ? "sword" : (i == 1 ? "bomb" : "arrow")) << " ";
        }
    }
    //报告生命
    fout << "and " << pWarrior->lifeValue << " elements" << endl;
}

void headQuarter::printEscapeLion(warrior *theWarrior) {
    fout << setw(3) << setfill('0') << curHour << ":";
    fout << setw(2) << setfill('0') << curMinutes << " ";
    fout << (theWarrior->color == 0 ? "red" : "blue") << " lion " << theWarrior->id << " ran away" << endl;
}

void headQuarter::setTaken(bool b) {
    Taken = b;
}


#endif //REDANDBLUEAGAINST_HEADQUARTER_H
