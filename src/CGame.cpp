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
	
	this->buffer = create_bitmap(800, 600);
	
	App->SetBuffer(buffer);

	game_status = GAME_GAME;
	
	// Maps test
	
	flow = true;
}

void CGame::run()
{
	// Ok... Main Looping
	
	while (flow)
	{
		App->ClearBuffer(0xFFFFFF);
	
		switch(game_status)
		{
			case GAME_OPEN:
			{
				game_open();
				break;
			}
			case GAME_MENU:
			{
				game_menu();
				break;
			}
			case GAME_GAME:
			{
				game_game();
				break;
			}
		}
		
		App->Refresh();
	}
	
	exit(-1);
	
}

void CGame::game_open()
{
	// Nada
}

void CGame::game_menu()
{
	// Nada
}

void CGame::game_game()
{
	if (key[KEY_ESC])
	{
		flow = false;
	}
	
	Map.show(App->GetBuffer());
}

