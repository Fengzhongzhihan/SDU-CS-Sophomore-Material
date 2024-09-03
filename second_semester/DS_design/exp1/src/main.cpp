#include "skipList.h"
#include "skipList.cpp"
#include <fstream>
int n , m;
double sum = 0 ;

void initData() {
    ofstream generateFile("input.txt", ios::trunc);
    generateFile << m << " " << n << endl; //输入n, m
    //生成-100000 + 100000内的随机数
    for (int i = 0 ; i < n ; i++) {
        int x = rand() % 200001 - 100000;
        generateFile << x << " ";
    }
    generateFile << endl;
    //生成操作序列
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
    //初始化input.txt的数据
    initData();

    ifstream infile("input.txt", ios::in); // 从input.txt文件中读入
    ofstream outfile("outputTest.txt", ios::trunc); // 输出到outputTest.txt文件

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
        perStartTime = clock(); // 开始计时
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

    cout << "(查找操作)执行时间为: "<< t1 / CLOCKS_PER_SEC * 1000<< "ms; "
    << "执行次数为" << op1 <<"; 平均执行时间为" << t1 / op1 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(插入元素+求异或和)操作执行时间为: "<< t2 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "执行次数为" << op2 <<"; 平均执行时间为" << t2 / op2 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(删除元素+求异或和)操作执行时间为: "<< t3 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "执行次数为" << op3 <<"; 平均执行时间为" << t3 / op3 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(删除最小元素)操作执行时间为: "<< t4 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "执行次数为" << op4 <<"; 平均执行时间为" << t4 / op4 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "(删除最大元素)操作执行时间为: "<< t5 / CLOCKS_PER_SEC * 1000<< "ms; "
         << "执行次数为" << op5 <<"; 平均执行时间为" << t5 / op5 / CLOCKS_PER_SEC * 1000 <<"ms"<<endl;
    cout << "初始数据规模为: "<<n<<"; 总执行时间为: " << sumTime/ CLOCKS_PER_SEC * 1000<< "ms; " << "总操作次数为" << m <<"; "
    <<"使用整理算法"
    << "平均执行时间为" << sumTime / m << "ms" << endl;

    infile.close();
    outfile.close();
}
