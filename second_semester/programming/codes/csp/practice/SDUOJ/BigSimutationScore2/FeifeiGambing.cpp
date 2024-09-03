//
// Created by Lenovo on 2024-03-22.
//
#include "bits/stdc++.h"
using namespace  std;
int n, m, a1, b1, a2, b2;
const int N = 25 + 10;
int cnt[10]; // 记录每种方案的个数

struct card{
    int a, b;
    // 重载<号按照点数升序排列
    bool operator < (card x) {
        return a < x.a;
    }
};
vector<card> num;

int CardType(card mcards[]) {
    // 同花, 炸弹, 顺子, 3个相同, 2个相同
    bool sameFlower = false, bomb = false, shun = true, threeCnt = false;
    int twoCnt = 0;

    // 注意备份, 若排序,会影响传入的cards
    card cards[N];
    for (int i = 0 ; i < 5 ;i ++) {
        cards[i] = mcards[i];
    }
    // 升序排序
    sort(cards, cards + 5);
    // 记录点数和花色的个数
    int dot[N] = {0}, flower[N] = {0};
    for (int i = 0 ; i < 5; i ++) {
        dot[cards[i].a] ++;
        flower[cards[i].b] ++;
    }

    // 5. 顺子
    for (int i = 0 ; i < 4; i++) {
        if (cards[i]. a + 1 != cards[i + 1].a) {
            shun = false;
            break;
        }
    }
    // 枚举每一个值
    for (int i = 0 ; i < N; i++) {
        // 2. 炸弹
        if (dot[i] == 4) {
            bomb = true;
        }
        // 4. 同花
        if (flower[i] == 5) {
            sameFlower = true;
        }
        // 6.三条
        if (dot[i] == 3) {
            threeCnt = true;
        }
        // 7. 两对 8. 一对
        if (dot[i] == 2) {
            twoCnt++;
        }
    }

    if (sameFlower && shun) {
        return 1;
    }
    if (bomb) {
        return 2;
    }
    if (twoCnt == 1 && threeCnt == true) {
        return 3;
    }
    if (sameFlower) {
        return 4;
    }
    if (shun) {
        return 5;
    }
    if (threeCnt == true) {
        return 6;
    }
    if (twoCnt == 2) {
        return  7;
    }
    if (twoCnt == 1) {
        return 8;
    }

    return 9;
}

void dfs(int u, int start, card mCards[])
{
    // 如果 u == 5 则已经枚举好了一组, 传入判断即可
    if (u == 5) {
        cnt[CardType(mCards)] ++;
        return;
    }
    //找数进行枚举, 每次找到一个数之后都要在下一个位置进行找
    for (int i = start; i < num.size(); i++ ){
        mCards[u] = num[i];
        dfs(u + 1, i + 1, mCards);
    }
}

int main() {
    // 处理输入输出
    cin >> n >> m >> a1 >> b1 >> a2 >> b2;
    card mCards[N];
    mCards[0] = {a1, b1};
    mCards[1] = {a2, b2};

    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m ; j++) {
            if ((i == a1 && j == b1) || (i == a2 && j == b2)) {
                continue;
            }
            num.push_back({i, j});
        }
    }

    //从第3个位置开始枚举, 依此找card
    dfs(2, 0, mCards);

    //输出结果
    for (int i = 1 ; i <= 9 ; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}