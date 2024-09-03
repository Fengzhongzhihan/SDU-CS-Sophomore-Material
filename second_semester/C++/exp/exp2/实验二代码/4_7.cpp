#include <iostream>
#include <string>

class Student {
private:
    int num;        // 学号
    std::string name;   // 姓名
    char sex;       // 性别
    int age;        // 年龄

public:
    // 构造函数
    Student(int n = 0, const std::string& nm = "", char s = ' ', int a = 0) : 
        num(n), name(nm), sex(s), age(a) {}

    // 成员函数用于设置学生信息
    void setInfo(int n, const std::string& nm, char s, int a) {
        num = n;
        name = nm;
        sex = s;
        age = a;
    }

    // 成员函数用于显示学生信息
    void display() const {
        std::cout << "Num:  " << num << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Sex:  " << sex << std::endl;
        std::cout << "Age:  " << age << std::endl;
    }
};

int main() {
    Student stu;
    stu.setInfo(97001, "Lin Lin", 'F', 19);
    stu.display();
    return 0;
}
