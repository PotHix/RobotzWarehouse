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
        Arm = new CArm();
	
	flow = true;
	
	// Load all bitmaps of the game =D
	loadImages();
	
	Arm->getMap(&Map);
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
	clear_to_color(screen, 0xFFFFFF);
	App->fadeInToColor(bmpOpen, FADE_TIME, 0xFFFFFF);
	rest(3000);
	App->fadeOutToColor(FADE_TIME, 0xFFFFFF);
	game_status = GAME_GAME;
	
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

	if (key[KEY_SPACE])
	{
	   Arm->armAction();
	   rest(100);
	}
	
	if (key[KEY_A])
	{
		Map.increaseMap();
	}
	
	Map.show(App->GetBuffer());
	Map.update();
	
	Arm->show(App->GetBuffer());
	Arm->update();
	
	App->ShowMouse();
}

void CGame::loadImages()
{
	bmpOpen = load_bitmap("../media/open.bmp", NULL);
}

