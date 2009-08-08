/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */

#ifndef _CMAP_H_
#define _CMAP_H_

#include <allegro.h>

#define RADIUS          15

#define GET_I			(i*(RADIUS * 1.3)*2) + RADIUS
#define GET_J			(j*(RADIUS * 1.3)*2) + RADIUS

#define MAX_ITEMS		2

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
	  
	  bool full;

   public:
      CMap();

      void initMatrix();

      // Setters
      void setWidth(int w);
      void setHeight(int h);
	  
	  void setX(int px);
	  void setY(int py);
	  
	  void setFull(bool op);

      // Getters
      int getWidth();
      int getHeight();
	  
	  int getX();
	  int getY();
	  
	  bool getFull();
	  
	  void center();	
	  
      EItem **getMap();

      void show(BITMAP *buffer);
	  
	  void update();
};



#endif

