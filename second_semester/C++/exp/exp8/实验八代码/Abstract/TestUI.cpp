//≤‚ ‘≥Ã–Ú 
#include "Point.h"
#include "Line.h" 
#include "Rectangle.h" 
#include "UI.h"

main(){ 
	UI ui;
	 
	Point p1(1,2),p2(7,8);
	ui.shapeVector.push_back(&p1);
	ui.shapeVector.push_back(&p2);
		
	ui.shapeVector.push_back(new Line(p1,p2));
	
	ui.shapeVector.push_back(new Rectangle(p1,5,6));
	
    ui.show();
}
 
