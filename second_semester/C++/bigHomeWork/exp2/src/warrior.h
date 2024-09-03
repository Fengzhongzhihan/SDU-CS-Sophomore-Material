//
// Created by Lenovo on 2024-05-21.
//

#ifndef REDANDBLUEAGAINST_WARRIOR_H
#define REDANDBLUEAGAINST_WARRIOR_H
#include "bits/stdc++.h"
using namespace std;
class weapon{
public:
    int weaponID;//武器编号
    int weaponAttack;//武器攻击力
    weapon(int weaponID_, int weaponAttack_){
        weaponID = weaponID_;
        weaponAttack = weaponAttack_;
    }
};

class warrior{
public:
    int lifeValue;//生命值
    int attack;//攻击力
    int id;//编号
};

class dragon: public warrior{
private:
    double morale; //士气
    int weaponID; //武器编号
    map<int, int> weapons;//编号 -> 数量
public:
    dragon(int id_, int lifeValue_, double remainingLifeValue){
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
        morale = remainingLifeValue / lifeValue_;
    }
    double getMorale(){
        return morale;
    }
    int getWeaponID(){
        return weaponID;
    }
    void print() {
        cout << "It has a arrow and it's morale is " << setprecision(3)<< morale << endl;
    }
};
class ninja: public warrior{
private:
    int weaponID1;
    int weaponID2;
    map<int, int> weapons;//编号 -> 数量
public:
    ninja(int id_, int lifeValue_){
        id = id_;
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
    }
    int getWeaponID1(){
        return weaponID1;
    }
    int getWeaponID2(){
        return weaponID2;
    }
    void print() {
cout << "It has a bomb and a arrow" << endl;
    }
};
class iceman: public warrior{
private:
    int weaponID;
    map<int, int> weapons;//编号 -> 数量
public:
    iceman(int id_, int lifeValue_){
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
    }
    int getWeaponID(){
        return weaponID;
    }
    void print() {
        cout << "It has a sword" << endl;
    }
};
class lion: public warrior{
private:
    int loyalty;
    int weaponID;
    map<int, int> weapons;//编号 -> 数量
public:
    lion(int id_, int lifeValue_, int remainingLifeValue){
        id = id_;
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
    }
    int getLoyalty(){
        return loyalty;
    }
    void print() {
        cout << "It's loyalty is " << loyalty << endl;
    }
};
class wolf: public warrior{
private:
    vector<weapon> weapons;
public:
    wolf(int id_, int lifeValue_){
        id = id_;
        lifeValue = lifeValue_;
    }
};

#endif //REDANDBLUEAGAINST_WARRIOR_H
