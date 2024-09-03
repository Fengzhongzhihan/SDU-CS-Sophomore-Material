#ifndef _POINT_H
#define _POINT_H

#include <iostream>
using namespace std;

class Point {	//Point¿‡
public:
	 
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
    void show(){
    	cout<<"point:("<<x<<","<<y<<")"<<endl;
	} 
	int getX() { return x; }
	int getY() { return y; }
private:
	int x, y;
};
#endif //_POINT_H
