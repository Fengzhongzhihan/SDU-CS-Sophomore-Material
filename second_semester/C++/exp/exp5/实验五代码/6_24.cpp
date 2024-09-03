#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    string streetAddress;
    string city;
    string postalCode;

public:
    // 构造函数
    Employee(string name, string streetAddress, string city, string postalCode) : 
        name(name), streetAddress(streetAddress), city(city), postalCode(postalCode) {}

    // 函数用于修改姓名
    void change_name(string new_name) {
        name = new_name;
    }

    // 函数用于显示雇员信息
    void display() {
        cout << "姓名：" << name << endl;
        cout << "街道地址：" << streetAddress << endl;
        cout << "城市：" << city << endl;
        cout << "邮编：" << postalCode << endl;
    }
};

int main() {
    const int NUM_EMPLOYEES = 2;
    Employee employees[NUM_EMPLOYEES] = {
        Employee("约翰·多", "123主街", "任意城镇", "12345"),
        Employee("简·史密斯", "456橡树街", "他镇", "54321"),
    };

    // 显示每个雇员的信息
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "雇员 #" << i + 1 << "：" << endl;
        employees[i].display();
        cout << endl;
    }

    // 修改雇员的姓名
    employees[0].change_name("约翰·史密斯");
    cout << "修改后的姓名：" << endl;
    employees[0].display();
    return 0;
}
