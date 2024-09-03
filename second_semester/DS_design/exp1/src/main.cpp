#include "skipList.h"
#include "skipList.cpp"
#include <fstream>
int n , m;
double sum = 0 ;

void initData() {
    ofstream generateFile("input.txt", ios::trunc);
    generateFile << m << " " << n << endl; //����n, m
    //����-100000 + 100000�ڵ������
    for (int i = 0 ; i < n ; i++) {
        int x = rand() % 200001 - 100000;
        generateFile << x << " ";
    }
    generateFile << endl;
    //���ɲ�������
    for (int i = 0 ; i < m; i++) {
        int op = rand() % 5 + 1;
        int num = rand() % 200001 - 100000;
        generateFile << op << " ";
        if (op == 1 || op == 2 || op == 3) {
            generateFile << num;
        }
        generateFile << endl;
    }
    generateFile.close();
}
int main() {
    n = 1000, m = 10000;
    srand((unsigned) time(NULL));
    //��ʼ��input.txt������
    initData();

    ifstream infile("input.txt", ios::in); // ��input.txt�ļ��ж���
    ofstream outfile("outputTest.txt", ios::trunc); // �����outputTest.txt�ļ�

    infile >> m >> n;
    clock_t startTime, endTime;
    clock_t perStartTime , perEndTime;
    double t1 = 0, t2 = 0, t3 = 0 , t4 = 0, t5 = 0;
    int op1 = 0, op2 = 0, op3 = 0, op4 = 0 , op5 = 0;

    skipList<int> z(100000, m + n, 0.5);
    for (int i = 0 ; i < n; i++) {
        int x; infile >> x;
        z.insert(x);
    }
    startTime = clock();

    for (int i = 0 ; i < m; i++) {
        perStartTime = clock(); // ��ʼ��ʱ
        int op, num; infile >> op;
        if (i == m / 2) {
            z.reBuild();
        }
        if (op == 1) {
            infile >> num;
            if (z.find(num)) {
                outfile << "YES" << endl;
                perEndTime = clock();
            }
            else {
                outfile << "NO" << endl;
            }

            op1++;
            perEndTime = clock();
            t1 += perEndTime - perStartTime;
        }
        else if (op == 2) {
            infile >> num;
            z.insert(num);
            outfile << z.xorNum() << endl;

            op2++;
            perEndTime = clock();
            t2 += perEndTime - perStartTime;
        }
        else if (op == 3) {
            infile >> num;
            z.erase(num);
            outfile << z.xorNum() << endl;
            op3++;
            perEndTime = clock();
            t3 += perEndTime - perStartTime;
        }
        else if (op == 4) {
            outfile << z.eraseMinElement() << endl;
            op4 ++;
            perEndTime = clock();
            t4 += perEndTime - perStartTime;
        }
        else {
            outfile << z.eraseMaxElement() << endl;
            op5++;
            perEndTime = clock();
            t5 += perEndTime - perStartTime;
        }
    }


    endTime = clock();
    double sumTime = endTime - startTime;

    cout << "(���Ҳ���)ִ��ʱ��Ϊ: "<< t1 / CLOCKS_PER_SEC * 1000<< "ms; "
    << "ִ�д���Ϊ" << op1 <<"; ƽ��ִ��ʱ��Ϊ" << t1 / op1 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(����Ԫ��+������)����ִ��ʱ��Ϊ: "<< t2 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "ִ�д���Ϊ" << op2 <<"; ƽ��ִ��ʱ��Ϊ" << t2 / op2 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(ɾ��Ԫ��+������)����ִ��ʱ��Ϊ: "<< t3 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "ִ�д���Ϊ" << op3 <<"; ƽ��ִ��ʱ��Ϊ" << t3 / op3 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(ɾ����СԪ��)����ִ��ʱ��Ϊ: "<< t4 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "ִ�д���Ϊ" << op4 <<"; ƽ��ִ��ʱ��Ϊ" << t4 / op4 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(ɾ�����Ԫ��)����ִ��ʱ��Ϊ: "<< t5 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "ִ�д���Ϊ" << op5 <<"; ƽ��ִ��ʱ��Ϊ" << t5 / op5 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "��ʼ���ݹ�ģΪ: "<<n<<"; ��ִ��ʱ��Ϊ: " << sumTime/ CLOCKS_PER_SEC * 1000<< "ms; " << "�ܲ�������Ϊ" << m <<"; "
    <<"ʹ�������㷨"
    << "ƽ��ִ��ʱ��Ϊ" << sumTime / m << "ms" << endl;

    infile.close();
    outfile.close();
}
