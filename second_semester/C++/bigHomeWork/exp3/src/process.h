
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
void redWarriorMove(int city, headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter,  bool st[25][2]) {
    if (city2Warrior[city][0] == NULL || st[city][0]) {
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
    if (city2Warrior[city][0]->city == n + 1) {//如果到达蓝色司令部
        redHeadQuarter.printTaken(city2Warrior[city][0]);
        blueHeadQuarter.setTaken(true);
    }else {//如果没有到达蓝色司令部
        redHeadQuarter.printWarriorMove(city2Warrior[city][0]);
    }
}
void blueWarriorMove(int city, headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter,  bool st[25][2]) {
    if (city2Warrior[city][1] == NULL || st[city][1]) {
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
    }
}
//全局函数
void warriorMove(headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter) {
    //初始化tmp和st
    //备份city2Warrior
    bool st[25][2] = {false};//标志信息有没有处理过
    //如果下一个城市的对方的武士要来到当前城市, 则先处理对方武士的信息
    for (int i = 0; i <= n + 1; i++) {
        if (i <= n) {
            blueWarriorMove(i + 1, redHeadQuarter, blueHeadQuarter, st);
        }
        redWarriorMove(i, redHeadQuarter, blueHeadQuarter, st);
        blueWarriorMove(i, redHeadQuarter, blueHeadQuarter, st);
    }
    //此时统计各个武士应该在的位置
    for (int i = n + 1; i >= 0; i--) {
        if (city2Warrior[i][0] != NULL) {
            city2Warrior[city2Warrior[i][0]->city][0] = city2Warrior[i][0];
            city2Warrior[i][0] = NULL;
        }
    }
    for (int i = 0 ; i <= n + 1; i++) {
        if (city2Warrior[i][1] != NULL) {
            city2Warrior[city2Warrior[i][1]->city][1] = city2Warrior[i][1];
            city2Warrior[i][1] = NULL;
        }
    }

    redHeadQuarter.addTime(25);
    blueHeadQuarter.addTime(25);
}

void lionEscape(headQuarter&redHeadQuarter, headQuarter&blueHeadQuarter) {
    for (int i = 0; i <= n + 1; i++) {
        //如果是lion, 判断忠诚度
        if (city2Warrior[i][0] != NULL && city2Warrior[i][0]->name == "lion" ){
            lion *curLion = dynamic_cast<lion *>(city2Warrior[i][0]);
            if (curLion->getLoyalty() <= 0) {
                redHeadQuarter.printEscapeLion(city2Warrior[i][0]);
                delete city2Warrior[i][0];
                city2Warrior[i][0] = NULL;
            }
        }
        //如果是lion, 判断忠诚度
        if (city2Warrior[i][1] != NULL && city2Warrior[i][1]->name == "lion") {
            lion *curLion = dynamic_cast<lion *>(city2Warrior[i][1]);
            if (curLion->getLoyalty() <= 0) {
                blueHeadQuarter.printEscapeLion(city2Warrior[i][1]);
                delete city2Warrior[i][1];
                city2Warrior[i][1] = NULL;
            }
        }
    }
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}

void wolfStealWeapon(headQuarter &redHeadQuarter, headQuarter& blueHeadQuarter) {
    for (int i = 0; i <= n; i++) {
        if (city2Warrior[i][0] != NULL && city2Warrior[i][1] != NULL) {
            if (city2Warrior[i][0]->name == "wolf" && city2Warrior[i][1]->name == "wolf") {
                continue;
            }else if(city2Warrior[i][0]->name == "wolf" && city2Warrior[i][1]->name != "wolf") {
                wolf *curWolf = dynamic_cast<wolf *>(city2Warrior[i][0]);
                auto t = curWolf->stealWeapon(city2Warrior[i][1]);
                redHeadQuarter.printStealWeapon(curWolf, city2Warrior[i][1], t.first, t.second);
            }else if (city2Warrior[i][0]->name != "wolf" && city2Warrior[i][1]->name == "wolf") {
                wolf *curWolf = dynamic_cast<wolf *>(city2Warrior[i][1]);
                auto t = curWolf->stealWeapon(city2Warrior[i][0]);
                blueHeadQuarter.printStealWeapon(curWolf, city2Warrior[i][0],t.first,t.second);
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
    for (int i = 0 ; i <= n + 1; i++) {
        if (city2Warrior[i][0] != NULL && city2Warrior[i][1] != NULL) {
            int res = -1; // 0表示平局, 1表示红色胜, 2表示蓝色胜
            warrior *redWarrior = city2Warrior[i][0];
            warrior *blueWarrior = city2Warrior[i][1];
            redWarrior->isChanged = true;
            blueWarrior->isChanged = true;
            redWarrior->sortWeapons();
            blueWarrior->sortWeapons();
            if (i == 8 && redWarrior->name == "wolf") {
                cout << "hi" << endl;
            }
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
                        redHeadQuarter.printDragonYell(redWarrior);
                    }
                    if(blueWarrior->name == "dragon") {
                        blueHeadQuarter.printDragonYell(blueWarrior);
                    }
                }else if (redWarrior->lifeValue <= 0 && blueWarrior->lifeValue <= 0) {//如果都死了
                    redHeadQuarter.printBothDie(redWarrior, blueWarrior);
                    delete city2Warrior[i][0];
                    city2Warrior[i][0] = NULL;
                    delete city2Warrior[i][1];
                    city2Warrior[i][1] = NULL;
                }
            } else if (res == 1) {//红色胜
                redHeadQuarter.printKill(redWarrior, blueWarrior);
                if (redWarrior->name == "dragon") {
                    redHeadQuarter.printDragonYell(redWarrior);
                }
                redWarrior->winWeapon(blueWarrior);      //缴获武器
                delete city2Warrior[i][1];
                city2Warrior[i][1] = NULL;//蓝色武士死亡
            } else if (res == 2) {//蓝色胜
                redHeadQuarter.printKill(blueWarrior, redWarrior);
                if (blueWarrior->name == "dragon") {
                    blueHeadQuarter.printDragonYell(blueWarrior);
                }
                blueWarrior->winWeapon(redWarrior);      //缴获武器
                delete city2Warrior[i][0];
                city2Warrior[i][0] = NULL;//红色武士死亡
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
    for (int i = 0; i <= n + 1; i++) {
        if (city2Warrior[i][0] != NULL) {
            redHeadQuarter.printWeapon(city2Warrior[i][0]);
        }
        if (city2Warrior[i][1] != NULL) {
            blueHeadQuarter.printWeapon(city2Warrior[i][1]);
        }
    }
    redHeadQuarter.addTime(5);
    blueHeadQuarter.addTime(5);
}