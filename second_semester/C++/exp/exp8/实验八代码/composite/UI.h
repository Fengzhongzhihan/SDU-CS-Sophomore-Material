//类的组合设计例子 
#ifndef _UI_H
#define _UI_H

#include <vector>
#include "Point.h"
#include "Line.h" 
#include "Rectangle.h" 

//类的组合
class UI{   //用户界面，组合类 
	public:
	vector<Point> pointVector; //点对象 
	vector<Line> lineVector;  //线型对象
	vector<Rectangle> rectVector;  //矩型对象
	
	void show(){
		for(int i=0;i<pointVector.size();i++)  //lineVector显示 
			pointVector[i].show(); 
			
		for(int i=0;i<lineVector.size();i++)  //lineVector显示 
			lineVector[i].show();  
			
		for(int i=0;i<rectVector.size();i++)  //lineVector显示 
			rectVector[i].show(); 
	}
};
#endif //_UI_H
