#include <iostream>
using namespace std;

// CPU类声明
class CPU {
private:
    unsigned int clockRate; // 时钟频率
    unsigned int wordLength; // 字长
    unsigned int cores; // 核数
    bool hyperThreading; // 是否支持超线程

public:
    // 构造函数
    CPU(unsigned int clock = 0, unsigned int word = 0, unsigned int core = 0, bool hyper = false);

    // 设置时钟频率
    void setClockRate(unsigned int clock);

    // 设置字长
    void setWordLength(unsigned int word);

    // 设置核数
    void setCores(unsigned int core);

    // 设置是否支持超线程
    void setHyperThreading(bool hyper);

    // 显示CPU信息
    void display() const;
};

// Computer类声明
class Computer {
private:
    string brand; // 品牌
    CPU cpu; // CPU对象

public:
    // 构造函数
    Computer(const string& b, const CPU& c);

    // 显示电脑信息
    void display() const;
};

// CPU类成员函数定义
CPU::CPU(unsigned int clock, unsigned int word, unsigned int core, bool hyper)
    : clockRate(clock), wordLength(word), cores(core), hyperThreading(hyper) {}

void CPU::setClockRate(unsigned int clock) {
    clockRate = clock;
}

void CPU::setWordLength(unsigned int word) {
    wordLength = word;
}

void CPU::setCores(unsigned int core) {
    cores = core;
}

void CPU::setHyperThreading(bool hyper) {
    hyperThreading = hyper;
}

void CPU::display() const {
    cout << "CPU Information:" << endl;
    cout << "Clock Rate: " << clockRate << " MHz" << endl;
    cout << "Word Length: " << wordLength << " bit" << endl;
    cout << "Cores: " << cores << endl;
    cout << "Hyper-Threading: " << (hyperThreading ? "Supported" : "Not Supported") << endl;
}

// Computer类成员函数定义
Computer::Computer(const string& b, const CPU& c)
    : brand(b), cpu(c) {}

void Computer::display() const {
    cout << "Computer Brand: " << brand << endl;
    cpu.display();
}

int main() {
    // 创建CPU对象
    CPU cpu1(3000, 64, 4, true);
    // 创建Computer对象
    Computer comp1("Legion", cpu1);
    // 显示电脑信息
    comp1.display();
    return 0;
}
