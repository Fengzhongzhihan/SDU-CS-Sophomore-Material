//
// Created by Lenovo on 2024-04-15.
//
#include "LoserTree.h"
#include "LoserNode.h"
using namespace std;
int n, k;
const int MEMORY_SIZE = 5000; // ��Ϊ�涨���ڴ�Ĵ�С
int bufferSize;
const int N = 1e5;
int outPutNum = 1;//��ǳ�ʼ��˳���ĸ���
int diskVisit = 0;
int randomNum = 0;// ��ʼ���ݸ���

//winner����
int winner(LoserNode a[], int b, int c)
{// For a min winner tree.
    if (a[b].ID != a[c].ID) {
        return a[b].ID < a[c].ID ? b : c;
    } // �õ���ʼ˳���ر�
    if (a[b].key <= a[c].key) return b;
    return c;
}

//���������ж�ȡreadSize�����ݵ�data��ȥ
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
//�õ�n, k
void initNK() {
    // ��properties.txt�н�ȡ��������Сn��k·�鲢
    string strn, strk;
    ifstream finNK("properties.txt", ios::in);
    finNK >> strn;
//    cout << strn.find("1") << endl;
    n = atoi(strn.substr(18).c_str()); // �õ�n
    finNK >> strk;
//    cout << strk.find("4") << endl;
    k = atoi(strk.substr(8).c_str()); //�õ�k
    //�ر��ļ�
    finNK.close();
}

//�õ���ʼ��˳��
void initOrderings() {
    //��data.txt�н�ȡ����
    int allNums, readSize;
    ifstream finData("testData.txt", ios::in);
    finData >> allNums;
    readSize = min (n, allNums); // ��ȡ���ݵĸ���, ��������Ĭ����С���ڴ��С��, ��Ϊ�ڴ��С > n

    //����һ�����ݳ�ʼ��������
    int * data = NULL;
    LoserTree <LoserNode> lt (n);
    readSizeData(data, readSize, finData);
    allNums -= readSize;
    LoserNode * players = new LoserNode[n];
    for (int i = 1 ; i <= n ; i++) {
        players[i] = LoserNode(1, data[i]); // //ID = 1, key = data[i]
    }
    lt.Initialize(players, n, winner);

    //������µ��ļ���
    ofstream fOutOrder("Seg0-1.txt", ios::out);
    int serialNumber = 1; // ��ʼ˳����
    //��ʼ��
    // 1000 -> 700 300
    while (allNums > 0) {
        //�ٶ���һ������
        readSizeData(data, readSize, finData);
        // ÿ�ζ���ȡreadSize������, �������readSize������
        for (int i = 1; i <= readSize; i++) {
            int winnerIdx = lt.Winner();
            int winnerSerial = players[winnerIdx].ID;
            //�жϴ�ʱ�Ƿ���Ҫ�ؿ�һ���ļ����
            if (serialNumber < winnerSerial ) {
                fOutOrder.close();
                serialNumber++;
                string initOutPutOrdering = "Seg0-1.txt";
                string outPutOrdering;
                outPutOrdering = initOutPutOrdering .replace
                        (initOutPutOrdering.find("0-1"), 3, "0-" + to_string(++outPutNum));
                fOutOrder.open(outPutOrdering);
            }
            fOutOrder << players[winnerIdx].key <<" ";// �����Ŀ���ļ���ȥ
            //�ж���һ����ҵ�˳������, ����winner�滻Ϊ�����
            if (data[i] >= players[winnerIdx].key) { // ����û�е�����
                players[winnerIdx] = {winnerSerial, data[i]};
            }
            else {
                players[winnerIdx] = {winnerSerial + 1, data[i]};
            }
            lt.RePlay(winner);
        }
        //���������ݽ��и���
        allNums -= readSize;
        readSize = min (readSize, allNums);
    }

    //��ʱ������л��г�ʼ��������û�����
    for (int i = 1; i <= n; i++) {
        int winnerIdx = lt.Winner();
        int winnerSerial = players[winnerIdx].ID;
        //�жϴ�ʱ�Ƿ���Ҫ�ؿ�һ���ļ����
        if (serialNumber < winnerSerial ) {
            fOutOrder.close();
            serialNumber++;
            string initOutPutOrdering = "Seg0-1.txt";
            string outPutOrdering;
            outPutOrdering = initOutPutOrdering .replace
                    (initOutPutOrdering.find("0-1"), 3, "0-" + to_string(++outPutNum));
            fOutOrder.open(outPutOrdering);
        }
        fOutOrder << players[winnerIdx].key <<" ";// �����Ӧ��Ӯ��(��Сֵ)
        players[winnerIdx] = LoserNode(INT_MAX, INT_MAX); // ��ʱ����Ϊ����, ��֤�������
        lt.RePlay(winner);
    }

    finData.close();
}

//��data[1 ~ size]�����ݹ鲢��outMerge��
void merge2File(int ** & data, int Size, ofstream & outMerge) {
    int idx[Size + 1];// ��¼ÿ��˳����Ҫȡ����λ��
    bool st[Size + 1]; //�ж�ÿ��˳���Ƿ�����˴��̷��ʴ���
    for (int i = 1 ; i <= Size ; i++) {
        idx[i] = 1; st[i] = false;
    } // ��ʼ��Ϊ1
    //�������, �޷���ʼ��������, ֱ���������
    if (Size == 1) {
        int cnt = 1;
        while (data[Size][cnt]!= 0x3f3f3f3f) {
            outMerge << data[Size][cnt++] << " ";
        }
        diskVisit += ceil(double(cnt - 1) / bufferSize);
        return;
    }

    //��ʼ��������
    LoserNode *players = new LoserNode [Size + 1];
    for (int i = 1 ; i <= Size; i++) {
        players[i] = LoserNode(1, data[i][idx[i]++]); // ����˳�������Ϊ1
    }
    LoserTree<LoserNode>  lt(Size);
    lt.Initialize(players, Size, winner);

    int winnerIdx = lt.Winner();
    //ÿ�ν��б���, �滻��Ӯ��
    while (players[winnerIdx].key != 0x3f3f3f3f) {
        outMerge << players[winnerIdx].key << " ";
        int nextOne = data[winnerIdx][idx[winnerIdx]++];// Ӯ�߶�Ӧ����һ��˳��
        if (!st[winnerIdx] && nextOne == 0x3f3f3f3f)  {// ������ĩβ, ȡ����ʱ��idx, ���ж���Ҫ���ڴ��ж�����
            diskVisit += ceil(double(idx[winnerIdx] - 1) / bufferSize); //��Ҫ��� ��˳���ĳ��� / bufferSize ����ȡ�� ��
            st[winnerIdx] = true;
        }

        players[winnerIdx].key = nextOne; // ��Ӯ�߶�Ӧ��˳����ȡ����

        lt.RePlay(winner); // �ع���
        winnerIdx = lt.Winner();
    }
}

//�����ɵĳ�ʼ��˳�����кϲ�
void mergeSort() {
    bufferSize = MEMORY_SIZE / (k + 1);
    int round = ceil(log(outPutNum) / log(k)); //�鲢���ĸ߶�, (5 / log4) = 2
    int cur = outPutNum, next; // ��¼��ʱ�������ļ��ܸ����ͼ������ɵ��ļ�����
    for (int i = 1; i <= round ; i++) {
        int inPutNum = 1; // ��¼�����ļ����ĺ���
        int outPutMergeNum = 1;//��¼����ļ����ĺ���
        next = ceil(double (cur) / k); // ��¼�������ɵ��ļ�����, ceil 5 / 4 = 2
        //��ʾ������ļ�Ϊ��j��
        for (int j = 1 ; j <= next; j++) {
            //ȷ������ļ���
            string mergeFile ;
            if (i == round) {// �޸�����ļ���
                mergeFile = "output.txt";
            }
            else {
                //ȷ������ļ��� 1-1 / 1-2 / 1-3..
                string initMergeFile = "Seg1-1.txt";
                mergeFile = initMergeFile.replace
                        (initMergeFile.find("1-1"), 3, to_string(i) + "-" + to_string(outPutMergeNum++));
            }
            ofstream ofMerge (mergeFile, ios::out); // ������ļ�

            //ȷ�������ļ���
            int Size = min (cur, k);
            cur -= k;
            //�ҵ���Ӧ�����봮 seg0-1 0-2 0-3 , seg1-1 seg1-2 .. �����ļ������ݴ���data������
            int ** data = new int * [Size + 1]; // data[i]��ʾ��i��˳��
            for (int s = 1 ; s <= Size ; s++) {
                data[s] = NULL;
            } // ��ʼ��
            for (int s = 1; s <= Size; s++) {
                string initOrdering = "Seg0-1.txt";
                string inputOrdering =initOrdering.replace
                        (initOrdering.find("0-1"), 3, to_string(i - 1) + "-" + to_string(inPutNum++));
                ifstream ifOrder (inputOrdering, ios::in); // �������ļ�
                readNoSizeData(data[s], ifOrder); // ÿ�ζ���ȡn������
            }
            //�Ѿ��õ���data����, ��ʱ����merge����
            merge2File(data, Size, ofMerge);
        }
        cur = next;
    }
}



//��������˳�����кϲ����ɶ�Ӧ��
void testGivenData() {
    initNK();
    initOrderings();
    mergeSort();
}

void initData() {
    k = 3; //����k·�鲢
    n = 1000; // ��С��������ѡ�ָ���
    ofstream ofInit ("testData.txt", ios::out);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000000);
//    randomNum = dis(gen) % N + 10; // ����1 ~ 100000����
    randomNum = 50000;

    ofInit << randomNum << endl;
    for (int i = 0 ; i < randomNum; i++) {
        // ���� 1 ~ 1e6����
        int x = dis(gen);
        ofInit << x << " ";
    }
    ofInit.close();
}

void printDiskVisit() {
    //������̷��ʴ���
    cout << "n: "<< n <<  "; k: " << k << "; ��ʼ���ݸ���Ϊ: " <<randomNum<<"; �ڴ��СΪ: " <<MEMORY_SIZE<<"; ��ʼ˳������Ϊ: " << outPutNum
         <<endl <<"���̷��ʴ���Ϊ: " << diskVisit << endl;
}

void testRandomData() {
    initData();
    initOrderings();
    mergeSort();
    printDiskVisit();
}