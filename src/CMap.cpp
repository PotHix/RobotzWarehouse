/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */

#include "CMap.h"

CMap::CMap(){
	full = false;

   setWidth(3);
   setHeight(3);
   
   setX(0);
   setY(0);
   
   clicked = false;
   
   center();
   initMatrix();
}

void CMap::show(BITMAP *buffer){
   for(int i=0; i < width; i++){
      for(int j=0; j< height; j++){
         circlefill(buffer, x+GET_I, y+GET_J, RADIUS, 0xFF0000);
		 
		 if (items[i][j] == EITEM_A) {
			circlefill(buffer, x + GET_I, y + GET_J, 6, 0xCC00AA);
		 } else if (items[i][j] == EITEM_B) {
			circlefill(buffer, x + GET_I, y + GET_J, 6, 0xAAFFAA);
		 }
		 
      }
   }
   
   if (clicked)
   {
		int i = sel_x;
		int j = sel_y;
		circle(buffer, x + GET_I, y + GET_J, RADIUS, 0);
   }
   
}

void CMap::initMatrix(){
   items = new EItem*[width];
   for(int i=0; i < width; i++){
      items[i] = new EItem[height];
      for(int j=0; j < height; j++){
         items[i][j] = EITEM_NULL;
      }
   }
}

void CMap::center(){
   x = (800 - (width * RADIUS * 2 * 1.3)) / 2;
   y = (600 - (height * RADIUS * 2 * 1.3)) / 2;
}

EItem** CMap::getMap(){
   return items;
}

//Setters
void CMap::setWidth(int w){
   width = w; }

void CMap::setHeight(int h){
   height = h;
}

void CMap::setX(int px){
   x = px;
}

void CMap::setY(int py){
   y = py;
}

void CMap::setFull(bool op) {
	full = op;
}

//Getters
int CMap::getWidth(){
   return width;
}

int CMap::getHeight(){
   return height;
}

int CMap::getX(){
   return x;
}

int CMap::getY(){
   return y;
}

bool CMap::getFull(){
	return full;
}

void CMap::update() {
	int empty = 0;
	
	int clicked_x = -1, clicked_y = -1;
	bool c = false;
	
	if (Input.isMouseLeftClick())
	{	 		
		clicked_x = mouse_x;
		clicked_y = mouse_y;
		c = true;
	}
	else
	{
		c = false;
	}
	
	int a = 0;
	
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			// Clicked?
			if (isClicked(i, j, clicked_x, clicked_y) && c == true)
			{
				if (!clicked)
				{
					clicked = true;
					sel_x = i;
					sel_y = j;
				}
				else
				{
					if (clicked_x != -1 && clicked_y != -1)
					{
						swap(sel_x, sel_y, i, j);
						clicked_x = -1;
						clicked_y = -1;
					}
					
					clicked = false;
				}
				a++;
			}
		
			// Is it empty?
			if (items[i][j] != EITEM_NULL)
			{
				empty++;
			}
		}
	}
	
	if (a == 0 && clicked == true && c == true)
	{
		clicked == false;
	}
	
	if (empty == width * height)
	{
		setFull(true);
	}
}

bool CMap::isClicked(int i, int j, int cx, int cy)
{
	int px = x + GET_I;
	int py = y + GET_J;
	
	if ((((px - cx) * (px - cx)) + ((py - cy) * (py - cy))) < ((2 * RADIUS) * (2 * RADIUS)))
	{
		// Clicked... =D
		return true;
	}
	
	return false;
}

void CMap::swap(int a, int b, int c, int d)
{
	//allegro_message("First: %d,%d - Second: %d,%d", a, b, c, d);
	EItem tmp = items[a][b];
	items[a][b] = items[c][d];
	items[c][d] = tmp;
}
