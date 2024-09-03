// 文件 loser.h
// 基于公式的败者树

#ifndef LoserTree_
#define LoserTree_
#include "bits/stdc++.h"
using namespace std;

template<class T>
class LoserTree {
public:
    LoserTree(int TreeSize = 10); // 构造函数
    ~LoserTree() {delete [] t;} // 析构函数
    void Initialize(T a[], int size, // 初始化败者树
                    int(*winner)(T a[], int b, int c));
    int Winner()  const {return (n) ? t[0] : 0;} // 返回胜者
    void RePlay(int(*winner) // 树的重构
            (T a[], int b, int c));
    void Output() const; // 输出败者树信息
private:
    int MaxSize; // 树的最大容量
    int n;      // 当前大小
    int LowExt; // 最低层的外部节点数
    int offset; // 2^k - 1
    int * t;     // 败者树数组
    T *e;       // 元素数组
    void Play(int p, int lc, int rc, // 进行比赛
              int(*winner)(T a[], int b, int c));
};

template<class T>
LoserTree<T>::LoserTree(int TreeSize)
{// 胜者树的构造函数
    MaxSize = TreeSize;
    t = new int[MaxSize];
    n = 0;
}

template<class T>
void LoserTree<T>::Initialize(T a[], int size,
                              int(*winner)(T a[], int b, int c))
{// 初始化败者树
    if (size > MaxSize || size < 2)
        return;
    //赋值大小, treeNode数组
    n = size;
    e = a;

    int i, s;
    for (s = 1; 2*s <= n-1; s += s);     // 计算 s = 2^log (n-1)

    LowExt = 2*(n-s); // 最底层外部节点个数
    offset = 2*s-1;

    // 首先记录t[1:n-1]中的胜者
    // 对于最低层的外部节点找右孩子进行比赛
    for (i = 2; i <= LowExt; i += 2)
        Play((offset+i)/2, i-1, i, winner); // 前者为父亲节点

    // 处理剩余的外部节点
    if (n % 2) {// 对于奇数n的特殊情况，进行比赛
        // 内部和外部节点
        Play(n/2, t[n-1], LowExt+1, winner);
        i = LowExt+3;}
    else i = LowExt+2;

    // i是最左边剩余的外部节点
    for (; i <= n; i += 2)
        Play((i-LowExt+n-1)/2, i-1, i, winner);

    // 在t[0]中记录总体赢家
    t[0] = t[1];

    // 现在对t进行层序遍历
    // 将胜者替换为败者
    for (i = 1; i < n; i++) {
        // 将t[i]设置为在t[i]中进行比赛的失败者
        int lc = 2 * i;   // i的左孩子
        int rc = lc + 1;  // i的右孩子
        // 最终 e[LeftPlayer] 表示比赛的左方选手
        // t[i] 和 e[RightPlayer] 表示另一位选手
        int LeftPlayer, RightPlayer;
        // 确定 LeftPlayer
        if (lc <= n - 1) LeftPlayer = t[lc];
        else // 左孩子是外部节点
        if (lc <= offset)
            LeftPlayer = lc + LowExt - n + 1;
        else LeftPlayer = lc - offset;

        // 确定 RightPlayer
        if (rc <= n - 1) RightPlayer = t[rc];
        else // 右孩子是外部节点
        if (rc <= offset)
            RightPlayer = rc + LowExt - n + 1;
        else RightPlayer = rc - offset;

        // 确定比赛的失败者
        if (LeftPlayer == t[i])
            // RightPlayer 是失败者
            t[i] = RightPlayer;
        else // LeftPlayer 是失败者
            t[i] = LeftPlayer;
    }

}

template<class T>
void LoserTree<T>::Play(int p, int lc, int rc, int(*winner)(T a[], int b, int c))
{// 从t[p]开始比赛
    // lc 和 rc 是 t[p] 的孩子
    t[p] = winner(e, lc, rc);

    // 如果在p在右孩子处还有比赛
    while (p > 1 && p % 2) {// 在右孩子处
        t[p/2] = winner(e, t[p-1], t[p]);
        p /= 2;  // 移动到父节点
    }
}

template<class T>
void LoserTree<T>::RePlay(int(*winner)(T a[], int b, int c)) // 重构进行之前的胜者树, 确保败者树已经初始化
{
    if (n < 2) return;
    int p;   // 比赛节点 (父节点)
    // 找到第一个比赛节点
    int i = t[0];    // i是之前的胜者的标号
    if (i <= LowExt)
        p = (offset + i)/2;// 从最低层开始
    else p = (i-LowExt+n-1)/2;

    int LastWinner = i;

    // 进行比赛
    for (; p >= 1; p /= 2) {
        // 在 t[p] 进行比赛
        int NewWinner = winner(e, LastWinner, t[p]);
        // 如果胜者有变化，则更新败者
        if (t[p] == NewWinner) {
            // e[t[p]] 不再是败者
            t[p] = LastWinner;
            LastWinner = NewWinner;}
    }

    // 将总体胜者放入 t[0]
    t[0] = LastWinner;
}

template<class T>
void LoserTree<T>::Output() const
{
    cout << "size = "<< n << " LowExt = " << LowExt
         << " Offset = " << offset << endl;
    cout << "Loser tree pointers are" << endl;
    for (int i = 0; i < n; i++)
        cout << t[i] << ' ';
    cout << endl;
}

#endif // LoserTree_

