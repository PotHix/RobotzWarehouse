/**
 * GameJam 2009 - GamePlay
 *
 * The map class file.
 */
 
 #ifndef _CMAP_H_
 #define _CMAP_H_
 
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
	
	void setWidth(int w);
	void setHeight(int h);
	
	void initMatrix();
 }
 
 
 
 #endif
 