//������������� 
#ifndef _UI_H
#define _UI_H

#include <vector>
#include "Point.h"
#include "Line.h" 
#include "Rectangle.h" 

//������
class UI{   //�û����棬����� 
	public:
	vector<Point> pointVector; //����� 
	vector<Line> lineVector;  //���Ͷ���
	vector<Rectangle> rectVector;  //���Ͷ���
	
	void show(){
		for(int i=0;i<pointVector.size();i++)  //lineVector��ʾ 
			pointVector[i].show(); 
			
		for(int i=0;i<lineVector.size();i++)  //lineVector��ʾ 
			lineVector[i].show();  
			
		for(int i=0;i<rectVector.size();i++)  //lineVector��ʾ 
			rectVector[i].show(); 
	}
};
#endif //_UI_H
