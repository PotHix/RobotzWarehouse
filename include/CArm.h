/**
 * GameJam 2009 - GamePlay
 *
 * The Arm class file.
 */
 
 #ifndef _CARM_H_
 #define _CARM_H_
 
 #define DEFAULT_X		800
 #define DEFAULT_Y		0
 
 #include <allegro.h>
 
 #include "CMap.h"
 #include "AnimSprite.h"
 
 enum EArmState
 {
	EAS_NULL,
	EAS_MOVE_GO,
	EAS_MOVE_BA,
	EAS_SET
 };
 
 class CArm
 {
 private:
	int x, y;
	int dx, dy;
	int rx, ry;
	
	int vel;
	
	int curr;
	
	CMap *map;
	
	int type;
	
	BITMAP *sprite[2];
	 
	EArmState state;
	
 public:
	CArm();
	
	void getMap(CMap *map);
	
	// Setters
	void setX(int px);
	void setY(int py);
	
	// Getters
	int getX();
	int getY();
	
	void armAction();
	
	void show(BITMAP *buffer);
	void update();
 };
 
 
 
 #endif
 
