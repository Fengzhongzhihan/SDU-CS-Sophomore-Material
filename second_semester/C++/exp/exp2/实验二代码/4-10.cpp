#include <iostream>
#include <string>

// 日期类
class Date {
private:
    int year;
    int month;
    int day;

public:
    // 构造函数
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    // 复制构造函数
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

    // 获取年份
    int getYear() const {
        return year;
    }

    // 设置年份
    void setYear(int y) {
        year = y;
    }

    // 获取月份
    int getMonth() const {
        return month;
    }

    // 设置月份
    void setMonth(int m) {
        month = m;
    }

    // 获取日期
    int getDay() const {
        return day;
    }

    // 设置日期
    void setDay(int d) {
        day = d;
    }

    // 显示日期信息
    void display() const {
        std::cout << year << "-" << month << "-" << day;
    }
};

// 人员类
class People {
private:
    int number;
    char sex;
    Date birthday;
    std::string id;

public:
    // 构造函数
    People(int num = 0, char s = '\0', const Date& bd = Date(), const std::string& i = "") :
        number(num), sex(s), birthday(bd), id(i) {}

    // 拷贝构造函数
    People(const People& other) : number(other.number), sex(other.sex), birthday(other.birthday), id(other.id) {}

    // 析构函数
    ~People() {}

    // 获取编号
    int getNumber() const {
        return number;
    }

    // 设置编号
    void setNumber(int num) {
        number = num;
    }

    // 获取性别
    char getSex() const {
        return sex;
    }

    // 设置性别
    void setSex(char s = '男') {
        sex = s;
    }

    // 获取出生日期
    Date getBirthday() const {
        return birthday;
    }

    // 设置出生日期
    void setBirthday(const Date& bd) {
        birthday = bd;
    }

    // 获取身份证号
    std::string getId() const {
        return id;
    }

    // 设置身份证号
    void setId(const std::string& i) {
        id = i;
    }

    // 内联成员函数：显示人员信息
    inline void displayInfo() const {
        std::cout << "Number: " << number << std::endl;
        std::cout << "Sex: " << sex << std::endl;
        std::cout << "Birthday: ";
        birthday.display();
        std::cout << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

int main() {
    Date dob(1990, 5, 25); // 出生日期
    People person(1, 'M', dob, "1234567890"); // 创建人员对象

    // 显示人员信息
    person.displayInfo();

    return 0;
}
