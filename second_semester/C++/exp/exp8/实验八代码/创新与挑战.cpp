#include"bits/stdc++.h"

class BigInteger {
private:
    std::vector<int> digits; // 存储每一位的数字
    std::vector<int> R;//余数
public:
    // 构造函数
    BigInteger(const std::string& number);//构造函数
    BigInteger() {};//默认构造函数
    BigInteger(const BigInteger &rhs) {//拷贝构造函数
        digits = rhs.digits;
    }
    // 加法运算符重载
    BigInteger operator+(const BigInteger& other) const;
    // 减法运算符重载
    BigInteger operator-(const BigInteger& other) const;
    // 乘法运算符重载
    BigInteger operator*(const BigInteger& other) const;
    // 除法运算符重载
    BigInteger operator/(const BigInteger& other) const;
    // 重载比较运算符
    bool operator<(const BigInteger& other) const;
    // 输出函数
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num);
};

bool cmp(std::vector<int>&A, std::vector<int>&B) // A > B为true
{
    if(A.size()!=B.size())
    {
        return A.size()>B.size();
    }
    else
    {
        for(int i=A.size()-1;i>=0;i--)
        {
            if(A[i]!=B[i])return A[i]>B[i];
        }
        return true;
    }
}

std::vector<int> add(std::vector<int>&A, std::vector<int>&B)
{
    std::vector<int> C;
    int  t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(1);
    return C;
}

std::vector<int> subtract(std::vector<int>&A, std::vector<int>&B)
{
    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

std::vector<int> multi(std::vector<int>&A, std::vector<int>&B)
{
    std::vector<int> C(A.size() + B.size() + 7, 0); // 初始化为 0，C的size可以大一点

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    int t = 0;
    for (int i = 0; i < C.size(); i++) { // i = C.size() - 1时 t 一定小于 10
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 必须要去前导 0，因为最高位很可能是 0
    return C;
}

//除法
std::pair<std::vector<int>, std::vector<int>> divide(std::vector<int>&A, std::vector<int>&B)
{
    std:: vector<int> C, R;
    int n = A.size(), m = B.size(), d = n - m;
    C.resize(d + 1, 0);
    // 枚举补 0 的个数
    for (int len = d; len >= 0; len--) {
        std::vector<int> Bp(len, 0);
        for (int i = 0; i < m; i++) Bp.push_back(B[i]);

        // A >= Bp
        while (cmp(A, Bp)) {
            C[len] += 1;
            A = subtract(A, Bp);
        }
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    R = A;
    return make_pair(C, R);
}

// 构造函数实现
BigInteger::BigInteger(const std::string& number) {
    for (int i = number.size() - 1; i >= 0; --i) {
        digits.push_back(number[i] - '0'); // 将每一位数字存储到数组中, 从低位到高位存储
    }
}

// 加法运算符重载实现
BigInteger BigInteger::operator+(const BigInteger& other) const {
    std::vector<int> A = digits, B = other.digits;
    std::vector<int> C;
    C = add(A, B);
    BigInteger result;
    result.digits = C;
    return result;
}

// 减法运算符重载实现
BigInteger BigInteger::operator-(const BigInteger& other) const {
    std::vector<int> A = digits, B = other.digits;
    std::vector<int> C;
    if (!cmp(A, B)) {
        C = subtract(B, A);
    } else {
        C = subtract(A, B);
    }
    BigInteger result;
    result.digits = C;
    return result;
}

// 乘法运算符重载实现
BigInteger BigInteger::operator*(const BigInteger& other) const {
    std::vector<int> A = digits, B = other.digits;
    std::vector<int> C;
    C = multi(A, B);
    BigInteger result;
    result.digits = C;
    return result;
}

// 除法运算符重载实现
BigInteger BigInteger::operator/(const BigInteger& other) const {
    std::vector<int> A = digits, B = other.digits;
    std::vector<int> C, R;
    auto t  = divide(A, B);
    C = t.first;
    R = t.second;
    BigInteger result;
    result.digits = C;
    result.R = R;
    return result;
}

// 输出函数实现
std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
    for (int i = num.digits.size() - 1; i >= 0; --i) {
        os << num.digits[i];
    }
    if (!num.R.empty()) {
        os << ".";
        for (int i = num.R.size() - 1; i >= 0; --i) {
            os << num.R[i];
        }
    }
    return os;
}

bool BigInteger::operator<(const BigInteger &other) const {
    auto A = digits, B = other.digits;
    return cmp(A, B);
}

int main() {
    BigInteger num1("50000000000000000000000000000000000000000000000000000000");
    BigInteger num2("2000000000000000000000000000000000000000000000000000");

    BigInteger sum = num1 + num2;
    std::cout << "Sum: " << sum << std::endl;

    BigInteger diff = num1 - num2;
    if (!(num1 < num2)) {
        std::cout << "Difference: -" << diff << std::endl;
    } else {
        std::cout << "Difference: " << diff << std::endl;
    }

    BigInteger product = num1 * num2;
    std::cout << "Product: " << product << std::endl;
    BigInteger quotient = num1 / num2;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}

