/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */

#include "CMap.h"

CMap::CMap(){
   setWidth(2);
   setHeight(2);
   initMatrix();
}

void CMap::show(BITMAP *buffer){
   for(int i=0; i < width; i++){
      for(int j=0; j< height; j++){
         circlefill(buffer, (i*RADIUS*2)+ (i == 0 ? RADIUS : RADIUS*2), (j*RADIUS*2)+ (j == 0 ? RADIUS : RADIUS*2), RADIUS, 0xFF0000);
      }
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

EItem** CMap::getMap(){
   return items;
}

//Setters
void CMap::setWidth(int w){
   width = w;
}

void CMap::setHeight(int h){
   height = h;
}

void CMap::setX(int px){
   x = px;
}

void CMap::setY(int py){
   y = py;
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
