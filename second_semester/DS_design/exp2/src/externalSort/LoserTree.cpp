//
// Created by Lenovo on 2024-04-15.
//
#include "LoserTree.h"
#include "LoserNode.h"
using namespace std;
int n, k;
const int MEMORY_SIZE = 5000; // 人为规定了内存的大小
int bufferSize;
const int N = 1e5;
int outPutNum = 1;//标记初始化顺串的个数
int diskVisit = 0;
int randomNum = 0;// 初始数据个数

//winner函数
int winner(LoserNode a[], int b, int c)
{// For a min winner tree.
    if (a[b].ID != a[c].ID) {
        return a[b].ID < a[c].ID ? b : c;
    } // 得到初始顺串必备
    if (a[b].key <= a[c].key) return b;
    return c;
}

//从输入流中读取readSize个数据到data中去
void readSizeData(int* & data, const int& readSize, ifstream & fin) {
    if (data != NULL) {
        delete []data;
    }
    data = new int[readSize + 1];
    for (int i = 1 ; i <= readSize; i++) {
        fin >> data[i];
    }
    diskVisit ++;
}

void readNoSizeData(int * & data, ifstream & fin) {
    if (data != NULL) {
        delete []data;
    }
    data = new int[N];
    for (int i = 0 ; i  < N; i++) {
        data[i] = 0x3f3f3f3f;
    }
    int idx = 1;
    while (!fin.eof()) {
        fin >> data[idx++];
    }
}
//得到n, k
void initNK() {
    // 从properties.txt中截取输者树大小n和k路归并
    string strn, strk;
    ifstream finNK("properties.txt", ios::in);
    finNK >> strn;
//    cout << strn.find("1") << endl;
    n = atoi(strn.substr(18).c_str()); // 得到n
    finNK >> strk;
//    cout << strk.find("4") << endl;
    k = atoi(strk.substr(8).c_str()); //得到k
    //关闭文件
    finNK.close();
}

//得到初始化顺串
void initOrderings() {
    //从data.txt中截取数据
    int allNums, readSize;
    ifstream finData("testData.txt", ios::in);
    finData >> allNums;
    readSize = min (n, allNums); // 读取数据的个数, 这里我们默认是小于内存大小的, 因为内存大小 > n

    //读入一组数据初始化输者树
    int * data = NULL;
    LoserTree <LoserNode> lt (n);
    readSizeData(data, readSize, finData);
    allNums -= readSize;
    LoserNode * players = new LoserNode[n];
    for (int i = 1 ; i <= n ; i++) {
        players[i] = LoserNode(1, data[i]); // //ID = 1, key = data[i]
    }
    lt.Initialize(players, n, winner);

    //输出到新的文件中
    ofstream fOutOrder("Seg0-1.txt", ios::out);
    int serialNumber = 1; // 初始顺串号
    //开始读
    // 1000 -> 700 300
    while (allNums > 0) {
        //再读入一组数据
        readSizeData(data, readSize, finData);
        // 每次都读取readSize个数据, 并且输出readSize个数据
        for (int i = 1; i <= readSize; i++) {
            int winnerIdx = lt.Winner();
            int winnerSerial = players[winnerIdx].ID;
            //判断此时是否需要重开一个文件输出
            if (serialNumber < winnerSerial ) {
                fOutOrder.close();
                serialNumber++;
                string initOutPutOrdering = "Seg0-1.txt";
                string outPutOrdering;
                outPutOrdering = initOutPutOrdering .replace
                        (initOutPutOrdering.find("0-1"), 3, "0-" + to_string(++outPutNum));
                fOutOrder.open(outPutOrdering);
            }
            fOutOrder << players[winnerIdx].key <<" ";// 输出到目标文件中去
            //判断下一个玩家的顺串类型, 并将winner替换为该玩家
            if (data[i] >= players[winnerIdx].key) { // 不是没有的数据
                players[winnerIdx] = {winnerSerial, data[i]};
            }
            else {
                players[winnerIdx] = {winnerSerial + 1, data[i]};
            }
            lt.RePlay(winner);
        }
        //读入完数据进行更新
        allNums -= readSize;
        readSize = min (readSize, allNums);
    }

    //此时输出树中还有初始化的数据没有输出
    for (int i = 1; i <= n; i++) {
        int winnerIdx = lt.Winner();
        int winnerSerial = players[winnerIdx].ID;
        //判断此时是否需要重开一个文件输出
        if (serialNumber < winnerSerial ) {
            fOutOrder.close();
            serialNumber++;
            string initOutPutOrdering = "Seg0-1.txt";
            string outPutOrdering;
            outPutOrdering = initOutPutOrdering .replace
                    (initOutPutOrdering.find("0-1"), 3, "0-" + to_string(++outPutNum));
            fOutOrder.open(outPutOrdering);
        }
        fOutOrder << players[winnerIdx].key <<" ";// 输入对应的赢者(最小值)
        players[winnerIdx] = LoserNode(INT_MAX, INT_MAX); // 此时更新为最大的, 保证不会输出
        lt.RePlay(winner);
    }

    finData.close();
}

//将data[1 ~ size]的数据归并到outMerge中
void merge2File(int ** & data, int Size, ofstream & outMerge) {
    int idx[Size + 1];// 记录每个顺串需要取数的位置
    bool st[Size + 1]; //判断每个顺串是否算过了磁盘访问次数
    for (int i = 1 ; i <= Size ; i++) {
        idx[i] = 1; st[i] = false;
    } // 初始化为1
    //特殊情况, 无法初始化输者树, 直接输出即可
    if (Size == 1) {
        int cnt = 1;
        while (data[Size][cnt]!= 0x3f3f3f3f) {
            outMerge << data[Size][cnt++] << " ";
        }
        diskVisit += ceil(double(cnt - 1) / bufferSize);
        return;
    }

    //初始化输者树
    LoserNode *players = new LoserNode [Size + 1];
    for (int i = 1 ; i <= Size; i++) {
        players[i] = LoserNode(1, data[i][idx[i]++]); // 所有顺串都标记为1
    }
    LoserTree<LoserNode>  lt(Size);
    lt.Initialize(players, Size, winner);

    int winnerIdx = lt.Winner();
    //每次进行比赛, 替换掉赢者
    while (players[winnerIdx].key != 0x3f3f3f3f) {
        outMerge << players[winnerIdx].key << " ";
        int nextOne = data[winnerIdx][idx[winnerIdx]++];// 赢者对应的下一个顺串
        if (!st[winnerIdx] && nextOne == 0x3f3f3f3f)  {// 读到了末尾, 取出此时的idx, 来判断需要从内存中读几次
            diskVisit += ceil(double(idx[winnerIdx] - 1) / bufferSize); //需要多读 该顺串的长度 / bufferSize 向上取整 次
            st[winnerIdx] = true;
        }

        players[winnerIdx].key = nextOne; // 从赢者对应的顺串中取数据

        lt.RePlay(winner); // 重构树
        winnerIdx = lt.Winner();
    }
}

//对生成的初始化顺串进行合并
void mergeSort() {
    bufferSize = MEMORY_SIZE / (k + 1);
    int round = ceil(log(outPutNum) / log(k)); //归并树的高度, (5 / log4) = 2
    int cur = outPutNum, next; // 记录此时遍历的文件总个数和即将生成的文件个数
    for (int i = 1; i <= round ; i++) {
        int inPutNum = 1; // 记录输入文件名的号码
        int outPutMergeNum = 1;//记录输出文件名的号码
        next = ceil(double (cur) / k); // 记录即将生成的文件个数, ceil 5 / 4 = 2
        //表示输出的文件为第j个
        for (int j = 1 ; j <= next; j++) {
            //确定输出文件名
            string mergeFile ;
            if (i == round) {// 修改输出文件名
                mergeFile = "output.txt";
            }
            else {
                //确定输出文件名 1-1 / 1-2 / 1-3..
                string initMergeFile = "Seg1-1.txt";
                mergeFile = initMergeFile.replace
                        (initMergeFile.find("1-1"), 3, to_string(i) + "-" + to_string(outPutMergeNum++));
            }
            ofstream ofMerge (mergeFile, ios::out); // 打开输出文件

            //确定输入文件名
            int Size = min (cur, k);
            cur -= k;
            //找到对应的输入串 seg0-1 0-2 0-3 , seg1-1 seg1-2 .. 并将文件的数据存入data数组中
            int ** data = new int * [Size + 1]; // data[i]表示第i个顺串
            for (int s = 1 ; s <= Size ; s++) {
                data[s] = NULL;
            } // 初始化
            for (int s = 1; s <= Size; s++) {
                string initOrdering = "Seg0-1.txt";
                string inputOrdering =initOrdering.replace
                        (initOrdering.find("0-1"), 3, to_string(i - 1) + "-" + to_string(inPutNum++));
                ifstream ifOrder (inputOrdering, ios::in); // 打开输入文件
                readNoSizeData(data[s], ifOrder); // 每次都读取n个数据
            }
            //已经得到了data数组, 此时进行merge操作
            merge2File(data, Size, ofMerge);
        }
        cur = next;
    }
}



//将给定的顺串进行合并生成对应的
void testGivenData() {
    initNK();
    initOrderings();
    mergeSort();
}

void initData() {
    k = 3; //采用k路归并
    n = 1000; // 最小输者树的选手个数
    ofstream ofInit ("testData.txt", ios::out);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000000);
//    randomNum = dis(gen) % N + 10; // 生成1 ~ 100000的数
    randomNum = 50000;

    ofInit << randomNum << endl;
    for (int i = 0 ; i < randomNum; i++) {
        // 生成 1 ~ 1e6的数
        int x = dis(gen);
        ofInit << x << " ";
    }
    ofInit.close();
}

void printDiskVisit() {
    //输出磁盘访问次数
    cout << "n: "<< n <<  "; k: " << k << "; 初始数据个数为: " <<randomNum<<"; 内存大小为: " <<MEMORY_SIZE<<"; 初始顺串个数为: " << outPutNum
         <<endl <<"磁盘访问次数为: " << diskVisit << endl;
}

void testRandomData() {
    initData();
    initOrderings();
    mergeSort();
    printDiskVisit();
}