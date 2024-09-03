#include <iostream>
using namespace std;

class CPU {
private:
    // 时钟频率，最大不会超过3000MHz
    unsigned int clockRate : 12; // 12位可以表示的最大数为2^12-1=4095，所以足够表示3000MHz
    // 字长，可以是32位或64位
    unsigned int wordLength : 1; // 1位用于表示字长，0表示32位，1表示64位
    // 核数，可以是单核、双核或四核
    unsigned int cores : 2; // 2位用于表示核数，00表示单核，01表示双核，11表示四核
    // 是否支持超线程
    bool hyperThreading : 1; // 1位表示是否支持超线程，1表示支持，0表示不支持

public:
    // 构造函数
    CPU(unsigned int clock, unsigned int word, unsigned int core, bool hyper) {
        setClockRate(clock);
        setWordLength(word);
        setCores(core);
        setHyperThreading(hyper);
    }

    // 设置时钟频率
    void setClockRate(unsigned int clock) {
        if (clock > 3000) {
            cout << "Error: Clock rate cannot exceed 3000MHz. Setting to maximum value." << endl;
            clockRate = 3000;
        } else {
            clockRate = clock;
        }
    }

    // 设置字长
    void setWordLength(unsigned int word) {
        if (word == 32 || word == 64) {
            wordLength = (word == 64) ? 1 : 0;
        } else {
            cout << "Error: Word length can only be 32 or 64 bits." << endl;
        }
    }

    // 设置核数
    void setCores(unsigned int core) {
        if (core == 1 || core == 2 || core == 4) {
            cores = core - 1; // 1表示单核，2表示双核，4表示四核
        } else {
            cout << "Error: Invalid number of cores." << endl;
        }
    }

    // 设置是否支持超线程
    void setHyperThreading(bool hyper) {
        hyperThreading = hyper;
    }
};

int main() {
    cout << "Size of CPU object: " << sizeof(CPU) << " bytes" << endl;
    return 0;
}
