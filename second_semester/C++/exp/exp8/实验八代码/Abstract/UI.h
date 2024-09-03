#ifndef _UI_H
#define _UI_H

#include<vector>
#include"Shape.h" 

class UI{
  public:
	vector<Shape*> shapeVector;   //建立抽象类的对象动态数组，对应所有兼容形状，统一处理。
	void show(){
		for(int i=0;i<shapeVector.size();i++)
		 	shapeVector[i]->show();    //多态 
	}
};

#endif
