/**
 * GameJam 2009 - GamePlay
 *
 * The main Input Class
 */
 
 #ifndef _CINPUT_H_
 #define _CINPUT_H_
 
 #include <allegro.h>
 
 class CInput
 {
 private:
	// Mouse flag
	bool fMouseLeft;
	bool fMouseRight;
 
 public:
	CInput();
	
	bool isMouseLeftClick();
	bool isMouseRightClick();
	
	void update();
 };
 
 #endif