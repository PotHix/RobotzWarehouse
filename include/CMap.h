/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */

#ifndef _CMAP_H_
#define _CMAP_H_

#include <allegro.h>

#define RADIUS          15

enum EItem
{
   EITEM_NULL,
   EITEM_A,
   EITEM_B
};

class CMap
{
   private:
      EItem **items;

      int width, height;
	  
	  int x, y;

   public:
      CMap();

      void initMatrix();

      // Setters
      void setWidth(int w);
      void setHeight(int h);
	  
	  void setX(int px);
	  void setY(int py);

      // Getters
      int getWidth();
      int getHeight();
	  
	  int getX();
	  int getY();
	  
	  void center();	
	  
      EItem **getMap();

      void show(BITMAP *buffer);
};



#endif

