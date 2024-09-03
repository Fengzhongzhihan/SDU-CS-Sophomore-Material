//
// Created by Lenovo on 2024-05-21.
//

#include "bits/stdc++.h"
using namespace std;
class warrior{
public:
    bool isChanged;//生命/ 武器状态是否改变
    int lifeValue;//生命值
    int attack;//攻击力
    int color;//颜色
    int id;//编号
    int weaponNum;//武器数量
    int tempWeaponNum;//临时武器数量
    string name;//名字
    int city;//所在城市
    int isUsedArrow = 0;//arrow使用过的次数
    map<int, int> weapons;//编号 -> 数量
    int weaponUseOrder[12];//武器使用顺序
    int curUseWeaponIndex = 0;//当前使用的武器的索引
    warrior(){}
    virtual ~warrior(){}
    void sortWeapons(){
        int idx = 0;
        for (auto &weapon : weapons) {
            for (int i = 0 ; i < weapon.second; i++) {
                weaponUseOrder[idx++] = weapon.first;
            }
        }
        tempWeaponNum = idx;
        curUseWeaponIndex = 0;
    }
    void attackEnemy(warrior * enemy){
        isChanged = false;
        //如果没有武器
        if (weaponNum == 0) {
            return;
        }
        if (curUseWeaponIndex == tempWeaponNum) {
            sortWeapons();
        }
        if (weaponUseOrder[curUseWeaponIndex] == 0) {
            curUseWeaponIndex++;
            //使用sword
            int swordAttack = attack * 2 / 10;
            if (swordAttack == 0 && weapons[1] == 0 && weapons[2] == 0) {
                isChanged = false;
            }else {
                isChanged = true;
                enemy->lifeValue -= swordAttack;
            }
        } else if (weaponUseOrder[curUseWeaponIndex] == 1) {
            curUseWeaponIndex ++;
            //使用bomb
            int bombAttack = attack * 4 / 10;
            isChanged = true;
            enemy->lifeValue -= bombAttack;
            if (name != "ninja") {
                lifeValue -= bombAttack * 5 / 10;
            }
            weaponNum--;
            weapons[1] --;
        } else if (weaponUseOrder[curUseWeaponIndex] == 2){
            curUseWeaponIndex ++;
            //使用arrow
            int arrowAttack = attack * 3 / 10;
            isChanged = true;
            enemy->lifeValue -= arrowAttack;
            if (isUsedArrow == weapons[2]) { //使用次数==武器数量
                weapons[2] --;
                weaponNum--;
                isUsedArrow --;
            }else {
                isUsedArrow++;
            }
        }
    }

    void winWeapon(warrior *enemy) {
        for (int i = 0; i < 3; i++) {
            if (enemy->weapons[i] > 0) {
                int takeNum = enemy->weapons[i];
                if (weaponNum + enemy->weapons[i] > 10) {//不能大于10件
                    takeNum = 10 - weaponNum;
                }
                weapons[i] += takeNum;
                weaponNum += takeNum;
//                enemy->weapons[i] -= takeNum;
//                enemy->weaponNum -= takeNum;
                //考虑拿arrow的情况
                if (i == 2) {
                    int goodArrow = enemy->weapons[i] - enemy->isUsedArrow;
                    if (goodArrow >= takeNum) {
                        isUsedArrow = 0;
                    }else {
                        isUsedArrow = takeNum - goodArrow;
                    }
                }
                if (weaponNum == 10) {
                    break;
                }
            }
        }
    }
};

class dragon: public warrior{
private:
    double morale; //士气
    int weaponID; //武器编号
    bool isUsed; // arrow是否已经使用过
public:
    dragon(int id_, int lifeValue_, int attack_, double remainingLifeValue, int city_, int color_){
        id = id_;
        weaponID = id % 3;
        if (weaponID == 0) {//sword
            weapons[0] = 1;
        } else if (weaponID == 1) {//bomb
            weapons[1] = 1;
        } else {//arrow
            weapons[2] = 1;
        }
        lifeValue = lifeValue_;
        attack = attack_;
        morale = remainingLifeValue / lifeValue_;
        name = "dragon";
        city = city_;
        color = color_;
        weaponNum = 1;
        isUsed = false;
    }
    double getMorale(){
        return morale;
    }
    int getWeaponID(){
        return weaponID;
    }
};
class ninja: public warrior{
private:
    int weaponID1;
    int weaponID2;
public:
    ninja(int id_, int lifeValue_, int attack_, int city_, int color_){
        id = id_;
        attack = attack_;
        lifeValue = lifeValue_;
        weaponID1 = id % 3;
        weaponID2 = (id + 1) % 3;
        if (weaponID1 == 0) {//sword
            weapons[0] = 1;
        } else if (weaponID1 == 1) {//bomb
            weapons[1] = 1;
        } else {//arrow
            weapons[2] = 1;
        }
        if (weaponID2 == 0) {//sword
            weapons[0] = 1;
        } else if (weaponID2 == 1) {//bomb
            weapons[1] = 1;
        } else {//arrow
            weapons[2] = 1;
        }
        name = "ninja";
        city = city_;
        color = color_;
        weaponNum = 2;
    }
    int getWeaponID1(){
        return weaponID1;
    }
    int getWeaponID2(){
        return weaponID2;
    }
};
class iceman: public warrior{
private:
    int weaponID;
public:
    iceman(int id_, int lifeValue_, int attack_, int city_, int color_){
        id = id_;
        weaponID = id % 3;
        attack = attack_;
        if (weaponID == 0) {//sword
            weapons[0] = 1;
        } else if (weaponID == 1) {//bomb
            weapons[1] = 1;
        } else {//arrow
            weapons[2] = 1;
        }
        lifeValue = lifeValue_;
        name = "iceman";
        city = city_;
        color = color_;
        weaponNum = 1;
    }
    int getWeaponID(){
        return weaponID;
    }
    void lifeValueDecrease() {
        lifeValue -= lifeValue / 10;
    }
};
class lion: public warrior{
private:
    int loyalty;
    int weaponID;
public:
    lion(int id_, int lifeValue_, int remainingLifeValue, int attack_, int city_, int color_){
        id = id_;
        attack = attack_;
        loyalty = remainingLifeValue;
        lifeValue = lifeValue_;
        weaponID = id % 3;
        if (weaponID == 0) {//sword
            weapons[0] = 1;
        } else if (weaponID == 1) {//bomb
            weapons[1] = 1;
        } else {//arrow
            weapons[2] = 1;
        }
        name = "lion";
        city = city_;
        color = color_;
        weaponNum = 1;
    }
    int getLoyalty(){
        return loyalty;
    }
    void print() {
        cout << "Its loyalty is " << loyalty << endl;
    }
    void loyaltyDecrease(int k){
        loyalty -= k;
    }
};
class wolf: public warrior{
public:
    wolf(int id_, int lifeValue_, int attack_, int city_, int color_){
        id = id_;
        attack = attack_;
        lifeValue = lifeValue_;
        name = "wolf";
        city = city_;
        color = color_;
        weaponNum = 0;
    }
    pair<int, int> stealWeapon(warrior * enemy){
        for (int i = 0; i < 3; i++) {
            if (enemy->weapons[i] > 0) {
                int takeNum = enemy->weapons[i];
                if (weaponNum + enemy->weapons[i] > 10) {//不能大于10件
                    takeNum = 10 - weaponNum;
                }
                if (i == 2) {
                    int goodArrow = enemy->weapons[i] - enemy->isUsedArrow;
                    if (goodArrow >= takeNum) {
                        isUsedArrow = 0;
                    }else {
                        isUsedArrow = takeNum - goodArrow;
                    }
                }
                weapons[i] += takeNum;
                weaponNum += takeNum;
                enemy->weapons[i] -= takeNum;
                enemy->weaponNum -= takeNum;
                //考虑拿arrow的情况

                //返回偷的武器编号和数量
                return make_pair(i, takeNum);
                break;
            }
        }
        return make_pair(-1, -1);
    }
};
//全局变量
warrior* city2Warrior[25][2] = {nullptr};//城市对应的武士
int cityNum = 0;//城市数量
int num, m, n, k, t;
int l1, l2, l3, l4, l5;
int a1, a2, a3, a4, a5;
//备份city2Warrior
warrior *tmp[25][2] = {nullptr};
bool st[25][2] = {false};//标志信息有没有处理过

class headQuarter{
private:
    int color;//0代表红色，1代表蓝色
    map<int, string> warriorName;//武士的名字
    int warrior2LifeValue[6] ;//武士对应的生命值
    int warrior2Attack[6];//武士对应的攻击力
    int totalLifeValue; //总生命元
    int warriorsNum[6];//生成的武士对应的个数
    int totalWarriorNum;//生成的武士数量
    int makingSeq[6];//武士的制造顺序
    int curMakingIndex;//当前制造的武士的索引
    int curId;//当前制造的武士的id
    int curHour;//当前小时
    int curMinutes;//当前分钟
    int initialCity;//初始城市, 0表示红色司令部，n+1表示蓝色司令部
    int minLifeValue;//武士最小生命值
    bool Stop;//是否停止制造武士
    bool Taken;//是否被占领
public:
    void makeWarrior();    //制造武士
    headQuarter(int color_, int lifeValue_, int *makingSeq_, int *warrior2LifeValue_,
                int *warrior2Attack_, int initialCity_);    //构造函数
    ~headQuarter();    //析构函数
    bool isStop() const;
    int getTotalLifeValue() const ;
    bool isTaken() const;
    void printWarriorBorn(int lifeValue);//打印武士出生信息
    void printWarriorMove(warrior* theWarrior);//打印武士前进信息
    void printTaken(warrior* theWarrior);//打印被占领信息
    void printStealWeapon(wolf *pWolf, warrior *pWarrior, int weaponId, int weaponNum);
    void printDragonYell(dragon * theDragon);//dragon欢呼
    void printKill(warrior *winner, warrior *loser);
    void printBothAlive(warrior *pWarrior, warrior *pWarrior1);
    void printBothDie(warrior *pWarrior, warrior *pWarrior1);
    void reportLifeValue();
    void addTime(int extra);
    void printEscapeLion(warrior* theWarrior);
    void printWeapon(warrior *pWarrior);

    void setTaken(bool b);
};

headQuarter::headQuarter(int color_, int lifeValue_, int *makingSeq_, int *warrior2LifeValue_, int *warrior2Attack_, int initialCity_) {
    color = color_;
    if (color_ == 0) {
        initialCity = 0;
    } else {
        initialCity = initialCity_ + 1;
    }
    totalLifeValue = lifeValue_;
    totalWarriorNum = 0;
    curMakingIndex = 1;
    curId = 0;
    curHour = 0;
    curMinutes = 0;
    Stop = false;
    Taken = false;
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
    for (int i = 1; i <= 5; i++) {
        warrior2Attack[i] = warrior2Attack_[i];
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
    int lifeValue = warrior2LifeValue[makingSeq[curMakingIndex]];//当前制造的武士的生命值
    if (totalLifeValue < lifeValue) {//如果生命元不够
        Stop = true;
        return;
    }
    totalLifeValue -= lifeValue;//生命元减少
    totalWarriorNum++;
    warriorsNum[makingSeq[curMakingIndex]]++;//当前武士的数量增加
    curId = totalWarriorNum;//当前武士的id
    printWarriorBorn(lifeValue);//打印武士出生信息
    if (makingSeq[curMakingIndex] == 1) {//如果是dragon
        dragon* curWarrior = new dragon(curId, lifeValue, warrior2Attack[1], totalLifeValue, initialCity, color);
        city2Warrior[initialCity][color] = curWarrior;
    } else if (makingSeq[curMakingIndex] == 2) {//如果是ninja
        ninja* curWarrior = new ninja(curId, lifeValue, warrior2Attack[2], initialCity, color);
        city2Warrior[initialCity][color] = curWarrior;
    } else if (makingSeq[curMakingIndex] == 3) {//如果是iceman
        iceman* curWarrior = new iceman(curId, lifeValue, warrior2Attack[3], initialCity, color);
        city2Warrior[initialCity][color] = curWarrior;
    } else if (makingSeq[curMakingIndex] == 4) {//如果是lion
        lion* curWarrior = new lion(curId, lifeValue, totalLifeValue, warrior2Attack[4], initialCity, color);
        city2Warrior[initialCity][color] = curWarrior;
        curWarrior->print();
    } else if (makingSeq[curMakingIndex] == 5) {//如果是wolf
        wolf* curWarrior = new wolf(curId, lifeValue, warrior2Attack[5], initialCity, color);
        city2Warrior[initialCity][color] = curWarrior;
    }

    //更新当前制造的Index, 映射到1~5
    curMakingIndex = (curMakingIndex + 1) % 6;
    if (curMakingIndex == 0)
        curMakingIndex = 1;
}



void headQuarter::printWarriorBorn(int lifeValue) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "red" : "blue") << " " << warriorName[makingSeq[curMakingIndex]] << " "
         << curId << " born" << endl;
}

void headQuarter::printWarriorMove(warrior* theWarrior) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "red" : "blue") << " " << theWarrior->name << " " << theWarrior->id << " marched to city "
         << theWarrior->city << " with " << theWarrior->lifeValue << " elements and force " << theWarrior->attack << endl;
}

void headQuarter::printTaken(warrior* theWarrior) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "red" : "blue") << " " << theWarrior->name << " " << theWarrior->id << " reached "
         << (color == 0 ? "blue" : "red") << " headquarter with " << theWarrior->lifeValue << " elements and force "
         << theWarrior->attack << endl;
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "blue" : "red") << " headquarter was taken" << endl;
}

headQuarter::~headQuarter() {

}

bool headQuarter::isStop() const {
    return Stop;
}

int headQuarter::getTotalLifeValue() const {
    return totalLifeValue;
}

bool headQuarter::isTaken() const {
    return Taken;
}

void headQuarter::printStealWeapon(wolf *pWolf, warrior *pWarrior, int weaponId, int weaponNum) {
    if (pWolf->weaponNum == 0){
        return;
    }
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "red" : "blue") << " wolf " << pWolf->id << " took ";
    cout << weaponNum << " " << (weaponId == 0 ? "sword" : (weaponId == 1 ? "bomb" : "arrow")) << " from ";
    cout <<  (color == 0 ? "blue" : "red") << " " << pWarrior->name << " " << pWarrior->id << " in city "
         << pWarrior->city << endl;
}


void headQuarter::printDragonYell(dragon * theDragon) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "red" : "blue") << " dragon " << theDragon->id << " yelled in city " << theDragon->city << endl;
}


void headQuarter::printKill(warrior *winner, warrior *loser) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (winner->color == 0 ? "red" : "blue") << " " << winner->name << " " << winner->id << " killed ";
    cout << (loser->color == 0? "red" : "blue") << " " << loser->name << " " << loser->id << " in city "
         << winner->city << " remaining " << winner->lifeValue << " elements" << endl;
}

void headQuarter::printBothAlive(warrior *pWarrior, warrior *pWarrior1) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << "both red " << pWarrior->name << " " << pWarrior->id << " and blue " << pWarrior1->name << " "
         << pWarrior1->id << " were alive in city " << pWarrior->city << endl;
}

void headQuarter::printBothDie(warrior *pWarrior, warrior *pWarrior1) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << "both red " << pWarrior->name << " " << pWarrior->id << " and blue " << pWarrior1->name << " "
         << pWarrior1->id << " died in city " << pWarrior->city << endl;
}

void headQuarter::reportLifeValue() {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << totalLifeValue << " elements in " << (color == 0 ? "red" : "blue") << " headquarter" << endl;
}

void headQuarter::addTime(int extra) {
    curMinutes += extra;
    if (curMinutes >= 60) {
        curMinutes -= 60;
        curHour++;
    }
}


void headQuarter::printWeapon(warrior *pWarrior) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (color == 0 ? "red" : "blue") << " " << pWarrior->name << " " << pWarrior->id << " has ";
    for (int i = 0; i < 3; i++) {
        if (pWarrior->weapons[i] > 0) {
            cout << pWarrior->weapons[i] << " " << (i == 0 ? "sword" : (i == 1 ? "bomb" : "arrow")) << " ";
        }else {
            cout << "0 " << (i == 0 ? "sword" : (i == 1 ? "bomb" : "arrow")) << " ";
        }
    }
    //报告生命
    cout << "and " << pWarrior->lifeValue << " elements" << endl;
}

void headQuarter::printEscapeLion(warrior *theWarrior) {
    cout << setw(3) << setfill('0') << curHour << ":";
    cout << setw(2) << setfill('0') << curMinutes << " ";
    cout << (theWarrior->color == 0 ? "red" : "blue") << " lion " << theWarrior->id << " ran away" << endl;
}

void headQuarter::setTaken(bool b) {
    Taken = b;
}

//
// Created by Lenovo on 2024-05-22.
//

void warriorMake(headQuarter& redHeadQuarter, headQuarter& blueHeadQuarter) {
    redHeadQuarter.makeWarrior();
    blueHeadQuarter.makeWarrior();
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}

int isGoingOn(warrior *redWarrior, warrior *blueWarrior) {
    if (redWarrior->lifeValue > 0 && blueWarrior->lifeValue <= 0) {
        return 1;
    } else if (redWarrior->lifeValue <= 0 && blueWarrior->lifeValue > 0) {
        return 2;
    } else if (redWarrior->lifeValue <= 0 && blueWarrior->lifeValue <= 0) {
        return 0;
    } else if (!redWarrior->isChanged && !blueWarrior->isChanged) {
        return 0;
    }
    return -1;
}
//处理红武士的移动
void redWarriorMove(int city, headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter) {
    if (city2Warrior[city][0] == nullptr || st[city][0]) {
        return;
    }
    st[city][0] = true;
    city2Warrior[city][0]->city ++;
    if (city2Warrior[city][0]->name == "lion") {//如果是lion
        lion *curLion = dynamic_cast<lion *>(city2Warrior[city][0]);
        curLion->loyaltyDecrease(k);
    }else if(city2Warrior[city][0]->name == "iceman") {//如果是iceman
        iceman *curIceman = dynamic_cast<iceman *>(city2Warrior[city][0]);
        curIceman->lifeValueDecrease();
    }
    if (city2Warrior[city][0]->city == cityNum + 1) {//如果到达蓝色司令部
        redHeadQuarter.printTaken(city2Warrior[city][0]);
        blueHeadQuarter.setTaken(true);
    }else {//如果没有到达蓝色司令部
        redHeadQuarter.printWarriorMove(city2Warrior[city][0]);
        tmp[city + 1][0]= city2Warrior[city][0];
        city2Warrior[city][0] = nullptr;
    }
}
void blueWarriorMove(int city, headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter) {
    if (city2Warrior[city][1] == nullptr || st[city][1]) {
        return;
    }
    st[city][1] = true;
    city2Warrior[city][1]->city --;
    if (city2Warrior[city][1]->name == "lion") {//如果是lion
        lion *curLion = dynamic_cast<lion *>(city2Warrior[city][1]);
        curLion->loyaltyDecrease(k);
    }else if(city2Warrior[city][1]->name == "iceman") {//如果是iceman
        iceman *curIceman = dynamic_cast<iceman *>(city2Warrior[city][1]);
        curIceman->lifeValueDecrease();
    }
    if (city2Warrior[city][1]->city == 0) {//如果到达红色司令部
        blueHeadQuarter.printTaken(city2Warrior[city][1]);
        redHeadQuarter.setTaken(true);
    }else {//如果没有到达红色司令部
        blueHeadQuarter.printWarriorMove(city2Warrior[city][1]);
        tmp[city - 1][1] = city2Warrior[city][1];
        city2Warrior[city][1] = nullptr;
    }
}
//全局函数
void warriorMove(headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter) {
    //初始化tmp和st
    for (int i = 0; i <= cityNum + 1; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i][j] = nullptr;
            st[i][j] = false;
        }
    }
    //如果下一个城市的对方的武士要来到当前城市, 则先处理对方武士的信息
    for (int i = 0; i <= cityNum + 1; i++) {
        if (i <= cityNum) {
            blueWarriorMove(i + 1, redHeadQuarter, blueHeadQuarter);
        }
        redWarriorMove(i, redHeadQuarter, blueHeadQuarter);
        blueWarriorMove(i, redHeadQuarter, blueHeadQuarter);
    }

    for (int i = 0; i <= cityNum + 1; i++) {
        city2Warrior[i][0] = tmp[i][0];
        city2Warrior[i][1] = tmp[i][1];
    }

    redHeadQuarter.addTime(25);
    blueHeadQuarter.addTime(25);
}

void lionEscape(headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter) {
    for (int i = 0; i <= cityNum + 1; i++) {
        //如果是lion, 判断忠诚度
        if (city2Warrior[i][0] != nullptr && city2Warrior[i][0]->name == "lion" ){
            lion *curLion = dynamic_cast<lion *>(city2Warrior[i][0]);
            if (curLion->getLoyalty() <= 0) {
                redHeadQuarter.printEscapeLion(city2Warrior[i][0]);
                city2Warrior[i][0] = nullptr;
            }
        }
        //如果是lion, 判断忠诚度
        if (city2Warrior[i][1] != nullptr && city2Warrior[i][1]->name == "lion") {
            lion *curLion = dynamic_cast<lion *>(city2Warrior[i][1]);
            if (curLion->getLoyalty() <= 0) {
                blueHeadQuarter.printEscapeLion(city2Warrior[i][1]);
                city2Warrior[i][1] = nullptr;
            }
        }
    }
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}

void wolfStealWeapon(headQuarter &redHeadQuarter, headQuarter& blueHeadQuarter) {
    for (int i = 0; i <= cityNum; i++) {
        if (city2Warrior[i][0] != nullptr && city2Warrior[i][1] != nullptr) {
            if (city2Warrior[i][0]->name == "wolf" && city2Warrior[i][1]->name == "wolf") {
                continue;
            }else if(city2Warrior[i][0]->name == "wolf" && city2Warrior[i][1]->name != "wolf") {
                wolf *curWolf = dynamic_cast<wolf *>(city2Warrior[i][0]);
                auto tt = curWolf->stealWeapon(city2Warrior[i][1]);
                if(tt.first != -1 && tt.second != -1) {
                    redHeadQuarter.printStealWeapon(curWolf, city2Warrior[i][1], tt.first, tt.second);
                }
            }else if (city2Warrior[i][0]->name != "wolf" && city2Warrior[i][1]->name == "wolf") {
                wolf *curWolf = dynamic_cast<wolf *>(city2Warrior[i][1]);
                auto tt = curWolf->stealWeapon(city2Warrior[i][0]);
                if(tt.first != -1 && tt.second != -1)
                blueHeadQuarter.printStealWeapon(curWolf, city2Warrior[i][0],tt.first,tt.second);
            }else {
                continue;
            }
        }
    }
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}

//全局函数战斗
void warriorFight(headQuarter& redHeadQuarter, headQuarter& blueHeadQuarter) {
    for (int i = 0 ; i <= cityNum + 1; i++) {
        if (city2Warrior[i][0] != nullptr && city2Warrior[i][1] != nullptr) {
            int res = -1; // 0表示平局, 1表示红色胜, 2表示蓝色胜
            warrior *redWarrior = city2Warrior[i][0];
            warrior *blueWarrior = city2Warrior[i][1];
            redWarrior->isChanged = true;
            blueWarrior->isChanged = true;
            redWarrior->sortWeapons();
            blueWarrior->sortWeapons();
            if (i % 2 == 1) {//如果是奇数, 红色先攻击
                while (res == -1) {
                    redWarrior->attackEnemy(blueWarrior);
                    res = isGoingOn(redWarrior, blueWarrior);
                    if (res != -1) {
                        break;
                    }
                    blueWarrior->attackEnemy(redWarrior);
                    res = isGoingOn(redWarrior, blueWarrior);
                }

            }
            if (i % 2 == 0) { // 如果是偶数, 则蓝色先攻击
                while (res == -1) {
                    redWarrior->isChanged = true;
                    blueWarrior->isChanged = true;
                    blueWarrior->attackEnemy(redWarrior);
                    res = isGoingOn(redWarrior, blueWarrior);
                    if (res != -1) {
                        break;
                    }
                    redWarrior->attackEnemy(blueWarrior);
                    res = isGoingOn(redWarrior, blueWarrior);
                }
            }
            //比赛结束了
            if (res == 0) {//平局
                //如果都活了
                if (redWarrior->lifeValue > 0 && blueWarrior->lifeValue > 0) {
                    redHeadQuarter.printBothAlive(redWarrior, blueWarrior);
                    if (redWarrior->name == "dragon") {
                        dragon *curDragon = dynamic_cast<dragon *>(redWarrior);
                        redHeadQuarter.printDragonYell(curDragon);
                    }
                    if(blueWarrior->name == "dragon") {
                        dragon *curDragon = dynamic_cast<dragon *>(blueWarrior);
                        blueHeadQuarter.printDragonYell(curDragon);
                    }
                }else if (redWarrior->lifeValue <= 0 && blueWarrior->lifeValue <= 0) {//如果都死了
                    city2Warrior[i][0] = nullptr;
                    city2Warrior[i][1] = nullptr;
                    redHeadQuarter.printBothDie(redWarrior, blueWarrior);
                }
            } else if (res == 1) {//红色胜
                city2Warrior[i][1] = nullptr;//蓝色武士死亡
                redHeadQuarter.printKill(redWarrior, blueWarrior);
                if (redWarrior->name == "dragon") {
                    dragon *curDragon = dynamic_cast<dragon *>(redWarrior);
                    redHeadQuarter.printDragonYell(curDragon);
                }
                redWarrior->winWeapon(blueWarrior);      //缴获武器
            } else if (res == 2) {//蓝色胜
                city2Warrior[i][0] = nullptr;//红色武士死亡
                redHeadQuarter.printKill(blueWarrior, redWarrior);
                if (blueWarrior->name == "dragon") {
                    dragon *curDragon = dynamic_cast<dragon *>(blueWarrior);
                    blueHeadQuarter.printDragonYell(curDragon);
                }
                blueWarrior->winWeapon(redWarrior);      //缴获武器
            }
        }
    }
    redHeadQuarter.addTime(10);
    blueHeadQuarter.addTime(10);
}
void reportLifeValue(headQuarter& redHeadQuarter, headQuarter& blueHeadQuarter) {
    redHeadQuarter.reportLifeValue();
    blueHeadQuarter.reportLifeValue();
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}

//汇报武器
void reportWeapons(headQuarter& redHeadQuarter, headQuarter& blueHeadQuarter) {
    for (int i = 0; i <= cityNum + 1; i++) {
        if (city2Warrior[i][0] != nullptr) {
            redHeadQuarter.printWeapon(city2Warrior[i][0]);
        }
        if (city2Warrior[i][1] != nullptr) {
            blueHeadQuarter.printWeapon(city2Warrior[i][1]);
        }
    }
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}

void solve(headQuarter &redHeadQuarter, headQuarter &blueHeadQuarter){
    int curSum = 0; // 当前时间
    while (curSum <= t) {
        //00分 制造武士
        warriorMake(redHeadQuarter, blueHeadQuarter);
        //05分 lion逃跑
        curSum += 5;
        if (curSum > t) {
            break;
        }
        lionEscape(redHeadQuarter, blueHeadQuarter);
        //10分 武士前进
        curSum += 5;
        if (curSum > t) {
            break;
        }
        warriorMove(redHeadQuarter, blueHeadQuarter);
        if (redHeadQuarter.isTaken()|| blueHeadQuarter.isTaken()) {
            break;
        }
        //35分 wolf偷武器
        curSum += 25;
        if (curSum > t) {
            break;
        }
        wolfStealWeapon(redHeadQuarter, blueHeadQuarter);
        //40分 武士战斗
        curSum += 5;
        if (curSum > t) {
            break;
        }
        warriorFight(redHeadQuarter, blueHeadQuarter);
        //50分, 司令部报告生命值
        curSum += 10;
        if (curSum > t) {
            break;
        }
        reportLifeValue(redHeadQuarter, blueHeadQuarter);
        //55分, 武士报告武器
        curSum += 5;
        if (curSum > t) {
            break;
        }
        reportWeapons(redHeadQuarter, blueHeadQuarter);
        //0分, 回到原来
        curSum += 5;
        if (curSum > t) {
            break;
        }
    }
}

int main() {
    cin >> num;
    for (int j = 1 ; j <= num ;j ++){
        cout << "Case " << j << ":"<<endl;
        cin >> m >> n >> k >> t;
        cityNum = n;
        cin >> l1 >> l2 >> l3 >> l4 >> l5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        //初始化全局变量
        for (int i = 0; i <= 24; i++) {
            for (int j = 0; j < 2; j++) {
                tmp[i][j] = nullptr;
                st[i][j] = false;
                city2Warrior[i][j] = nullptr;
            }
        }
        //dragon、ninja、iceman、lion、wolf 1 2 3 4 5
        headQuarter redHeadQuarter(0, m, new int[6]{0, 3, 4, 5, 2, 1},
                                   new int[6]{0, l1, l2, l3, l4, l5},
                                   new int[6]{0, a1, a2, a3, a4, a5}, n);
        headQuarter blueHeadQuarter(1, m, new int[6]{0, 4, 1, 2, 3, 5},
                                    new int[6]{0, l1, l2, l3, l4, l5},
                                    new int[6]{0, a1, a2, a3, a4, a5}, n);
        solve(redHeadQuarter, blueHeadQuarter);
    }
}
