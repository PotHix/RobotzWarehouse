/**
 * GameJam 2009 - GamePlay
 *
 * The robot arm class file.
 */

#include "CArm.h"

CArm::CArm(){
   setX(DEFAULT_X);
   setY(DEFAULT_Y);
   sprite = new AnimSprite();
}

void CArm::armAction(CMap &map){
	if (map.getFull() == false)
	{
	   int rx, ry;
	   EItem** b;
	   do{
		  rx = rand() % map.getWidth();
		  ry = rand() % map.getHeight();
		  b = map.getMap();
	   }while(b[rx][ry] != EITEM_NULL);
	   
	   int type = (rand() % MAX_ITEMS) + 1;
	   b[rx][ry] = (EItem)type;
	}
}

//Setters
void CArm::setX(int px){
   x = px;
}

void CArm::setY(int py){
   y = py;
}

//Getters
int CArm::getX(){
   return x;
}

int CArm::getY(){
   return y;
}
