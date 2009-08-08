/**
 * GameJam 2009 - GamePlay
 *
 * The main Game Class
 */
 
#include "CGame.h"

CGame::CGame()
{
	// Initializes the game here...
	
	App = new CApp();
	App->Init(800, 600, "GameJam 2009 - GamePlay");
	
	readkey();
}

void CGame::run()
{
	// WOW, let's see if it works! :)
}