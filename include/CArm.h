/**
 * GameJam 2009 - GamePlay
 *
 * The Arm class file.
 */
 
 #ifndef _CARM_H_
 #define _CARM_H_
 
 #define DEFAULT_X		0
 #define DEFAULT_Y		0
 
 #include "CMap.h"
 #include "AnimSprite.h"
 
 class CArm
 {
 private:
	int x, y;
	
	AnimSprite *sprite;
	
 public:
	CArm();
	
	// Setters
	void setX(int px);
	void setY(int py);
	
	// Getters
	int getX();
	int getY();
	
	void armAction(CMap &map);
	
	void show(BITMAP *buffer);
 };
 
 
 
 #endif
 