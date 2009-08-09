/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */

#include "CMap.h"

CMap::CMap(){
	full = false;

   setWidth(4);
   setHeight(4);
   
   setX(0);
   setY(0);
   
   clicked = false;
   
   loadImages();
   
   center();
   initMatrix();
}

void CMap::show(BITMAP *buffer){
		int i = width;
		int j = height;
		rectfill(buffer, x-RADIUS-5, y-RADIUS-5, x+GET_I-3, y+GET_J-10, 0xAAAAAA);
		rectfill(buffer, x-RADIUS-5, y-RADIUS-5, x+GET_I-3, y-10, 0x444444);
		rectfill(buffer, x-RADIUS-5, y-RADIUS-5, x-10, y+GET_J-10, 0x444444);

   for(int i=0; i < width; i++){
      for(int j=0; j< height; j++){
         //circlefill(buffer, x+GET_I, y+GET_J, RADIUS, 0xFF0000);
		 draw_sprite(buffer, elevation, x+GET_I-RADIUS, y+GET_J-RADIUS);
		 
		 if (items[i][j] == EITEM_A) {
			//circlefill(buffer, x + GET_I, y + GET_J, 6, 0xCC00AA);
			draw_sprite(buffer, box2, x + GET_I - 12, y + GET_J - 12);
		 } else if (items[i][j] == EITEM_B) {
			//circlefill(buffer, x + GET_I, y + GET_J, 6, 0xAAFFAA);
			draw_sprite(buffer, box, x + GET_I - 12, y + GET_J - 12);
		 }
		 
      }
   }
   
   if (clicked)
   {
		int i = sel_x;
		int j = sel_y;
		//circle(buffer, x + GET_I, y + GET_J, RADIUS, 0);
		draw_sprite(buffer, box_select, x + GET_I - 12, y + GET_J - 12);
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
		int zz = 0;
		int za = 0;
		
		for (int j = 0; j < height; j++)
		{
			// 
			if (j != 0 && items[i][j] == items[i][j-1] && items[i][j] != EITEM_NULL)
			{
				zz++;
			}
			
			if (i != 0 && items[i][j] == items[i-1][j] && items[i][j] != EITEM_NULL)
			{
				za++;
			}
		
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
		
		if (zz == width-1 || za == height-1)
		{
			increaseMap();
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
	if (items[a][b] == EITEM_NULL || items[c][d] == EITEM_NULL)
	{
		return;
	}
	
	EItem tmp = items[a][b];
	items[a][b] = items[c][d];
	items[c][d] = tmp;
}

void CMap::increaseMap()
{
	width++;
	height++;
	
	center();
	initMatrix();
}

void CMap::loadImages()
{
	elevation = load_bitmap("../media/elevation.bmp", NULL);
	box = load_bitmap("../media/box.bmp", NULL);
	box2 = load_bitmap("../media/box2.bmp", NULL);
	box_select = load_bitmap("../media/box_select.bmp", NULL);
}
