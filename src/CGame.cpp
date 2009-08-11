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
	
	Map = new CMap();
	
	this->buffer = create_bitmap(800, 600);
	
	App->SetBuffer(buffer);

	game_status = GAME_OPEN;
	
	// Maps test
        Arm = new CArm();
	
	flow = true;
	
	// Load all bitmaps of the game =D
	loadMedia();
	
	Arm->getMap(Map);
	
	// Initializing the timer
	timer = new CTimer(16);
	
	op = 0;
}

void CGame::run()
{
	// Ok... Main Looping
	
	timer->Start();
	
	while (flow)
	{
		if (timer->getCount() > 0)
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
				case GAME_OVER:
				{
					game_over();
					break;
				}
				default:
				{
					flow = false;
					break;
				}
			}
			
			App->Refresh();
			timer->desc();
		}
	}
	
	exit(-1);
	
}

void CGame::game_open()
{
	clear_to_color(screen, 0xFFFFFF);
	App->fadeInToColor(bmpOpen, FADE_TIME, 0xFFFFFF);
	rest(3000);
	App->fadeOutToColor(FADE_TIME, 0xFFFFFF);
	game_status = GAME_MENU;
	timer->Reset();
	play_midi(midi_menu, 1);
	
}

void CGame::game_menu()
{
	blit(bmpBackMenu, App->GetBuffer(), 0, 0, 0, 0, 800, 600);
	
	if (key[KEY_ESC] || (mouse_b & 1 && op == 1 && mouse_y < 445))
	{
		game_status = GAME_FAIL;
	}
	
	if (op == 0)
	{
		ax = 390;
		ay = 303;
	}
	else if (op == 1)
	{
		ax = 390;
		ay = 388;
	}
	
	if (mouse_y < 375)
	{
		op = 0;
	}
	else
	{
		op = 1;
	}
	
	if (mouse_b & 1 && mouse_y > 300)
	{
		if (op == 0)
		{
			App->fadeOutToColor(FADE_TIME, 0xFFFFFF);
			App->ClearBuffer(0x000000);
			game_status = GAME_GAME;
			timer->Reset();
			play_midi(midi_game, 1);
		}
	}
	
	draw_sprite(App->GetBuffer(), arrow, ax, ay);
	
	App->ShowMouse();
}

void CGame::game_game()
{
	blit(bmpBackGame, App->GetBuffer(), 0, 0, 0, 0, 800, 600);

	if (key[KEY_ESC])
	{
		flow = false;
	}
	
	Map->show(App->GetBuffer());
	Map->update();
	
	if (Map->getFull())
	{
		game_status = GAME_OVER;
	}
	
	Arm->show(App->GetBuffer());
	Arm->update();
	
	App->ShowMouse();
}

void CGame::game_over()
{
	App->fadeOutToColor(FADE_TIME, 0xFFFFFF);
	App->fadeInToColor(bmpGameOver, FADE_TIME, 0xFFFFFF);
	rest(2000);
	exit(-1);
}

void CGame::loadMedia()
{
	bmpOpen = load_bitmap("../media/open.bmp", NULL);
	bmpBackGame = load_bitmap("../media/back_game.bmp", NULL);
	bmpBackMenu = load_bitmap("../media/back_menu.bmp", NULL);
	bmpGameOver = load_bitmap("../media/game_over.bmp", NULL);
	
	arrow = load_bitmap("../media/arrow.bmp", NULL);
	
	midi_game = load_midi("../media/unbal.mid");
	midi_menu = load_midi("../media/harestwav.mid");
}

