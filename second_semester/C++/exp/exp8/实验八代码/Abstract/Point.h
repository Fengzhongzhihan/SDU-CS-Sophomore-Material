#ifndef _POINT_H
#define _POINT_H

#include"Shape.h" 
#include<iostream>
using namespace std;

//Point¿‡, ºÃ≥–
class Point:public Shape{    
	public:
		Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
	virtual void show(){
    	cout<<"point:("<<x<<","<<y<<")"<<endl;
	} 
	int getX() { return x; }
	int getY() { return y; }
private:
	int x, y;
};

#endif //_POINT_H
