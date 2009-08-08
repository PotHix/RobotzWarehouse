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

void CMap::setWidth(int w){
   width = w;
}

void CMap::setHeight(int h){
   height = h;
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

void CMap::getMap(){
   return items;
}

void CMap::getWidth(int w){
   return width;
}

void CMap::getHeight(int h){
   return height;
}
