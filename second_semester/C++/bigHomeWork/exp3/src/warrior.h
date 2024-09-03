//
// Created by Lenovo on 2024-05-21.
//
#ifndef REDANDBLUEAGAINST_WARRIOR_H
#define REDANDBLUEAGAINST_WARRIOR_H
#include "bits/stdc++.h"
using namespace std;
ofstream fout("testOut.txt", ios::trunc);

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
    warrior(int id_, int lifeValue_, int attack_, int city_, int color_, string name);
    virtual ~warrior(){}
    void sortWeapons();
    void attackEnemy(warrior * enemy);
    void winWeapon(warrior *enemy);
    void print();
};

void warrior::sortWeapons(){
    int idx = 0;
    for (auto &weapon : weapons) {
        for (int i = 0 ; i < weapon.second; i++) {
            weaponUseOrder[idx++] = weapon.first;
        }
    }
    tempWeaponNum = idx;
    curUseWeaponIndex = 0;
}

void warrior::winWeapon(warrior *enemy) {
    if (weaponNum == 10) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (enemy->weapons[i] > 0) {
            int takeNum = enemy->weapons[i];
            if (weaponNum + enemy->weapons[i] > 10) {//不能大于10件
                takeNum = 10 - weaponNum;
            }
            weapons[i] += takeNum;
            weaponNum += takeNum;
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

void warrior::attackEnemy(warrior *enemy) {
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
    } else if (weaponUseOrder[curUseWeaponIndex] == 2) {
        curUseWeaponIndex++;
        //使用arrow
        int arrowAttack = attack * 3 / 10;
        isChanged = true;
        enemy->lifeValue -= arrowAttack;
        if (isUsedArrow == weapons[2]) { //使用次数==武器数量
            weapons[2]--;
            weaponNum--;
            isUsedArrow--;
        } else {
            isUsedArrow++;
        }
    }
}

warrior::warrior(int id_, int lifeValue_, int attack_, int city_, int color_, string name) {
    id = id_;
    lifeValue = lifeValue_;
    attack = attack_;
    city = city_;
    color = color_;
    this->name = name;
    weaponNum = 0;
    isChanged = false;
    weapons[0] = 0;
    weapons[1] = 0;
    weapons[2] = 0;
    isUsedArrow = 0;
}

class dragon: public warrior{
private:
    double morale; //士气
    int weaponID; //武器编号
public:
    dragon(int id_, int lifeValue_, int attack_, double remainingLifeValue, int city_, int color_);
    double getMorale(){
        return morale;
    }
};
dragon::dragon(int id_, int lifeValue_, int attack_, double remainingLifeValue, int city_, int color_)
: warrior(id_, lifeValue_, attack_, city_, color_, "dragon"){
    weaponID = id % 3;
    if (weaponID == 0) {//sword
        weapons[0] = 1;
    } else if (weaponID == 1) {//bomb
        weapons[1] = 1;
    } else {//arrow
        weapons[2] = 1;
    }
    morale = remainingLifeValue / lifeValue;
    weaponNum = 1;

}
class ninja: public warrior{
private:
    int weaponID1;
    int weaponID2;
public:
    ninja(int id_, int lifeValue_, int attack_, int city_, int color_);
};

ninja::ninja(int id_, int lifeValue_, int attack_, int city_, int color_) : warrior(id_, lifeValue_, attack_, city_, color_, "ninja"){
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
    weaponNum = 2;
}
class iceman: public warrior{
private:
    int weaponID;
public:
    iceman(int id_, int lifeValue_, int attack_, int city_, int color_);
    void lifeValueDecrease();
};

void iceman::lifeValueDecrease() {
    lifeValue -= lifeValue / 10;
}
iceman::iceman(int id_, int lifeValue_, int attack_, int city_, int color_): warrior(id_, lifeValue_, attack_, city_, color_, "iceman"){
    weaponID = id % 3;
    if (weaponID == 0) {//sword
        weapons[0] = 1;
    } else if (weaponID == 1) {//bomb
        weapons[1] = 1;
    } else {//arrow
        weapons[2] = 1;
    }
    weaponNum = 1;
}
class lion: public warrior{
private:
    int weaponID;
    int loyalty;
public:
    lion(int id_, int lifeValue_, int remainingLifeValue, int attack_, int city_, int color_);
    inline int getLoyalty()const{
        return loyalty;
    }
    void loyaltyDecrease(int k);
    void printLoyalty();
};

void lion::loyaltyDecrease(int k) {
    loyalty -= k;
}
lion::lion(int id_, int lifeValue_, int remainingLifeValue, int attack_, int city_, int color_) :
warrior(id_, lifeValue_, attack_, city_, color_, "lion"){
    loyalty = remainingLifeValue;
    weaponID = id % 3;
    if (weaponID == 0) {//sword
        weapons[0] = 1;
    } else if (weaponID == 1) {//bomb
        weapons[1] = 1;
    } else {//arrow
        weapons[2] = 1;
    }
    weaponNum = 1;
}

void lion::printLoyalty() {
    fout << "Its loyalty is " << loyalty << endl;
}

class wolf: public warrior{
public:
    wolf(int id_, int lifeValue_, int attack_, int city_, int color_);
    pair<int, int> stealWeapon(warrior * enemy);
};

wolf::wolf(int id_, int lifeValue_, int attack_, int city_, int color_): warrior(id_, lifeValue_, attack_, city_, color_, "wolf"){

}
pair<int, int> wolf::stealWeapon(warrior *enemy) {
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
}
#endif //REDANDBLUEAGAINST_WARRIOR_H