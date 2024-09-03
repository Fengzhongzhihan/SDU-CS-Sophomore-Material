#ifndef _SHAPE_H
#define _SHAPE_H

class Shape    //抽象类 
{
 public:
 	virtual void show()=0;  //纯虚函数 
	 
 	virtual ~Shape(){ };   //虚析构函数 

};

#endif 
