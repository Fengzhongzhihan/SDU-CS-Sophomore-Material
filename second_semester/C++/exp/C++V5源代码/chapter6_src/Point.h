#pragma once

class Point {	//类的定义
public:	//外部接口
    Point(int x , int y );
    Point();
    Point(const Point &p);
    ~Point() ;
    int getX() const { return x; }
    int getY() const { return y; }
    static void showCount();	//静态函数成员
    void move(int newX,int newY);
private:	//私有数据成员
    int x, y;
    static int count;	//静态数据成员
};
