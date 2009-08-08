/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */
 
 #ifndef _CMAP_H_
 #define _CMAP_H_
 
 #include <allegro.h>
 
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
	
 public:
	CMap();
	
	void initMatrix();
	
	// Setters
	void setWidth(int w);
	void setHeight(int h);
	
	// Getters
	int getWidth();
	int getHeight();
	EItem **getMap();
	
	void show(BITMAP *buffer);
 };
 
 
 
 #endif
 