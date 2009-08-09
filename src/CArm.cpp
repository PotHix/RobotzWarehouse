/**
 * GameJam 2009 - GamePlay
 *
 * The robot arm class file.
 */

#include "CArm.h"

CArm::CArm(){
   setX(DEFAULT_X);
   setY(DEFAULT_Y);
   
   state = EAS_NULL;
   
   // Loading Arm sprite
   sprite[0] = load_bitmap("../media/arm.bmp", NULL);
   sprite[1] = load_bitmap("../media/arm2.bmp", NULL);
   
   curr = 0;
}

void CArm::getMap(CMap *map)
{
	this->map = map;
}

void CArm::armAction(){
	if (state == EAS_NULL)
	{
		state = EAS_MOVE_GO;
		
		if (map->getFull() == false)
		{
		   EItem** b;
		   do{
			  rx = rand() % map->getWidth();
			  ry = rand() % map->getHeight();
			  b = map->getMap();
		   }while(b[rx][ry] != EITEM_NULL);
		   
		   int i = rx;
		   int j = ry;
		   
		   dx = (map->getX() + GET_I) - 50;
		   dy = (map->getY() + GET_J) - 20;
		   
		   type = (rand() % MAX_ITEMS) + 1;
		   curr = 0;
		}
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

void CArm::show(BITMAP *buffer)
{
	draw_sprite(buffer, sprite[curr], x, y);
}

void CArm::update()
{
	switch(state)
	{
		case EAS_NULL:
		{		
			armAction();
			break;
		}
		
		case EAS_MOVE_GO:
		{
			if (x > dx)
			{
				x--;
			}
			
			if (y < dy)
			{
				y++;
			}
			
			if (x == dx && y == dy)
			{
				state = EAS_SET;
			}
		
			break;
		}
		
		case EAS_MOVE_BA:
		{
			if (x < DEFAULT_X)
			{
				x++;
			}
			
			if (y > DEFAULT_Y)
			{
				y--;
			}
			
			if (x == DEFAULT_X && y == DEFAULT_Y)
			{
				state = EAS_NULL;
			}
			
			break;
		}

		case EAS_SET:
		{
			EItem** b= map->getMap();
			b[rx][ry] = (EItem)type;
			state = EAS_MOVE_BA;
			curr = 1;
			break;
		}
	}
}
