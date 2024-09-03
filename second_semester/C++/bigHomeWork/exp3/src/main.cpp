#include <iostream>
#include "headQuarter.h"
#include "process.h"
using namespace std;
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
    ifstream fin("testIn.txt", ios::in);
    fin >> num;
    warriorName[1] = "dragon";
    warriorName[2] = "ninja";
    warriorName[3] = "iceman";
    warriorName[4] = "lion";
    warriorName[5] = "wolf";
    for (int j = 1 ; j <= num ;j ++){
        fout << "Case " << j << ":"<<endl;
        fin >> m >> n >> k >> t;
        fin >> warriorLife[1] >> warriorLife[2] >> warriorLife[3] >> warriorLife[4] >> warriorLife[5];
        fin >> warriorAttack[1] >> warriorAttack[2] >> warriorAttack[3] >> warriorAttack[4] >> warriorAttack[5];
        minLifeValue = warriorLife[1];
        //求出minLifeValue
        for (int i = 1; i <= 5; i++) {
            minLifeValue = min(minLifeValue, warriorLife[i]);
        }
        //dragon、ninja、iceman、lion、wolf 1 2 3 4 5
        headQuarter redHeadQuarter(0);
        headQuarter blueHeadQuarter(1);
        solve(redHeadQuarter, blueHeadQuarter);
        //释放内存
        for (int i = 0; i <= 21; i++) {
            for (int j = 0; j < 2; j++) {
                if (city2Warrior[i][j] != nullptr) {
                    delete city2Warrior[i][j];
                    city2Warrior[i][j] = nullptr;
                }
            }
        }
    }
}
