/**
 * GameJam 2009 - GamePlay
 *
 * The main Game Class
 */
 
 #ifndef _CGAME_H_
 #define _CGAME_H_
 
 #include <allegro.h>
 
 #include "CApp.h"
 #include "CMap.h"
 #include "CArm.h"
 #include "CTimer.h"
 
 #define FADE_TIME					5
 
 // This enum stores all the stats of the machine
 enum GameStatus
 {
	GAME_OPEN,
	GAME_MENU,
	GAME_GAME,
	GAME_OVER
 };
 
 class CGame
 {
 private:
	
	// Our game status
	GameStatus game_status;
	
	// App Manager
	CApp *App;
	
	// Boolean
	bool flow;
	
	// Buffer for double buffering
	BITMAP *buffer;	
	
	// Maps test
	CMap *Map;
	
    CArm *Arm;
	
	// Images =D
	BITMAP *bmpOpen;
	BITMAP *bmpBackGame;
	BITMAP *bmpGameOver;
	
	// Timer
	CTimer *timer;
	
 public:
 
	CGame();
	
	// Runs the game
	void run();
	
	// One method for each game state
	void game_open();
	void game_menu();
	void game_game();
	void game_over();
	
	void loadImages();
 
 };
 
 
 #endif

 
