#include "vMachine.h"
int main() {
    //创建虚拟机对象，内存可存1024条指令
    vMachine vm("青芯CU1", "青芯ALU1", 1024, "输入设备1", "输出设备1");
//    vm.run("input1.txt");
    vm.run("input2.txt");
    return 0;
}
