#include <iostream>
using namespace std;

class SimpleCircle
{
public:
    SimpleCircle();
    SimpleCircle(int);
    SimpleCircle(const SimpleCircle &);
    ~SimpleCircle() {}
    SimpleCircle& operator = (const SimpleCircle & rhs);
    void setRadius(int);
    int getRadius() const;

private:
    int *itsRadius;
};

SimpleCircle::SimpleCircle()
{
    itsRadius = new int(5);
}

SimpleCircle::SimpleCircle(int radius)
{
    itsRadius = new int(radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle & rhs)
{
    int val = rhs.getRadius();
    itsRadius = new int(val);
}
//使用=运算符重载函数实现深拷贝
SimpleCircle & SimpleCircle::operator = (const SimpleCircle & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete itsRadius;
    itsRadius = new int(rhs.getRadius());
    return *this;
}

int SimpleCircle::getRadius() const
{
    return *itsRadius;
}

int main()
{
    // SimpleCircle CircleOne, CircleTwo(9);
    // cout << "CircleOne: " << CircleOne.getRadius() << endl;
    // cout << "CircleTwo: " << CircleTwo.getRadius() << endl;
    SimpleCircle c1, c2;
    c1 = c2 = 3;
    cout << c1.getRadius() << " " << c2.getRadius() << endl;
    return 0;
}